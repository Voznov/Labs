#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binSearchLeft(int x, int l, int r, int* a)
{
	if (l + 1 >= r)
		return l;
	int m = (l + r) / 2;
	if (a[m] <= x)
		return binSearchLeft(x, m, r, a);
	else
		return binSearchLeft(x, l, m, a);
}

int binSearchRight(int x, int l, int r, int* a)
{
	if (l + 1 >= r)
		return r;
	int m = (l + r) / 2;
	if (a[m] < x)
		return binSearchRight(x, m, r, a);
	else
		return binSearchRight(x, l, m, a);
}

int main()
{
	int n;
	cin >> n;

	int* a = (int*) malloc(n * sizeof(int));

	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		a[i] = x;
	}

	sort(a, a + n);

	int k;
	cin >> k;

	for (int i = 0; i < k; ++i)
	{
		int l, r;
		cin >> l >> r;
		cout << (binSearchLeft(r, -1, n, a) - binSearchRight(l, -1, n, a) + 1) << endl;
	}
	
	return 0;
}
