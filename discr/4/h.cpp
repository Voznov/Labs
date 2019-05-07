#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool rule(unordered_set<int> * a, unordered_set<int> * b) {
	return (a->find(0) != a->end());
}

bool emptyV(unordered_set<int> * a) {
	return (*a).empty();
}

int main() {
#ifndef _DEBUG
	freopen("minimization.in", "r", stdin);
	freopen("minimization.out", "w", stdout);
#endif //_DEBUG

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
	vector<int> Inv[n][26];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 26; ++j)
			mat[i][j] = -1;

	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		mat[a - 1][c - 'a'] = b - 1;
		Inv[b - 1][c - 'a'].push_back(a - 1);
	}

	vector<unordered_set<int>*> P;
	int Class[n];

	unordered_set<int>* finSet = new unordered_set<int>;
	unordered_set<int>* nfinSet = new unordered_set<int>;
	for (int i = 0; i < n; ++i)
		if(fin[i]) {
			finSet->insert(i);
			Class[i] = 0;
		}
		else {
			nfinSet->insert(i);
			Class[i] = 1;
		}
	P.push_back(finSet);
	P.push_back(nfinSet);

	queue<pair<int, int>> Queue;
	for (int i = 0; i < 26; ++i) {
		Queue.push({0, i});
		Queue.push({1, i});
	}

	while (Queue.size()) {
		pair<int, int> now = Queue.front();
		Queue.pop();

		map<int, vector<int>> Involved;
		for (int q : *(P[now.first]))
			for (int r : Inv[q][now.second]) {
				int i = Class[r];
				Involved[i].push_back(r);
			}
		for (auto i : Involved)
			if (i.second.size() < P[i.first]->size()) {
				int j = P.size();
				P.push_back(new unordered_set<int>);
				for (int r : i.second) {
					P[i.first]->erase(r);
					P[j]->insert(r);
				}
				if (P[j]->size() > P[i.first]->size())
					swap(P[i.first], P[j]);
				for (int r : *(P[j]))
					Class[r] = j;
				for (int c = 0; c < 26; ++c)
					Queue.push({j, c});
			}
	}

	P.erase(remove_if(P.begin(), P.end(), emptyV), P.end());
	sort(P.begin(), P.end(), rule);
    for (int i = 0; i < P.size(); ++i)
        for (int x : *(P[i]))
        	Class[x] = i;

	int newN = P.size(), newM = 0, newK = 0;
	bool newfin[newN];
	for (int i = 0; i < newN; ++i)
		newfin[i] = false;
	int newmat[newN][26];
	for (int i = 0; i < newN; ++i)
		for (int j = 0; j < 26; ++j)
			newmat[i][j] = -1;

	int firstE[newN];
	for (auto x : P) {
		int xx = *(x->begin());
		int num = Class[xx];
		if (fin[xx]) {
			++newK;
			newfin[num] = true;
		}
		for (int i = 0; i < 26; ++i)
			if (mat[xx][i] != -1) {
				++newM;
				newmat[num][i] = Class[mat[xx][i]];
			}
	}

	cout << newN << ' ' << newM << ' ' << newK << endl;
	for (int i = 0; i < newN; ++i)
		if (newfin[i])
			cout << (i + 1) << ' ';
	cout << endl;
	for (int i = 0; i < newN; ++i)
		for (int j = 0; j < 26; ++j)
			if (newmat[i][j] != -1)
				cout << (i + 1) << ' ' << (newmat[i][j] + 1) << ' ' << (char) (j + 'a') << endl;

	return 0;
}
