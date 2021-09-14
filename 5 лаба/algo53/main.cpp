#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct list
{
    string key;
    list* next;
    list* prev;
    list* prev_in;
    list* next_in;
    string value;
};
vector <list*> v(1000007, NULL);
list* last = NULL;
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
    list* l = v[k];
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
        p -> prev_in = last;
        if (last != NULL)
            last -> next_in = p;
        p -> next_in = NULL;
        if (l != NULL)
            l -> next = p;
        else
            v[k] = p;
        last = p;
    } else{
        if (l -> key == x)
            l -> value = value;

        }
}

void get (int k, string x)
{
    list* l = v[k];
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
    list* l = v[k];
    if (l != NULL)
    {
        while ((l -> next != NULL) && (l  -> key != x))
            l = l -> next;
        if (l != v[k]) {
            if (l -> key == x) {
                if (l == last)
                    last = last -> prev_in;
                if (l -> prev_in != NULL)
                    l -> prev_in -> next_in = l -> next_in;
                if (l -> next_in != NULL)
                    l -> next_in -> prev_in = l -> prev_in;
                if (l -> prev != NULL)
                    l -> prev -> next = l -> next;
            }
        } else
        {
            if (l -> key == x) {
                if (l == last)
                last = last -> prev_in;
                if (v[k] -> prev_in != NULL)
                    v[k] -> prev_in -> next_in = v[k] -> next_in;
                if (v[k] -> next_in != NULL)
                    v[k] -> next_in -> prev_in = v[k] -> prev_in;
                v[k] = v[k]->next;
            }
        }
    }
}

void prev_out (int k, string x)
{
    list* l = v[k];
    if (l != NULL)
        while ((l -> next != NULL) && (l -> key != x))
        {
            l = l -> next;
        }
    if ((l != NULL) && (l -> key == x)&& (l -> prev_in != NULL))
        cout << l -> prev_in -> value<< "\n";
    else
        cout <<"none\n";
};

void next_out (int k, string x)
{
    list* l = v[k];
    if (l != NULL)
        while ((l -> next != NULL) && (l -> key != x))
        {
            l = l -> next;
        }
    if ((l != NULL) && (l -> key == x) && (l -> next_in != NULL))
        cout << l -> next_in -> value<< "\n";
    else
        cout <<"none\n";
};
int main() {
    freopen("linkedmap.in", "r", stdin);
    freopen("linkedmap.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    string s, s1;
    int hash;
    long long x;
    while (cin >> s) {
        cin >> s1;
        hash = hash_func(s1);
        if (s == "put") {
            string y;
            cin >> y;
            insert(hash, s1, y);
        }
        if (s == "get")
            get(hash, s1);
        if (s == "delete")
            delete_(hash, s1);
        if (s == "prev")
            prev_out(hash, s1);
        if (s == "next")
            next_out(hash, s1);
    }
}