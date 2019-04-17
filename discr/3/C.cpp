#include <iostream>
#include <iomanip>

using namespace std;

int main() {
#ifndef _DEBUG
	freopen("lottery.in", "r", stdin);
	freopen("lottery.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	double mo = 0;
	int a, b;
	double a_all = 1;
	double _b = 0;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		a_all *= a;
		mo += (b - _b) / a_all;
		_b = b;
	}

	cout << setprecision(20) << n - mo;

	return 0;
}
