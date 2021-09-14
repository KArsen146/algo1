#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int n = 2;

struct list_2nd {
    string key;
    list_2nd *next;
    list_2nd *prev;

    list_2nd() {
        next = nullptr;
        prev = nullptr;
    };
};

struct list_1st {
    string key;
    list_1st *next;
    list_1st *prev;
    list_2nd **y;
    int count;

    list_1st() {
        next = nullptr;
        prev = nullptr;
        y = nullptr;

    };
};

vector<list_1st *> x(n + 1, nullptr);

int hash_func(string x) {
    int p0 = 91;
    int p = 1;
    int a = 0;
    for (int i = 0; i < x.size(); ++i) {
        a = abs((a + (int(x[i]) * p) % n) % n);
        p = (p0 * p) % n;
    }
    return a % n;
}

void insert_1st(string first, string second) {
    int hash_x = hash_func(first);
    int hash_y = hash_func(second);
    list_1st *l1 = x[hash_x];
    if (l1 != nullptr) {
        while ((l1->next != nullptr) && (l1->key != first))
            l1 = l1->next;
        if (l1->key == first) {
            if (l1->count != 0) {
                list_2nd *l2 = l1->y[hash_y];
                while ((l2 != NULL) && (l2->next != nullptr) && (l2->key != second))
                    l2 = l2->next;
                if (l2->key != second) {
                    list_2nd *p;
                    l1->count++;
                    p = new list_2nd;
                    l2->next = p;
                    p->prev = l2;
                    p->key = second;
                }
            } else {
                list_2nd *p;
                p = new list_2nd;
                p->key = second;
                l1->y[hash_y] = p;
                l1->count++;
            }
        } else {
            list_1st *p;
            p = new list_1st;
            p->key = first;
            p->count = 1;
            p->prev = l1;
            l1->next = p;
            list_2nd *l2;
            l2 = new list_2nd;
            l2->key = second;
            p->y = new list_2nd *[n];
            p->y[hash_y] = l2;
            l1->next = p;
            delete l2;
            delete p;
        }
    } else {
        list_1st *l1;
        l1 = new list_1st;
        l1->key = first;
        l1->count = 1;
        list_2nd *l2;
        l2 = new list_2nd;
        l2->key = second;
        l1->y = new list_2nd *[n];
        l1->y[hash_y] = l2;
        x[hash_x] = l1;
    }
}

void delete_pair(string first, string second) {
    int hash_x = hash_func(first);
    int hash_y = hash_func(second);
    list_1st *l1 = x[hash_x];
    if (l1 != nullptr) {
        while ((l1->next != nullptr) && (l1->key != first))
            l1 = l1->next;
        if ((l1->key == first) && (l1->y != nullptr)) {
            list_2nd *l2 = l1->y[hash_y];
            if (l2 != nullptr) {
                while ((l2->next != nullptr) && (l2->key != second))
                    l2 = l2->next;
                if (l2->key == second) {
                    if ((l2->prev == nullptr) && (l2->next == nullptr)) {
                        if (l1->count == 1) {
                            l1->y = nullptr;
                            if (l1 == x[hash_x])
                                x[hash_x] = x[hash_x]->next;
                            else {
                                if (x[hash_x]->prev != nullptr)
                                    x[hash_x]->prev->next = x[hash_x]->next;
                                if (x[hash_x]->next != nullptr)
                                    x[hash_x]->next->prev = x[hash_x]->prev;
                            }
                        } else {
                            l1->count--;
                            l1->y[hash_y] = nullptr;
                        }
                    } else {
                        if (l2 == l1->y[hash_y]) {
                            l1->count--;
                            l1->y[hash_y] = l1->y[hash_y]->next;
                            delete (l1->y[hash_y]->prev);
                            l1->y[hash_y]->prev = nullptr;
                        } else {
                            l1->count--;
                            if (l1->y[hash_y]->prev != nullptr)
                                l1->y[hash_y]->prev->next = l1->y[hash_y]->next;
                            if (l1->y[hash_y]->next != nullptr)
                                l1->y[hash_y]->next->prev = l1->y[hash_y]->prev;
                        }
                    }
                }
            }
        }

    }
}

void get(string first) {
    int hash_x = hash_func(first);
    list_1st *l1 = x[hash_x];
    if (l1 != nullptr) {
        while ((l1->next != nullptr) && (l1->key != first))
            l1 = l1->next;
        if (l1->key == first) {
            cout << l1->count << ' ';
            list_2nd *l2;
            l2 = new list_2nd;
            for (int i = 0; i < n; i++) {
                l2 = l1->y[i];
                if (l2 != nullptr)
                    cout << l2->key << ' ';
                while ((l2 != nullptr) && (l2->next != nullptr)) {
                    l2 = l2->next;
                    cout << l2->key << ' ';
                }
            }
            delete l2;
            cout << "\n";
        } else cout << 0 << "\n";
    } else cout << 0 << "\n";
}

void deleteall(string first) {
    int hash_x = hash_func(first);
    list_1st *l1 = x[hash_x];
    if (l1 != nullptr) {
        while ((l1->next != nullptr) && (l1->key != first))
            l1 = l1->next;
        if (l1->key == first) {
            l1->y = nullptr;
            if (l1 == x[hash_x]) {
                x[hash_x] = x[hash_x]->next;
            } else {
                if (l1->prev != nullptr)
                    l1->prev->next = l1->next;
                if (l1->next != nullptr)
                    l1->next->prev = l1->prev;
                delete l1;
            }
        }
    }
}

int main() {
    freopen("multimap.txt", "r", stdin);
    freopen("multimap.txt", "w", stdout);
    string s, x;
    while (cin >> s) {
        cin >> x;
        if (s == "put") {
            string y;
            cin >> y;
            insert_1st(x, y);
        }
        if (s == "get") {
            get(x);
        }
        if (s == "delete") {
            string y;
            cin >> y;
            delete_pair(x, y);
        }
        if (s == "deleteall") {
            deleteall(x);
        }
    }
}