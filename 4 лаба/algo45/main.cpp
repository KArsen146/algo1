#include <iostream>
#include <string>
using namespace std;
struct list
{
    list* next;
    pair <int, int> key;
    list* previous;
};
list *last = NULL;
list *first = NULL;
void push(int k, int num)
{
    list *l; list *ll;
    l = new list;
    l -> key.first = k;
    l -> key.second = num;
    ll = last;
    if (last!=NULL)
    {
    while ((ll -> next != NULL) && ((l -> key.first) < (ll -> next) -> key.first))
    {
        ll = ll -> next;
    }}
    if ((ll != last) && (last != 0)){
        l->next = ll->next;
        l->previous = ll->previous;
        (l->previous)->next = l;
        (l->next)->previous = l;
    }
    if (last != NULL) {
        if (l->next != NULL)
            (l->next)->previous = l;
        if (l -> next == NULL)
            first = l;
        else
        {
        if (l->next->next == NULL)
            first = l->next;}
    } else first = l;
    if (l -> next == NULL)
        first = l;
        if (l->previous == NULL)
        last = l;
}
int popstack()
{
    int x = last -> key.first;
    last = last -> next;
    return x;
}

void popqueue()
{
    cout << first -> key.first << "\n";
    if (first == last)
        last = NULL;
    first = first -> previous;
}
void outlist()
{
    list *p;
    p = last;
    while(p != NULL)
    {
        cout << p -> key.first  << ' ' << p -> key.second << endl;
        p = p -> next;
    }
}
int main() {
    string s; int x; int y; int i = 0;
    while (i<4)
    {
        cin >>s;
        if (s == "push")
        {
            cin >> x;
            push(x, i);
        }
        i++;
        outlist();
    }

    return 0;
}