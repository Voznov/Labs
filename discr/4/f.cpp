#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mat1[101010][26], mat2[101010][26];
bool fin1[101010], fin2[101010];
bool visited[101010];

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


bool dfs(int a, int b) {
	visited[a] = true;
	if (fin1[a] != fin2[b])
		return false;

	bool result = true;
	for (int i = 0; i < 26; ++i) {
		int a_ = mat1[a][i];
		int b_ = mat2[b][i];
		if ((a_ == -1) != (b_ == -1))
			return false;
		if ((a_ == -1) && (b_ == -1))
			continue;
		if (!eqDevil(a, b))
			return false;
		if (!visited[a_])
			result = result && dfs(a_, b_);
	}

	return result;
}

int main() {
#ifndef _DEBUG
	freopen("isomorphism.in", "r", stdin);
	freopen("isomorphism.out", "w", stdout);
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
	if (n1 != n2 || m1 != m2 || k1 != k2)
		cout << "NO";
	else
		cout << (dfs(0, 0) ? "YES" : "NO");

	return 0;
}
