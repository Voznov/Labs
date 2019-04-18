#include <iostream>

using namespace std;

struct Node {
    int key;
    int height;
    Node *left = nullptr;
    Node *right = nullptr;
    Node *parent = nullptr;

    Node(int _key, Node *_parent) : key(_key), parent(_parent) {
        height = (parent ? parent->height + 1 : 0);
        if (_parent)
            (_key < parent->key ? parent->left : parent->right) = this;
    }

    ~Node() = default;

    Node *remove() {
        if (left && right) {
            Node *now = right;
            while (now->left)
                now = now->left;
            swap(key, now->key);
            now->remove();
            return this;
        } else {
            Node *child = (left ? left : right);
            if (parent)
                (this == parent->left ? parent->left : parent->right) = child;
            if (child)
                child->parent = parent;
            delete this;
            return child;
        }
    }
};

pair<Node *, Node *> search(Node *root, int key) {
    if (!root)
        return {nullptr, nullptr};
    Node *nowNode = root, *parentNode = root->parent;

    while (nowNode && nowNode->key != key) {
        parentNode = nowNode;
        if (key < nowNode->key)
            nowNode = nowNode->left;
        else
            nowNode = nowNode->right;
    }
    return {nowNode, parentNode};
};

int main() {
#ifndef _DEBUG
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Node *root = nullptr;

    string s;
    int x;
    while (cin >> s >> x) {
        pair<Node *, Node *> searchResult = search(root, x);
        Node *now = searchResult.first;
        Node *parent = searchResult.second;
        switch (s[0]) {
            case 'i':
                if (!now) {
                    now = new Node(x, parent);
                    if (!parent)
                        root = now;
                }
                break;
            case 'd':
                if (now) {
                    Node *result = now->remove();
                    if (!parent)
                        root = result;
                }
                break;
            case 'e':
                cout << (now ? "true" : "false") << endl;
                break;
            case 'n':
                if (now && now->right) {
                    now = now->right;
                    while (now->left)
                        now = now->left;
                } else {
                    while (parent && (x > parent->key)) {
                        parent = parent->parent;
                    }
                    now = parent;
                }
                if (now)
                    cout << now->key;
                else
                    cout << "none";
                cout << endl;
                break;
            case 'p':
                if (now && now->left) {
                    now = now->left;
                    while (now->right)
                        now = now->right;
                } else {
                    while (parent && x < parent->key) {
                        parent = parent->parent;
                    }
                    now = parent;
                }
                if (now)
                    cout << now->key;
                else
                    cout << "none";
                cout << endl;
                break;
            default:
                break;
        }
    }


    return 0;
}
