#include <iostream>
#include <algorithm>
using namespace std;
int sizeque;
pair <long long, long long> arr[1000005];
void sift_up(long long num)
{
    int j = num;
    while ((j >= 0) && (arr[j] < arr[(j - 1)/ 2]))
    {
        swap(arr[j], arr[(j - 1) / 2]);
        j = (j - 1) / 2;
    }
}

void push(long long value, long long num)
{
    sizeque ++;
    arr[sizeque].first = value;
    arr[sizeque].second = num;
    sift_up(sizeque);
}

void sift_down(int num)
{
    int ind = num;
    int l = 2 * num + 1;
    int r = 2 * num + 2;
    if ((l <= sizeque) && (arr[ind] > arr[l]))
        ind= l;
    if ((r <= sizeque) && (arr[ind] > arr[r]))
        ind = r;
    if (ind != num)
    {
        swap (arr[ind], arr[num]);
        sift_down(ind);
    }

}
void pop()
{
    if (sizeque != -1) {
        cout << arr[0].first << "\n";
        swap(arr[0], arr[sizeque]);
        sizeque--;
        sift_down(0);
    } else
    {
        cout << "*\n";
    }
}

void decrease(long long num, long long y)
{
    bool b = true;
    int i = 0;
    while (b)
    {
        if (arr[i].second == num)
        {
            b = false;
            arr[i].first = y;
            sift_up(i);
        }
        i++;
    }
}

int main() {
    freopen("priorityqueue.in", "r", stdin);
    freopen("priorityqueue.out", "w", stdout);
    string s;
    long long i = 0;
    long long x; long long y;
    sizeque = -1;
    while (cin >> s)
    {
        i ++;
        if (s == "push")
        {
            cin >> x;
            push(x, i);
        }
        else
        if (s == "extract-min")
        {
            pop();
        }
        else
        {
            cin >> x >> y;
            decrease(x, y);
        }
    }
    return 0;
}