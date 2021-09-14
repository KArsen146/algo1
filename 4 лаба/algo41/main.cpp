#include <iostream>
#include <string>
using namespace std;
struct list
{
    list* next;
    long long key;
};
list *last = NULL;
void push(long long k)
{
    list *l;
    l = new list;
    l -> key = k;
    l -> next = last;
    last = l;
}
void popstack()
{
    cout << last -> key << "\n";
    last = last -> next;
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
            popstack();
        else
        {
            cin >> k;
            push(k);
        }
    }
    return 0;
}