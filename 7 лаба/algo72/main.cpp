#include <iostream>
using namespace std;
struct node
{
    node* l;
    node* r;
    int key;
    int height;
    node* p;
};
int ind = 1;
struct write_tree
{
    int l;
    int r;
    int key;
};
write_tree arr2[800000];
node* head = NULL;
node arr[2000000];
void make_el(int i, int key, int l, int r)
{
    arr[i].key = key;
    if (l != 0) {
        arr[l].p = &arr[i];
        arr[i].l = &arr[l];
    }
    if (r != 0)
    {
        arr[r].p = &arr[i];
        arr[i].r = &arr[r];
    }
}

int balance(node * p)
{
    int hl = 0;
    int hr = 0;
    if (p -> r != NULL)
        hr = p -> r -> height;
    if (p -> l != NULL)
        hl = p -> l -> height;
    return hr - hl;
}
int height(node* p)
{
    if (p == NULL)
        return 0;
    if ((p -> l == NULL) && (p -> r == NULL))
    {
        p -> height = 1;
        return 1;
    }
    p -> height = max(height(p -> l), height(p -> r)) + 1;
    return p -> height;
}

void correct_height(node* p)
{
    int pl = 0;
    int pr = 0;
    if (p -> l != NULL)
        pl = p -> l -> height;
    if (p -> r != NULL)
        pr = p -> r -> height;
    p -> height = max(pr, pl) + 1;
}

node* small_left_rot(node* p)
{
    node* b = p -> r;
    p -> r = b -> l;
    b -> l = p;
    correct_height(b);
    correct_height(p);
    return b;
}

node* small_right_rot(node* p)
{
    node* b = p -> l;
    p -> l = b -> r;
    b -> r = p;
    correct_height(b);
    correct_height(p);
    return b;
}

node* big_left_rot(node* p)
{
    node* b = small_right_rot(p -> r);
    p -> r = b;
    p = small_left_rot(p);
    correct_height(p);
    return p;
}

void new_ind(node* p, int i)
{
    arr2[i].key = p -> key;
    if (p -> l != NULL) {
        arr2[i].l = ind + 1;
        ind ++;
        new_ind(p -> l, ind);
    }
    else
        arr2[i].l = 0;
    if (p -> r != NULL) {
        ind++;
        arr2[i].r = ind;
        new_ind(p -> r, ind);
    } else
        arr2[i].r = 0;
}
int main() {
   freopen("rotation.in", "r", stdin);
    freopen("rotation.out", "w", stdout);
    int n;
    cin >> n;
    arr[0].height = 0;
    int l;
    int r;
    int key;
    for (int i = 1; i <= n; i++) {
        cin >> key >> l >> r;
        make_el(i, key, l, r);
    }
    arr[1].height = height(&arr[1]);
    if (balance(arr[1].r) == -1) {
        head = big_left_rot(&arr[1]);
    } else
        head = small_left_rot(&arr[1]);
    cout << n << endl;
    for (int i = 1; i <= n; i++)
    {
        arr2[i].key = -1;
        arr2[i].l = -1;
        arr2[i].r = -1;
    }
    new_ind(head, 1);
    for (int i = 1; i <= n; i++)
        cout << arr2[i].key << ' ' << arr2[i].l << ' '<<arr2[i].r<<endl;
    return 0;
}