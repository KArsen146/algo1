#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    freopen("antiqs.in", "r", stdin);
    freopen("antiqs.out", "w", stdout);
    int n;
    int a[70000];
    cin >> n;
    int l = 0;
    int r = n - 1;
    int k = 1;
    while (l < r + 1)
    {
        a[(l + r) / 2] = k;
        swap(a[l], a[(l + r) / 2]);
        k++;
        l++;
    }
    while (l > 0)
    {
        l--;
        swap(a[l], a[(l + r) / 2]);
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    return 0;
}