#include <iostream>
#include <limits>

using namespace std;

int r;

struct kek{
	long long lol[4];
	kek() {
		lol[0] = 1; lol[1] = 0;
		lol[2] = 0; lol[3] = 1;
	}
};

istream& operator>>(istream &in, kek &k) {
	in >> k.lol[0] >> k.lol[1] >> k.lol[2] >> k.lol[3];
	return in;
}

ostream& operator<<(ostream &out, kek &k) {
	out << k.lol[0] << ' ' << k.lol[1] << '\n' << k.lol[2] << ' ' << k.lol[3] << '\n';
	return out;
}

kek& operator+(kek& a, kek& b) {
	kek * result = new kek();
	result->lol[0] = (a.lol[0] * b.lol[0] + a.lol[1] * b.lol[2]) % r;
	result->lol[1] = (a.lol[0] * b.lol[1] + a.lol[1] * b.lol[3]) % r;
	result->lol[2] = (a.lol[2] * b.lol[0] + a.lol[3] * b.lol[2]) % r;
	result->lol[3] = (a.lol[2] * b.lol[1] + a.lol[3] * b.lol[3]) % r;

	return *result;
};

kek * arr;

int main() {
	freopen("crypto.in", "r", stdin);
	freopen("crypto.out", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> r >> n >> m;
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
	arr = new kek[2 * _n];

	for (int i = 0; i < _n; ++i)
		if (i < n)
			cin >> arr[i + _n - 1];

	for (int i = _n - 2; i >= 0; --i)
		arr[i] = arr[2 * i + 1] + arr[2 * i + 2];

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;

		a += _n - 2;
		b += _n - 2;
		kek resultLeft, resultRight;
		while (a < b) {
			if (a % 2 == 0)
				resultLeft = resultLeft + arr[a++];
			if (b % 2)
				resultRight = arr[b--] + resultRight;
			a = (a - 1) / 2;
			b = (b - 1) / 2;

		}
		if (a == b)
			resultLeft = resultLeft + arr[a];
		cout << resultLeft + resultRight << '\n';
	}

	return 0;
}
