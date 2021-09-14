#include <iostream>
#include <string>
using namespace std;
struct list
{
    list* next;
    char key;
    list* previous;
};
list *last = NULL;
list *first = NULL;
void push(char k)
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
void popstack()
{
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
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    bool b;
    while (cin >> s)
    {
        b = true;
        for (int i = 0; i < s.length(); i++) {
            if ((s[i] == '(') || (s[i] == '['))
                push(s[i]);
            else
            {
                if (s[i] == ')')
                {
                    if ((last == 0) ||(last -> key != '('))
                    {
                        if (b)
                            cout << "NO\n";
                        b = false;
                    }
                    else
                        popstack();
                } else
                {
                    if ((last == 0) ||( last -> key != '['))
                    {
                        if (b)
                            cout << "NO\n";
                        b = false;
                    }
                    else
                        popstack();
                }
            }
        }
        if ((b) && (last == NULL))
            cout << "YES\n";
        else
        {
            if (b)
                cout << "NO\n";
        }
        last = NULL;
    }
    return 0;
}