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
void push(long long k, int num)
{
    list *l; list *l2;
    l2 = new list;
    l2 -> key.first = k;
    l2 -> key.second = num;
    if (last == 0)
    {
        last = l2;
        first = l2;
    }
    else
    {
        list *tmp;
        last -> previous = l2;
        l2 -> next = last;
        l2 -> previous = 0;
        l = last ->next;
        while ((l!= NULL)&&(l2 -> key.first < l -> key.first))
        {
            tmp = l;
            (l -> previous )->next = l2;
            l -> previous = l2;
            l2 -> previous = tmp;
            l2 -> next = l;
            l = l -> next;
        }
        if (l == NULL)
        {
            first -> next = l2;
            l2 -> previous = first;
            l2 -> next = 0;
        }
    }
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
        cout << p -> key.first  <<endl;
        p = p -> next;
    }
}
int main() {
    string s; int x; int y; int i = 0;
    while (i<3)
    {
            cin >> x;
            push(x, i);
        i++;

        cout << first -> key. first << ' '<<last -> key.first<< ' ';
        }
    outlist();

    return 0;
}