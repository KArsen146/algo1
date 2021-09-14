#include <iostream>
#include <vector>

using namespace std;

int bin_search_left(vector<int> &v, int l, int r, int k) {
    if (r - l > 1) {
        int m = (l + r) / 2;
        if (v[m] >= k) {
            return bin_search_left(v, l, m, k);
        } else {
            return bin_search_left(v, m, r, k);
        }
    } else {
        if ((r == v.size()) || (v[r] != k)) {
            return -1;
        } else {
            return r + 1;
        }
    }
}

int bin_search_right(vector<int> &v, int l, int r, int k) {
    if (r - l != 1) {
        int m = (l + r) / 2;
        if (v[m] > k) {
            return bin_search_right(v, l, m, k);
        } else {
            return bin_search_right(v, m, r, k);
        }
    } else {
        if ((l == -1) || (v[l] != k)) {
            return -1;
        } else {
            return l + 1;
        }
    }
}

int main() {
    int n, m, k;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> k;
        cout << bin_search_left(v, -1, n, k) << ' ' << bin_search_right(v, -1, n, k);
    }
    return 0;
}