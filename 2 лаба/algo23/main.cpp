#include <iostream>
using namespace std;
long long a[300000];
long long arr[300000];
long long z; // считает количество инверсий
void merge(long long a[300000], int p, int r)
{
    if (p < r)
    {
        int i = p;
        int j = (p + r) / 2 + 1;
        int k = p;
        while ( (j < r +1) && (i < (p + r) / 2 + 1))
        {
            if (a[i] > a[j])
            {
                arr[k] = a[j];
                j++;
                z = z + ((p + r) / 2 + 1 - i);
            }
            else {
                arr[k] = a[i];
                i++;
            }
            k++;
        }
        while (j < r + 1)
        {
            arr[k] = a[j];
            j++;
            k++;
        }
        while (i < (p + r) / 2 +1)
        {
            arr[k] = a[i];
            i++;
            k++;
        }
        for (int k = p; k < r + 1; k++)
        {
            a[k] = arr[k];
        }

    }
}

void M_sort(long long a[300000], int p, int r)
{
    if (p < r)
    {
        M_sort(a, p,(p + r) / 2);
        M_sort(a,(p + r) / 2 + 1, r);
        merge(a, p, r);
    }
}

int main()
{
    freopen("inversions.in", "r", stdin);
    freopen("inversions.out", "w", stdout);
    z = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    M_sort(a, 0, n-1);
    cout << z;
    return 0;
}