#include <iostream>

using namespace std;

int a[15];
int n, k;

void kek(int i, int nowCount)
{
	if (nowCount > k)
		return;
	if (i > n)
	{
		if (nowCount != k)
			return;
		for (int j = 1; j <= k; ++j)
		{
			bool was = false;
			for (int t = 1; t <= n; ++t)
				if (a[t] == j)
				{
					was = true;
					break;
				}
			if (!was)
				return;
		}

		for (int j = 1; j <= k; ++j)
		{
			for (int t = 1; t <= n; ++t)
				if (a[t] == j)
					cout << t << ' ';
			cout << endl;
		}
		cout << endl;
		return;
	}

	for (int j = 1; j <= nowCount; ++j)
	{
		a[i] = j;
		kek(i + 1, nowCount);
	}
	a[i] = nowCount + 1;
	kek(i + 1, nowCount + 1);
}

int main()
{
	freopen("part2sets.in", "r", stdin);
	freopen("part2sets.out", "w", stdout);

	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
		a[i] = 0;

	kek(1, 0);

	return 0;
}
