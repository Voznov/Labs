#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int mat1[101010][26], mat2[101010][26];
bool fin1[101010], fin2[101010];
bool visited1[101010], visited2[101010];

bool eqDevil(int a, int b) {
	bool a1 = true, b1 = true;
	for (int i = 0; i < 26; ++i)
		if (mat1[a][i] != -1 && mat1[a][i] != a)
			a1 = false;
	for (int i = 0; i < 26; ++i)
		if (mat2[b][i] != -1 && mat2[b][i] != b)
			b1 = false;

	return a1 == b1;
}


int main() {
#ifndef _DEBUG
	freopen("equivalence.in", "r", stdin);
	freopen("equivalence.out", "w", stdout);
#endif //_DEBUG

	int a, b;
	char c;
	int tmp;

/////////////
	int n1, m1, k1;
	cin >> n1 >> m1 >> k1;
	for (int i = 0; i < n1; ++i)
		fin1[i] = false;

	for (int i = 0; i < k1; ++i) {
		cin >> tmp;
		fin1[tmp - 1] = true;
	}

	for (int i = 0; i < n1; ++i)
		for (int j = 0; j < 26; ++j)
			mat1[i][j] = -1;

	for (int i = 0; i < m1; ++i) {
		cin >> a >> b >> c;
		mat1[a - 1][c - 'a'] = b - 1;
	}

/////////////
	int n2, m2, k2;
	cin >> n2 >> m2 >> k2;
	for (int i = 0; i < n2; ++i)
		fin2[i] = false;

	for (int i = 0; i < k2; ++i) {
		cin >> tmp;
		fin2[tmp - 1] = true;
	}

	for (int i = 0; i < n2; ++i)
		for (int j = 0; j < 26; ++j)
			mat2[i][j] = -1;

	for (int i = 0; i < m2; ++i) {
		cin >> a >> b >> c;
		mat2[a - 1][c - 'a'] = b - 1;
	}

/////////////
	bool isEq = true;
    queue<pair<int, int>> q;
	q.push({0, 0});
	while (q.size()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		if (fin1[a] != fin2[b]) {
			isEq = false;
			break;
		}

		visited1[a] = true;
		visited2[b] = true;

		for (int i = 0; i < 26; ++i) {
			int a_ = mat1[a][i];
			int b_ = mat2[b][i];
			if ((a_ == -1) != (b_ == -1)) {
				isEq = false;
				break;
			}
			if ((a_ == -1) && (b_ == -1))
				continue;
			if (!visited1[a_] || !visited2[b_])
				q.push({a_, b_});
		}
	}

	cout << (isEq ? "YES" : "NO");

	return 0;
}
