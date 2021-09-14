#include <iostream>
using namespace std;
int a[100000];
int n;
void sift_down(int i, int n)
{
    int ind = i;
    int l = 2 * i;
    int r = 2 * i + 1;
    if ((l <= n) && (a[i] < a[l]))
        ind = l;
    else
        ind = i;
    if ((r <= n) && (a[ind] < a[r]))
        ind = r;
    if (ind != i)
    {
        swap(a[i], a[ind]);
        sift_down(ind, n);
    }
}
void build()
{
    for (int i = n; i >= 1; i--) {
        sift_down(i, n);
    }
}
void heap()
{
    build();
    sift_down(1, n);
    int k = n;
    for (int i = 1; i <=n; i++)
    {
        swap(a[1], a[k]);
        k--;
        sift_down(1, k);
    }
}

int main()
{
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    heap();
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    return 0;
}