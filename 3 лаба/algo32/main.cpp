#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
double lef;

double func(vector<double> &v, double m) {
    v[0] = lef;
    v[1] = m;
    double k = min(v[0], v[1]);
    for (int i = 2; i < n; i++) {
        v[i] = 2 * (1 + v[i - 1]) - v[i - 2];
        if (v[i] < k)
            k = v[i];
    }
    return k;
}

double bin_search(vector<double> &v, double l, double r) {
    if (r - l > 0.0000001) {
        double m = (l + r) / 2;
        if (func(m) >= 0)
            return bin_search(l, m);
        else
            return bin_search(m, r);
    } else {
        v[0] = lef;
        v[1] = l;
        double k;
        for (int i = 2; i < n; i++)
            v[i] = 2 * (1 + v[i - 1]) - v[i - 2];
        return v[n - 1];
    }
}

int main() {
    cin >> n >> lef;
    vector<double> v(n);
    cout << fixed;
    cout.precision(2);
    cout << bin_search(0, lef);
    return 0;
}