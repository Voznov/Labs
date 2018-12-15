#include <iostream>

using namespace std;

bool a[20];
long long n, k;

long long fac(int x)
{
	long long result = 1;
	while (x)
	{
		result *= x;
		--x;
	}
	return result;
}

void kek(int now)
{
	//cout << "now=" << now << endl; //
	if (!now)
	{
		return;
	}
	long long _k = fac(now - 1);
	//cout << "k=" << k << "; _k=" << _k << endl; //
	long long x = 1;
	while (a[x])
		++x;
	while (k / _k)
	{
		k -= _k;
		++x;
		while (a[x])
			++x;
	}

	a[x] = true;
	cout << x << ' ';
	kek(now - 1);
}

int main()
{
	freopen("num2perm.in", "r", stdin);
	freopen("num2perm.out", "w", stdout);

	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
		a[i] = false;

	kek(n);

	return 0;
}
