#include <iostream>
using namespace std;
struct made
{
    int l;
    int r;
    int key;
};
made arr[200000];
int height(int i) {
    if ((arr[i].l == 0) && (arr[i].r == 0))
        return 1;
    else
    {
        if (arr[i].l == 0)
            return height(arr[i].r) + 1;
        if (arr[i].r == 0)
            return height(arr[i].l) + 1;
        return max(height(arr[i].l), height(arr[i].r)) + 1;
    }
};
int main() {
    freopen("height.in", "r", stdin);
    freopen("height.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].key >> arr[i].l >> arr[i].r;
    }
    if (n != 0)
        cout << height(1);
    else
        cout << 0;
    return 0;
}