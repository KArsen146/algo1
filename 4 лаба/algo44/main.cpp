#include <iostream>
#include <string>
using namespace std;
struct list
{
    list* next;
    int key;
    list* previous;
};
list *last = NULL;
list *first = NULL;
void push(int k)
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
    last = l;
}
int popstack()
{
    int x = last -> key;
    last = last -> next;
    return x;
}

void popqueue()
{
    cout << first -> key << "\n";
    if (first == last)
        last = NULL;
    first = first -> previous;
}

int main() {
    freopen("postfix.in", "r", stdin);
    freopen("postfix.out", "w", stdout);
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ') {
            if (s[i] == '+')
                push(popstack() + popstack());
            else if (s[i] == '*')
                push(popstack() * popstack());
            else if (s[i] == '-')
            {
                int k =  popstack() - popstack();
                push(-k);
            }
            else {
                push(int(s[i]) - '0');
            }
        }
    }
    cout << last -> key;
    return 0;
}