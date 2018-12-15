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

	int k;
	cin >> k;

	int* a = (int*) malloc(n * sizeof(int));

	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		a[i] = x;
	}

	sort(a, a + n);

	for (int i = 0; i < k; ++i)
	{
		int x;
		cin >> x;
		int xL = a[max(0, binSearchLeft(x, -1, n, a))];
		int xR = a[min(n - 1, binSearchRight(x, -1, n, a))];

		cout << (x - xL > xR - x ? xR : xL) << endl;
	}
	
	return 0;
}
