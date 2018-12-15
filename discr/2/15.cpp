#include <iostream>

using namespace std;

int n, k, m = 0;
long long cnk[35][35];

int main()
{
	freopen("num2choose.in", "r", stdin);
	freopen("num2choose.out", "w", stdout);

	cin >> n >> k >> m;
	for (int i = 0; i <= 30; ++i)
		cnk[i][0] = cnk[i][i] = 1;

	for (int i = 1; i <= 30; ++i)
		for (int j = 1; j < i; ++j)
			cnk[i][j] = cnk[i - 1][j] + cnk[i - 1][j - 1];

	int x = 1;
	for (int i = 0; i < k; ++i)
	{
		//cout << endl << "x=" << x << "; i=" << i << "; m=" << m << endl; //
		while (m >= cnk[n - x][k - i - 1])
		{
			//cout << "cnk[n - x][k - i - 1]=" << cnk[n - x][k - i - 1] << endl;
			m -= cnk[n - x][k - i - 1];
			++x;
		}
		cout << x << ' ';
		++x;
	}

	return 0;
}
