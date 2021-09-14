#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int nx = 1000007, ny = 100;
struct list_1st;
struct list_2nd {
    list_2nd* next;
    list_2nd* prev;
    string value;
    list_1st* key;
};
struct list_1st {
    string key;
    list_2nd** y;
    long long count;
    list_1st* next;
    list_1st* prev;
};
vector <list_1st*> x(nx, nullptr);
list_1st* cur_key;

long long hash_func (string key, long long n)
{
    long long simple = 179;
    long long num = 1;
    long long res = 0;
    for (long long i = 0; i < key.size(); i++){
        res = abs((res + (int (key[i]) * num) % n) % n);
        num = (num * simple) % n;
    }
    return res % n;
}

list_1st* find_x(string first) {
    long long key = hash_func(first, nx);
    list_1st* p = x[key];
    if (p == nullptr)
        return nullptr;
    while ((p->next != nullptr) && (p->key != first))
        p = p->next;
    if (p->key == first)
        return p;
    else return nullptr;
}

list_2nd* find_y(string first, string second) {
    list_1st* p = find_x(first);
    cur_key = p;
    if (p == nullptr)
        return nullptr;
    long long key = hash_func(second, ny);
    list_2nd* p2 = p->y[key];
    if (p2 == nullptr)
        return nullptr;
    while ((p2->next != nullptr) && (p2->value != second))
        p2 = p2->next;
    if (p2->value == second)
        return p2;
    else return nullptr;
}


void put(string first, string second) {
    long long key = hash_func(first, nx);
    list_2nd* p2 = find_y(first, second);
    if (p2 == nullptr) {
        long long key2 = hash_func(second, ny);
        list_1st* p = cur_key;
        list_2nd* elem;
        elem = new list_2nd;
        elem->value = second;
        elem->prev = nullptr;
        elem->next = nullptr;
        if (p != nullptr) {
            elem->key = p;
            if (p->y[key2] == nullptr)
                p->y[key2] = elem;
            else {
                p->y[key2]->prev = elem;
                elem->next = p->y[key2];
                p->y[key2] = elem;
            }
            p->count++;
        }
        else {
            list_1st* elem1;
            elem1 = new list_1st;
            elem1->key = first;
            elem1->count = 1;
            elem1->y = new list_2nd*[101];
            for (long long i = 0; i < 101; i++)
                elem1->y[i] = nullptr;
            elem1->y[key2] = elem;
            if (x[key] != nullptr)
                x[key]->prev = elem1;
            elem1->next = x[key];
            elem1->prev = nullptr;
            elem->key = elem1;
            x[key] = elem1;
        }
    }
}

void delete_pair(string first, string second) {
    int key = hash_func(first, nx);
    list_2nd* p = find_y(first, second);
    if (p != nullptr) {
        int key2 = hash_func(second, ny);
        list_1st* p2 = p->key;
        if (p->next != nullptr)
            p->next->prev = p->prev;
        if (p->prev != nullptr)
            p->prev->next = p->next;
        else p2->y[key2] = p->next;
        p2->count--;
    }
}
void deleteall(string first)
{
    long long hash_x = hash_func(first, nx);
    list_1st *l1 = x[hash_x];
    if (l1 != nullptr)
    {
        while ((l1 -> next != nullptr) && (l1 -> key != first))
            l1 = l1 -> next;
        if (l1 -> key == first)
        {
            l1 -> y = nullptr;
            if (l1 == x[hash_x])
            {
                x[hash_x] = x[hash_x] -> next;
            } else
            {
                if (l1 -> prev != nullptr)
                    l1 -> prev -> next = l1 -> next;
                if (l1 -> next != nullptr)
                    l1 -> next -> prev = l1 -> prev;
                delete l1;
            }
        }
    }
}

void get(string first)
{
    long long hash_x = hash_func(first, nx);
    list_1st *l1 = x[hash_x];
    if (l1 != nullptr)
    {
        while ((l1 -> next != nullptr) && (l1 -> key != first))
            l1 = l1 -> next;
        if (l1 -> key == first)
        {
            cout << l1 -> count << ' ';
            list_2nd *l2;
            l2 = new list_2nd;
            for (long long i = 0; i < ny; i++)
            {
                l2 = l1 -> y[i];
                if (l2 != nullptr)
                    cout << l2 -> value << ' ';
                while ((l2 != nullptr) && (l2 -> next != nullptr))
                {
                    l2 = l2 -> next;
                    cout << l2 -> value << ' ';
                }
            }
            cout << "\n";
        }
        else cout << 0 << "\n";
    }
    else cout << 0 << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("multimap.in", "r", stdin);
    freopen("multimap.out", "w", stdout);
    string command, key, value;
    while (cin >> command) {
        cin >> key;
        if (command == "put") {
            cin >> value;
            put(key, value);
        }
        if (command == "delete") {
            cin >> value;
            delete_pair(key, value);
        }
        if (command == "deleteall") {
            deleteall(key);
        }
        if (command == "get") {
            get(key);
        }
    }
    return 0;
}