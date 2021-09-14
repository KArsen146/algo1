#include <iostream>
using namespace std;
struct node
{
    node* l;
    node* r;
    int key;
    int balance;
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
        arr[i].l = &arr[l];
    }
    if (r != 0)
    {
        arr[i].r = &arr[r];
    }
}

int balance(node * p)
{
    if (p == NULL)
        return 0;
    int hl = 1 + balance(p->l);
    int hr = 1 + balance(p->r);
    p -> balance = hr - hl;
    return max(hl, hr);
}

node* small_left_rot(node* p)
{
    node* a = p;
    node* b = a -> r;
    a -> r = b -> l;
    b -> l = a;
    return b;
}

node* small_right_rot(node* p)
{
    node* a = p;
    node* b = a -> l;
    a->l = b->r;
    b->r = a;
    return b;
}

node* big_left_rot(node* p)
{
    node* b = p;
    p -> r = small_right_rot(p -> r);
    return small_left_rot(b);
}

node* big_right_rot(node* p)
{
    node* b = p;
    p -> l = small_left_rot(p -> l);
    return small_right_rot(b);
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

node* balance_v(node* p) {
    balance(p);
    if (p -> balance == 2) {
        if ((p->r != NULL) && (balance(p->r) < 0))
            p = big_left_rot(p);
        else
            p = small_left_rot(p);
    } else {
        if (p -> balance == -2) {
            if ((p->l != NULL) && (balance(p->l) > 0))
                p = big_right_rot(p);
            else
                p = small_right_rot(p);
        }
    }
    return p;
}

node* insert(int x, node* par) {
    if (par == NULL)
    {
        node *p = new node;
        p -> l = NULL;
        p -> r = NULL;
        p -> key = x;
        return p;
    }
    if (x < par -> key)
    {
        par -> l =insert(x, par -> l);
    }
    else
        par -> r = insert(x, par->r);
    return balance_v(par);
}

int main() {
    freopen("addition.in", "r", stdin);
    freopen("addition.out", "w", stdout);
    int n;
    cin >> n;
    int l;
    int r;
    int key;
    for (int i = 1; i <= n; i++) {
        cin >> key >> l >> r;
        make_el(i, key, l, r);
    }
    cin >> key;
    if (n == 0)
    {
        cout << 1 << endl;
        cout << key <<" 0 0\n";
        return 0;
    }
    head = insert(key, &arr[1]);
    n++;
    cout << n << endl;
    new_ind(head, 1);
    for (int i = 1; i <= n; i++)
        cout << arr2[i].key << ' ' << arr2[i].l << ' ' << arr2[i].r << endl;
    return 0;
}