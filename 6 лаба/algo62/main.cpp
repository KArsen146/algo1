#include <iostream>
using namespace std;
struct made
{
    int l;
    int r;
    int key;
};
made arr[200000];
bool right_tree(int i, int min_prev, int max_prev)
{
    if ((arr[i].l == 0) && (arr[i].r == 0))
        return true;
    else {
        bool a = true;
        bool b = true;
        if (arr[i].l != 0) {
            if ((arr[arr[i].l].key >=arr[i].key) || (arr[arr[i].l].key <= max_prev))
                return false;
            a = right_tree(arr[i].l,arr[i].key, max_prev);
        }
        if (arr[i].r != 0) {
            if ((arr[arr[i].r].key <=arr[i].key) || (arr[arr[i].r].key >= min_prev))
                return false;
            b = right_tree(arr[i].r, min_prev, arr[i].key);
        }
        if ((a == true) && (b == true))
            return true;
        return false;
    }
}
int main() {
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].key >> arr[i].l >> arr[i].r;
    }
    if ((n == 0) || (right_tree(1, 1000000009, -1000000009)))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}