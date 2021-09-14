#include <iostream>
#include <string>
using namespace std;
struct list
{
    list* next;
    long long key;
    list* previous;
};
list *last = NULL;
list *first = NULL;
void push(long long k)
{
    list *l;
    l = new list;
    l -> key = k;
    l -> next = last;
    l -> previous = NULL;
    if (last != NULL) {
        (l->next)->previous = l;
        if (l->next->next == NULL)
            first = l -> next;
    }
    else first = l;
    last  = l;

}
void popstack()
{
    cout << last -> key << "\n";
    last = last -> next;
}

void popqueue()
{
    cout << first -> key << "\n";
    if (first == last)
        last = NULL;
    first = first -> previous;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    long long k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "-")
            popqueue();
        else
        {
            cin >> k;
            push(k);
        }
    }
    return 0;
}