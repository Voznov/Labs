#include <iostream>

using namespace std;

int n, k, m = 0;
long long cnk[35][35];

int main()
{
	freopen("choose2num.in", "r", stdin);
	freopen("choose2num.out", "w", stdout);

	cin >> n >> k;
	for (int i = 0; i <= 30; ++i)
		cnk[i][0] = cnk[i][i] = 1;

	for (int i = 1; i <= 30; ++i)
		for (int j = 1; j < i; ++j)
			cnk[i][j] = cnk[i - 1][j] + cnk[i - 1][j - 1];

	int _x, x = 1;
	for (int i = 0; i < k; ++i)
	{
		cin >> _x;
		while (x < _x)
		{
			m += cnk[n - x][k - i - 1];
			++x;
		}
		++x;
	}

	cout << m;

	return 0;
}
