#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
#ifndef _DEBUG
	freopen("problem1.in", "r", stdin);
	freopen("problem1.out", "w", stdout);
#endif //_DEBUG

	string s;
	cin >> s;
	int n, m, k;
	cin >> n >> m >> k;
	bool fin[n];
	for (int i = 0; i < n; ++i)
		fin[i] = false;

	int tmp;
	for (int i = 0; i < k; ++i) {
		cin >> tmp;
		fin[tmp - 1] = true;
	}

	int a, b;
	char c;

	int mat[n][26];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 26; ++j)
			mat[i][j] = -1;

	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		mat[a - 1][c - 'a'] = b - 1;
	}

	int now = 0;
	for (int i = 0; i < s.length(); ++i) {
		int symb = s[i] - 'a';
		if (mat[now][symb] == -1) {
			cout << "Rejects";
			return 0;
		}
		now = mat[now][symb];
	}
	if (fin[now])
		cout << "Accepts";
	else
		cout << "Rejects";

	return 0;
}
