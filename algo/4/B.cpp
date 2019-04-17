#include <iostream>

using namespace std;

long long * arr;

int main() {
	int n;
	cin >> n;
	int _n = n, logn = 0;
	while (_n) {
		_n >>= 1;
		++logn;
	}
	_n = 1 << logn;
	if (2 * n == _n) {
		_n = n;
		--logn;
	}
	arr = new long long[2 * _n];

	for (int i = 0; i < _n; ++i)
		if (i < n)
			cin >> arr[i + _n - 1];
		else
			arr[i + _n - 1] = 0;

	for (int i = _n - 2; i >= 0; --i)
		arr[i] = arr[2 * i + 1] + arr[2 * i + 2];

	string s;
	while (cin >> s) {
		long long a, b;
		cin >> a >> b;
		if (s[2] == 'm') {
			a += _n - 2;
			b += _n - 2;
			long long result = 0;
			while (a < b) {
				if (a % 2 == 0)
					result += arr[a++];
				if (b % 2)
					result += arr[b--];
				a = (a - 1) / 2;
				b = (b - 1) / 2;

			}
			if (a == b)
				result += arr[a];
			cout << result << endl;
		} else {
			a += _n - 2;
			long long dx = b - arr[a];
			arr[a] = b;
			for (int i = 0; i < logn; ++i) {
				a = (a - 1) / 2;
				arr[a] += dx;
			}
		}
	}

	return 0;
}
