#include <iostream>

using namespace std;

int main() {
    int a[100000];
    int n;
    cin >> n;
    for (int i = 1; i < n + 1; i++)
        cin >> a[i];
    bool ind = true;
    for (int i = 1; i < n + 1; i++) {
        if ((2 * i < n + 1) && (a[i] < a[2 * i]))
            ind = false;
        if ((2 * i + 1 < n + 1) && (a[i] < a[2 * i + 1]))
            ind = false;
    }
    if (ind)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}