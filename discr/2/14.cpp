#include <iostream>

using namespace std;

bool a[20];
long long n, k = 0;

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

int main()
{
	freopen("perm2num.in", "r", stdin);
	freopen("perm2num.out", "w", stdout);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		a[i] = false;

	int x;
	for (int i = 1; i <= n; ++i)
	{
		cin >> x;
		int count = 0;
		for (int it = 1; it < x; ++it)
			if (!a[it])
				++count;

		k += count * fac(n - i);
		//cout << "k=" << k << endl; //
		a[x] = true;
	}

	cout << k;

	return 0;
}
