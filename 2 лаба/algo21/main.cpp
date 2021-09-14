#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &a, vector<int> &arr, int p, int r) {
    if (p < r) {
        int i = p;
        int j = (p + r) / 2 + 1;
        int k = p;
        while ((j < r + 1) && (i < (p + r) / 2 + 1)) {
            if (a[i] > a[j]) {
                arr[k] = a[j];
                j++;
            } else {
                arr[k] = a[i];
                i++;
            }
            k++;
        }
        while (j < r + 1) {
            arr[k] = a[j];
            j++;
            k++;
        }
        while (i < (p + r) / 2 + 1) {
            arr[k] = a[i];
            i++;
            k++;
        }
        for (int k = p; k < r + 1; k++) {
            a[k] = arr[k];
        }
    }
}

void m_sort(vector<int> &a, vector<int> &arr, int p, int r) {
    if (p < r) {
        m_sort(a, arr, p, (p + r) / 2);
        m_sort(a, arr, (p + r) / 2 + 1, r);
        merge(a, arr, p, r);
    }
}

void merge_sort(vector<int> &a) {
    vector<int> arr(a.size() - 1, 0);
    m_sort(a, arr, 0, a.size() - 1);
}

int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    merge_sort(a);
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    return 0;
}