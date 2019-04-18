//
// Created by admin on 4/18/19.
//

#include <iostream>

using namespace std;

const int e9 = 1000 * 1000 * 1000;

struct summ {
    int left;
    int right;
    long long sum;
    summ(int _left, int _right, long long _sum) : left(_left), right(_right), sum(_sum) {}
};

class balanced_tree {
private:
    struct node {
        pair<int, summ> key = {0, {0, 0, 0}};
        int height = 1;
        node *left = nullptr;
        node *right = nullptr;
        node *parent = nullptr;

        node *rotate_right() {
            node *tmp = left;

            left = tmp->right;
            if (left)
                left->parent = this;
            tmp->right = this;
            tmp->parent = parent;
            parent = tmp;
            fix_height();
            tmp->fix_height();
            return tmp;
        }

        node *rotate_left() {
            node *tmp = right;

            right = tmp->left;
            if (right)
                right->parent = this;
            tmp->left = this;
            tmp->parent = parent;
            parent = tmp;
            fix_height();
            tmp->fix_height();
            return tmp;
        }

        node *balance() {
            fix_height();
            if (balance_factor() == 2) {
                if (right->balance_factor() < 0)
                    right = right->rotate_right();
                return rotate_left();
            }
            if (balance_factor() == -2) {
                if (left->balance_factor() > 0)
                    left = left->rotate_left();
                return rotate_right();
            }
            return this;
        }

        signed int balance_factor() {
            return (right ? right->height : 0) - (left ? left->height : 0);
        }

        node *find_min() {
            return (left ? left->find_min() : this);
        }

        void fix_height() {
            int hl = left ? left->height : 0;
            int hr = right ? right->height : 0;
            height = (hl > hr ? hl : hr) + 1;

            int sLeft = left ? left->key.second.left : key.second.left;
            int sRight = right ? right->key.second.right : key.second.right;
            long long sSum = (left ? left->key.second.sum : 0) + (right ? right->key.second.sum : 0) + key.first;
            key.second = {sLeft, sRight, sSum};
        }

        node(int _key, node *_parent) {
            key = {_key, {_key, _key, _key}};
            parent = _parent;
            node * tmp = parent;
            while (tmp) {
                tmp->fix_height();
                tmp = tmp->parent;
            }
        }

        ~node() {
            delete left;
            delete right;
        }

        node *insert(int _key) {
            if (_key < key.first) {
                left = left ? left->insert(_key) : new node(_key, this);
            }
            if (_key > key.first) {
                right = right ? right->insert(_key) : new node(_key, this);
            }

            return balance();
        }

        long long sum(int _left, int _right) {
            if (_left > key.second.right || _right < key.second.left)
                return 0;
            if (_left < key.second.left && key.second.right < _right)
                return key.second.sum;
            long long result = 0;
            if (left)
                result += left->sum(_left, _right);
            if (right)
                result += right->sum(_left, _right);
            if (_left <= key.first && key.first <= _right)
                result += key.first;
            return result;
        }
    };

    node *root = nullptr;
public:


    balanced_tree() = default;

    ~balanced_tree() {
        delete root;
    }

    void insert(int key) {
        root = root ? root->insert(key) : new node(key, nullptr);
    }

    long long sum(int left, int right) {
        return root ? root->sum(left, right) : 0;
    }
};


int main() {
# ifdef _DEBUG
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    balanced_tree bal;

    int n; cin >> n;
    string s;
    int x, y;
    long long lastResult = 0;
    bool isSum = false;
    for (int i = 0; i < n; ++i) {
        cin >> s >> x;
        switch (s[0]) {
            case '+':
                bal.insert((x + (isSum ? lastResult : 0)) % e9);
                isSum = false;
                break;
            case '?':
                cin >> y;
                lastResult = bal.sum(x, y);
                cout << lastResult << '\n';
                isSum = true;
                break;
            default:
                throw 228;
        }
    }

    return 0;
}
