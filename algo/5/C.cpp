//
// Created by admin on 4/17/19.
//
#include<iostream>
#include<algorithm>

using namespace std;

struct st {
    st() = default;

    st(int _a, int _b, int _num) : a(_a), b(_b), num(_num) {}

    int a;
    int b;
    int num;
};

bool rule_a(st &left, st &right) {
    return left.a < right.a;
}

struct node {
    int a;
    int b;
    int num;
    node *left = nullptr;
    node *right = nullptr;
    node *parent = nullptr;

    node(int _a, int _b, int _num) : a(_a), b(_b), num(_num) {}
};

bool rule_num(node *left, node *right) {
    return left->num < right->num;
}

node *root = nullptr;
node *last = nullptr;

void set(int a, int b, int num) {
    node *now = new node(a, b, num);
    if (!root) {
        root = now;
    } else {
        if (last->b < b) {
            last->right = now;
            now->parent = last;
        } else {
            while (last->parent && last->b > b)
                last = last->parent;
            if (last->b < b) {
                now->left = last->right;
                last->right->parent = now;

                last->right = now;
                now->parent = last;
            } else {
                root = now;
                now->left = last;
                last->parent = now;
            }
        }
    }
    last = now;
}

int counter = 0;

void read(node *arr[], node *now) {
    arr[counter] = now;
    counter += 1;
    if (now->left)
        read(arr, now->left);
    if (now->right)
        read(arr, now->right);
}

int main() {
#ifndef _DEBUG
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    st arr[n];
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        arr[i] = st(a, b, i + 1);
    }

    sort(arr, arr + n, rule_a);

    for (int i = 0; i < n; ++i)
        set(arr[i].a, arr[i].b, arr[i].num);

    node *arr_result[n];
    read(arr_result, root);
    sort(arr_result, arr_result + n, rule_num);

    cout << "YES" << endl;

    for (int i = 0; i < n; ++i) {
        node *now = arr_result[i];
        cout << (now->parent ? now->parent->num : 0) << ' '
             << (now->left ? now->left->num : 0) << ' '
             << (now->right ? now->right->num : 0) << endl;
    }

    return 0;
}
