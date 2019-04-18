//
// Created by admin on 4/18/19.
//

#include <iostream>

using namespace std;

class balanced_tree {
private:
    struct node {
        pair<int, int> key;
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
                         isSum = false;   return (right ? right->height : 0) - (left ? left->height : 0);
        }

        node *find_min() {
            return (left ? left->find_min() : this);
        }

        void fix_height() {
            int hl = left ? left->height : 0;
            int hr = right ? right->height : 0;
            height = (hl > hr ? hl : hr) + 1;

            int kl = left ? left->key.second : 0;
            int kr = right ? right->key.second : 0;
            key.second = kl + kr + 1;
        }

        node(int _key, node *_parent) {
            key = {_key, 1};
            parent = _parent;
            node * tmp = parent;
            while (tmp) {
                tmp->key.second++;
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

        node *remove(int _key) {
            if (_key < key.first) {
                if (left)
                    left = left->remove(_key);
                else
                    return this;
            } else if (_key > key.first) {
                if (right)
                    right = right->remove(_key);
                else
                    return this;
            } else if (_key == key.first) {
                if (!right) {
                    node *tmp = left;
                    if (tmp)
                        tmp->parent = parent;
                    left = nullptr;
                    delete this;
                    return tmp;
                }
                node *min = right->find_min();
                key = min->key;
                if (min->right) {
                    min->key = min->right->key;
                    min = min->right;
                }
                node *tmp = min->parent;
                (tmp->left == min ? tmp->left : tmp->right) = nullptr;
                delete min;
                while (tmp != this) {
                    tmp->balance();
                    tmp = tmp->parent;
                }
            }
            return balance();
        }

        int kmax(int pos) {
            int nodePos = right ? right->key.second : 0;
            if (pos < nodePos)
                return right->kmax(pos);
            if (pos == nodePos)
                return key.first;
            return left->kmax(pos - nodePos - 1);
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

    void remove(int key) {
        if (!root)
            return;
        root = root->remove(key);
    }

    int kmax(int pos) {
        return root->kmax(pos);
    }
};


int main() {
# ifdef _DEBUG
    freopen("test.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    balanced_tree bal;

    int n; cin >> n;
    string s;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> s >> x;
        switch (s[0]) {
            case '+':
            case '1':
                bal.insert(x);
                break;
            case '-':
                bal.remove(x);
                break;
            case '0':
                cout << bal.kmax(x - 1) << '\n';
                break;
            default:
                throw 228;
        }
    }

    return 0;
}
