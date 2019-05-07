#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
#ifndef _DEBUG
	freopen("problem2.in", "r", stdin);
	freopen("problem2.out", "w", stdout);
#endif //_DEBUG

	string s;
	cin >> s;
	int s_len = s.length();
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

	vector<int> mat[n][26];

	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		mat[a - 1][c - 'a'].push_back(b - 1);
	}

	bool can[s_len + 1][n];
	for (int i = 0; i < s_len + 1; ++i)
		for (int j = 0; j < n; ++j)
			can[i][j] = false;
	can[0][0] = true;

	for (int i = 0; i < s_len; ++i) {
		int symb = s[i] - 'a';
		for (int j = 0; j < n; ++j) {
			if (!can[i][j])
				continue;
			for (int k : mat[j][symb])
				can[i + 1][k] = true;
		}
	}
	for (int i = 0; i < n; ++i)
		if (can[s_len][i] && fin[i]) {
			cout << "Accepts";
			return 0;
		}
	cout << "Rejects";

	return 0;
}
