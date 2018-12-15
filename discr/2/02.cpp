#include <iostream>

using namespace std;

int main()
{
	freopen("gray.in", "r", stdin);
	freopen("gray.out", "w", stdout);

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

		bool was = false;
		for (int j = 0; j < n; ++j)
		{
			int i = (x % (1 << (j + 1))) / (1 << j);
			int x_ = x + (i ? -(1 << j) : (1 << j));
			if (a[x_] == false)
			{
				was = true;
				x = x_;
				break;
			}
		}

		if (!was)
			return 0;
	}

	return 0;
}
