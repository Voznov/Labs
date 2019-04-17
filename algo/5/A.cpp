#include <iostream>

using namespace std;

struct Node {
	int key;
	int height;
	Node * left = nullptr;
	Node * right = nullptr;
	Node * parent = nullptr;
	Node(int _key, Node * parent) : key(_key) {
		height = (parent ? parent->height + 1 : 0);
	}
	~Node() {
	}
#ifdef _DEBUG
	friend ostream & operator<<(ostream & out, Node & node);
#endif
};

#ifdef _DEBUG
ostream & operator<<(ostream & out, Node & node) {
	for (int i = 0; i < node.height - 1; ++i)
		out << "  ";
	if (node.height)
		out << "|_";
	out << node.key << endl;
	if (node.left)
		out << *(node.left);
	else {
		for (int i = 0; i < node.height; ++i)
			out << "  ";
		out << "|_";
		out << "null" << endl;
	}
	if (node.right)
		out << *(node.right);
	else {
		for (int i = 0; i < node.height; ++i)
			out << "  ";
		out << "|_";
		out << "null" << endl;
	}
	return out;
};

void show(Node * node, string comment = "") {
	if (node)
		cout << *node << endl;
	else
		cout << "null" << endl;
	if (comment.length())
		cout <<  "(" + comment + ")" << endl;
	cout << endl;
}
#endif

pair <Node *, Node *> search(Node * root, int key) {
	if (!root)
		return {nullptr, nullptr};
	Node * nowNode = root, * parentNode = root->parent;

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
	cin.tie(NULL);

	Node * root = nullptr;

	string s;
	int x;
	while (cin >> s >> x) {
		pair<Node *, Node *> searchResult = search(root, x);
		Node * now = searchResult.first;
		Node * parent = searchResult.second;
		switch (s[0]) {
			case 'i':
				if (!now) {
#ifdef _DEBUG
					show(now);
					show(parent);
#endif
					now = new Node(x, parent);
					if (parent)
						if (x < parent->key)
							parent->left = now;
						else
							parent->right = now;
					else
						root = now;
				}
				break;
			case 'd':
				if (now) {
					delete now;
					if (parent)
						if (x < parent->key)
							parent->left = nullptr;
						else
							parent->right = nullptr;
					else
						root = now;
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
					while (parent && (now == parent->right)) {
						now = parent;
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
					while (parent && now == parent->left) {
						now = parent;
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
#ifdef _DEBUG
			case 'x':
				show(now);
				break;
			default:
				throw "kek";
				break;
#endif
		}
	}


	return 0;
}
