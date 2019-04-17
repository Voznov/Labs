#include <iostream>

using namespace std;

int main() {
#ifndef _DEBUG
	freopen("exam.in", "r", stdin);
	freopen("exam.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k, n;
	cin >> k >> n;

	int mo = 0, p, m;
	for (int i = 0; i < k; ++i) {
		cin >> p >> m;
		mo += p * m;
	}

	cout << ((double) mo / 100 / n);

	return 0;
}
