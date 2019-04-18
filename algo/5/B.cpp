//
// Created by admin on 4/17/19.
//

#include <iostream>

using namespace std;

class balanced_tree {
private:
    struct node {
        int key;
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

        node *find_max() {
            return (right ? right->find_max() : this);
        }

        void fix_height() {
            int hl = left ? left->height : 0;
            int hr = right ? right->height : 0;
            height = (hl > hr ? hl : hr) + 1;
        }

        node(int _key, node *_parent) {
            key = _key;
            parent = _parent;
        }

        ~node() {
            delete left;
            delete right;
        }

        node *insert(int _key) {
            if (_key < key) {
                left = left ? left->insert(_key) : new node(_key, this);
            }
            if (_key > key) {
                right = right ? right->insert(_key) : new node(_key, this);
            }

            return balance();
        }

        node *remove(int _key) {
            if (_key < key) {
                if (left)
                    left = left->remove(_key);
                else
                    return this;
            } else if (_key > key) {
                if (right)
                    right = right->remove(_key);
                else
                    return this;
            } else if (_key == key) {
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

        pair<node *, node *> find(int _key) {
            if (_key == key)
                return {this, parent};
            return _key < key
                   ? (left ? left->find(_key) : make_pair(nullptr, this))
                   : (right ? right->find(_key) : make_pair(nullptr, this));
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

    bool exists(int key) {
        return root && root->find(key).first;
    }

    pair<int, bool> next(int key) {
        pair<node *, node *> findResult = (root ? root->find(key) : make_pair(nullptr, nullptr));
        node *now = findResult.first;
        node *parent = findResult.second;
        if (now && now->right) {
            now = now->right->find_min();
        } else {
            while (parent && (key > parent->key)) {
                parent = parent->parent;
            }
            now = parent;
        }
        if (now)
            return {now->key, true};
        else
            return {0, false};
    }

    pair<int, bool> prev(int key) {
        pair<node *, node *> findResult = (root ? root->find(key) : make_pair(nullptr, nullptr));
        node *now = findResult.first;
        node *parent = findResult.second;
        if (now && now->left) {
            now = now->left->find_max();
        } else {
            while (parent && (key < parent->key)) {
                parent = parent->parent;
            }
            now = parent;
        }
        if (now)
            return {now->key, true};
        else
            return {0, false};
    }
};


int main() {
# ifndef _DEBUG
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    balanced_tree bal;

    string s;
    int x;
    pair<int, bool> pairIB;
    while (cin >> s >> x) {
        switch (s[0]) {
            case 'i':
                bal.insert(x);
                break;
            case 'd':
                bal.remove(x);
                break;
            case 'e':
                cout << (bal.exists(x) ? "true" : "false") << '\n';
                break;
            case 'n':
                pairIB = bal.next(x);
                if (pairIB.second)
                    cout << pairIB.first;
                else
                    cout << "none";
                cout << '\n';
                break;
            case 'p':
                pairIB = bal.prev(x);
                if (pairIB.second)
                    cout << pairIB.first;
                else
                    cout << "none";
                cout << '\n';
                break;
            default:
                cout << "lol\n";
                break;
        }
    }

    return 0;
}