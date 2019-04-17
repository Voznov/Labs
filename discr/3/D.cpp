#include <iostream>
#include <iomanip>

using namespace std;

const double eps = 1e-8;

double ** arr1, ** arr2;
int n;
bool isFirst = true;

void fun(double ** arr1, double ** arr2) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			arr2[i][j] = 0;
			for (int k = 0; k < n; ++k)
				arr2[i][j] += arr1[i][k] * arr1[k][j];
		}
	}
}

int main() {
#ifndef _DEBUG
	freopen("markchain.in", "r", stdin);
	freopen("markchain.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	arr1 = new double*[n];
	arr2 = new double*[n];
	for (int i = 0; i < n; ++i) {
		arr1[i] = new double[n];
		arr2[i] = new double[n];
		for (int j = 0; j < n; ++j)
			cin >> arr1[i][j];
	}

	for (int i = 0; i < 20; ++i)
		if (isFirst) {
			fun(arr1, arr2);
			isFirst = false;
		} else {
			fun(arr2, arr1);
			isFirst = true;
		}

	double b[n];
	double sum = 0;
	for (int i = 0; i < n; ++i) {
		b[i] = 0;
		for (int j = 0; j < n; ++j)
			b[i] += arr1[j][i];
		sum += b[i];
	}

	if (sum < eps)
		for (int i = 0; i < n; ++i)
			cout << setprecision(20) << ((double) 1 / n) << '\n';
	else
		for (int i = 0; i < n; ++i)
			cout << setprecision(20) << (b[i] / sum) << '\n';

	return 0;
}
