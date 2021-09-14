#include <iostream>
#include <vector>
#include <string>
#include <strstream>
using namespace std;
struct list
{
    string key;
    list* next;
    list* prev;
    string value;
};
vector <list*> v(1000007, NULL);
int hash_func (string x)
{
    int p0 = 19151;
    int p = 1;
    int a = 0;
    for (int i = 0; i < x.size(); ++i){
        a = abs((a + (int (x[i]) * p) % 1000007) % 1000007);
        p = (p0 * p) % 1000007;
    }
    return a % 1000007;
}

void insert (int k, string x, string value)
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
        p -> value = value;
        if (l != NULL)
            l -> next = p;
        else
            v[k] = p;
    } else{
        if (l -> key == x)
            l -> value = value;
    }
}

void get (int k, string x)
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
        cout << l -> value<< "\n";
    else
        cout <<"none\n";
}

void delete_ (int k, string x)
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
    freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    string s,s1;
    int hash;
    long long x;
    while (cin >> s)
    {
        cin >> s1;
        hash = hash_func(s1);
        if (s =="put") {
            string y;
            cin >> y;
            insert(hash, s1, y);
        }
        if (s =="get")
            get(hash, s1);
        if (s =="delete")
            delete_(hash, s1);
    }
}