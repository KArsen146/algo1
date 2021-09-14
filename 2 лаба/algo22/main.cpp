#include <iostream>
#include <string>
#include <vector>

using namespace std;

void merge(vector<pair<string, string>> &a, vector<pair<string, string>> &arr, int p, int r) {
    if (p < r) {
        int i = p;
        int j = (p + r) / 2 + 1;
        int k = p;
        while ((j < r + 1) && (i < (p + r) / 2 + 1)) {
            if (a[i].first > a[j].first) {
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

void m_sort(vector<pair<string, string>> &a, vector<pair<string, string>> &arr, int p, int r) {
    if (p < r) {
        m_sort(a, arr, p, (p + r) / 2);
        m_sort(a, arr, (p + r) / 2 + 1, r);
        merge(a, arr, p, r);
    }
}

void merge_sort(vector<pair<string, string>> &a) {
    vector<pair<string, string>> arr(a.size());
    m_sort(a, arr, 0, a.size() - 1);
}


int main() {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<string, string>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    merge_sort(a);
    int i = 0;
    while (i < n) {
        cout << "=== " << a[i].first << " ===" << endl;
        string ind = a[i].first;
        while ((i < n) && (a[i].first == ind)) {
            cout << a[i].second << endl;
            i++;
        }
    }
    return 0;
}