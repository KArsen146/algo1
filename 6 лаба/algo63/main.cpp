#include <iostream>
#include <string>
#include <climits>

using namespace std;
struct list
{
    list* l;
    list* r;
    int key;
    list* parent;
};
list* head = NULL;
void insert(int x, list* par) {
    if (x < par -> key)
    {
        if (par -> l == NULL)
        {
            list *p = new list;
            p -> l = NULL;
            p -> r = NULL;
            p -> key = x;
            p -> parent = par;
            par -> l = p;
        }
        else
            insert(x, par->l);
    }
    else {
        if (x > par->key) {
            if (par->r == NULL) {
                list *p = new list;
                p->l = NULL;
                p->r = NULL;
                p->key = x;
                p->parent = par;
                par->r = p;
            } else
                insert(x, par->r);
        }
    }
}

bool exists(int x, list* par)
{
    if (par == NULL)
        return false;
    if (x == par -> key)
        return true;
    if (x < par -> key)
        return exists(x, par -> l);
    return exists(x, par -> r);
}

list* prev(int x)
{
    list *p = head;
    list *nextel = NULL;
    while (p != NULL) {
        if (p->key < x) {
            nextel = p;
            p = p->r;
        } else p = p->l;
    }
    return nextel;
}

list* next(int x)
{
    list *p = head;
    list *nextel = NULL;
    while (p != NULL) {
        if (p->key > x) {
            nextel = p;
            p = p->l;
        } else p = p->r;
    }
    return nextel;
}

void delete_el(int x) {
    list *p = new list;
    p = head;
    while ((p != NULL) && (p -> key != x)) {
        if (x < p->key)
            p = p->l;
        else
            p = p->r;
    }
    if (p != NULL){

            list *change;
            list *delbabies;
            if (p->l == nullptr || p->r == nullptr)
                change = p;
            else
                change = prev(x);
            if (change->l != nullptr)
                delbabies = change->l;
            else
                delbabies = change->r;
            if (delbabies != nullptr)
                delbabies->parent = change->parent;
            if (change->parent == nullptr)
                head = delbabies;
            else if (change == change->parent->l)
                change->parent->l = delbabies;
            else
                change->parent->r = delbabies;
            if (change != p)
                p->key = change->key;
            delete change;
        }
}


int main() {
    freopen("bstsimple.in", "r", stdin);
    freopen("bstsimple.out", "w", stdout);
    int x;
    string s;
    while (cin >> s)
    {
        cin >> x;
        if (s == "insert")
        {
            if (head == NULL)
            {
                head = new list;
                head -> parent = NULL;
                head -> r = NULL;
                head -> l = NULL;
                head -> key = x;
            }
            else
                insert(x, head);
        }
        else
        {
            if (s == "delete")
                delete_el(x);
            else
            {
                if (s == "exists")
                {
                    if (exists(x,head))
                        cout << "true\n";
                    else
                        cout << "false\n";
                } else
                {
                    if (s == "next") {
                        list *l = next(x);
                        if (l == NULL)
                            cout << "none\n";
                        else
                            cout << l->key << '\n';
                    }
                    else
                    {
                        list *l = prev(x);
                        if (l == NULL)
                            cout << "none\n";
                        else
                            cout << l->key << '\n';
                    }
                }
            }
        }
    }
    //cout << head->r->key;
    return 0;
}