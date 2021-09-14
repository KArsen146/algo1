#include <iostream>
#include <vector>
#include <string>
#include <strstream>
using namespace std;
struct list
{
    long long key;
    list* next;
    list* prev;
    long long value
};
vector <list*> v(1000007, NULL);
int hash_func(int x)
{
    return abs(x) % 1000007;
}

void insert(int k, long long x)
{
    list *l;
    l = new list;
    l = v[k];
    if (v[k] != NULL)
    {
        while ((l -> next != NULL) && (l -> key != x))
        {
            l = l -> next;
        }
    }
    if ((l == NULL) || (l -> key != x))
    {
        list *p;
        p = new list;
        p -> next = NULL;
        p -> prev = l;
        p -> key = x;
        if (l != NULL)
            l -> next = p;
        else
            v[k] = p;
    }
}

void exists(int k, long long x)
{
    list *l;
    l = new list;
    l = v[k];
    if (l != NULL)
        while ((l -> next != NULL) && (l -> key != x))
        {
            l = l -> next;
        }
    if ((l != NULL) && (l -> key == x))
        cout << "true\n";
    else
        cout << "false\n";
}

void delete_(int k, long long x)
{
    list *l;
    l = new list;
    l = v[k];
    if (l != NULL)
    {
        while ((l -> next != NULL) && (l  -> key != x))
            l = l -> next;
        if (l != v[k]) {
            if (l->key == x)
                l->prev->next = l->next;
        } else
        {
            if (l -> key == x)
                v[k] = v[k] -> next;
        }
    }
}
int main()
{
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    string s,s1;
    int hash;
    long long x;
    while (cin >> s)
    {
        cin >> s1;
        strstream str;
        str << s1;
        str >> x;
        hash = hash_func(x);
        if (s =="insert")
            insert(hash, x);
        if (s =="exists")
            exists(hash, x);
        if (s =="delete")
            delete_(hash, x);
    }
}