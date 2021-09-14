#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int qsortt(vector<int>& arr, int p, int r, int k) {
    if (p < r) {
        int i = p;
        int j = r;
        int m = arr[p];
        while (i <= j) {
            while (arr[i] < m)
                i++;
            while (arr[j] > m)
                j--;
            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
        if ((k > j) && (k < i))
            cout << m;
        else {
            if (k <= j)
                qsortt(arr, p, j, k);
            else
                qsortt(arr, i, r, k);
        }
    } else
        cout << arr[p];
}

int main() {
    int n, k, a, b, c;
    cin >> n >> k;
    vector<int> arr(n);
    cin >> a >> b >> c >> arr[0] >> arr[1];
    k--;
    for (int i = 2; i < n; i++)
        arr[i] = arr[i - 2] * a + arr[i - 1] * b + c;
    qsortt(arr, 0, n - 1, k);
    return 0;
}