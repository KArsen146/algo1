#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    string s[1000];
    vector <string> arr[27];
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 1; i <= k; i++)
    {
        int num = m - i;
        for (int j = 0; j < n; j++)
        {
            arr[int(s[j][num]) - int('a')+1].push_back(s[j]);
        }
        int iterator = 0;
        for (int j = 0; j < 27; j++)
        {
            for (int it = 0; it < arr[j].size(); it++) {
                s[iterator] = arr[j][it];
                iterator++;
            }
            arr[j].clear();
        }
    }
    for (int i = 0; i < n; i++)
        cout << s[i] << endl;
    return 0;
}