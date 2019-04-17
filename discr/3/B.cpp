#include <iostream>
#include <iomanip>

using namespace std;

double pow(double x, int a) {
	double result = 1;
	for (int i = 0; i < a; ++i)
		result *= x;
	return result;
}

int main() {
#ifndef _DEBUG
	freopen("shooter.in", "r", stdin);
	freopen("shooter.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	double mo = 0;
	double mo_k, p;

	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> p;
		mo += pow(1 - p, m);

		if (i == k - 1)
			mo_k = pow(1 - p, m);
	}

	cout << setprecision(20) << mo_k / mo;

	return 0;
}
