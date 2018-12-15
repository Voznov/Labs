#include <iostream>

using namespace std;

int main()
{
	freopen("chaincode.in", "r", stdin);
	freopen("chaincode.out", "w", stdout);

	int n;
	cin >> n;

	bool a[1 << n];
	for (int i = 0; i < (1 << n); ++i)
		a[i] = false;

	int x = 0;
	while (true)
	{
		string s;
		int _x = x;
		for (int j = 0; j < n; ++j)
		{
			s = (char) ((_x % 2) + '0') + s;
			_x /= 2;
		}

		cout << s << endl;

		a[x] = true;

		x *= 2;
		x %= (1 << n);
		if (!a[x + 1])
			++x;
		else
			if (a[x])
				return 0;
	}

	return 0;
}
