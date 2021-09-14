#include <iostream>
using namespace std;
struct node
{
    node* l;
    node* r;
    node* p;
    int key;
    int height;
};
node arr[200000];
void make_el(int i, int key, int l, int r)
{
    arr[i].key = key;
    if (l != 0) {
        arr[l].p = &arr[i];
        arr[i].l = &arr[l];
    }
    if (r != 0)
    {
        arr[r].p = &arr[i];
        arr[i].r = &arr[r];
    }
}

int height(node* p)
{
    if (p == NULL)
        return 0;
    if ((p -> l == NULL) && (p -> r == NULL))
    {
        p -> height = 1;
        return 1;
    }
    p -> height = max(height(p -> l), height(p -> r)) + 1;
    return p -> height;
}

int main() {
    //freopen("balance.in", "r", stdin);
    //freopen("balance.out", "w", stdout);
    int n;
    cin >> n;
    arr[0].height = 0;
    int l;
    int r;
    int key;
    for (int i = 1; i <= n; i++) {
        cin >> key >> l >> r;
        make_el(i, key, l, r);
    }
    height(&arr[1]);
    for (int i = 1; i <= n; i++)
    {
        if ((arr[i].r == NULL) && (arr[i].l == NULL))
            cout << 0 << "\n";
        else{
            if (arr[i].r == NULL)
                cout << -arr[i].l -> height << "\n";
            else
            {
                if (arr[i].l == NULL)
                    cout << arr[i].r -> height << "\n";
                else
                    cout << arr[i].r -> height - arr[i].l -> height << "\n";
            }
        }
    }
    return 0;
}