#include <iostream>
#include <algorithm>

using namespace std;

int n, k;

void coutArray(int *a)
{
	for (int i = 0; i < k; ++i)
		cout << a[i] << ' ';
}

int main()
{
	freopen("nextchoose.in", "r", stdin);
	freopen("nextchoose.out", "w", stdout);

	cin >> n >> k;

	int a[k];
	for (int i = 0; i < k; ++i)
		cin >> a[i];

	sort(a, a + k);

	if (a[k - 1] != n)
	{
		++a[k - 1];
		coutArray(a);
		return 0;
	}

	if (a[0] == (n - k + 1))
	{
		cout << "-1";
		return 0;
	}

	int it = k - 1;
	while (it)
		if (a[it] == a[it - 1] + 1)
			--it;
		else
			break;

	++a[--it];
	while (++it != k)
		a[it] = a[it - 1] + 1;

	coutArray(a);
	return 0;
}
