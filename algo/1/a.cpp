#include <iostream>

using namespace std;

int* a;

void qsort(int left, int right)
{
	int m = (right + left) / 2;
	int x = a[m];
	int l = left, r = right;

	while (l < r)
	{
		while (a[l] < x)
			++l;
		while (a[r] > x)
			--r;
		if (l <= r)
		{
			swap(a[l], a[r]);
			++l;
			--r;
		}
	}
	if (left < r)
		qsort(left, r);
	if (l < right)
		qsort(l, right);
}

int main()
{
	int n;
	cin >> n;

	a = (int*) malloc(n * sizeof(int));

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	qsort(0, n - 1);

	for (int i = 0; i < n; ++i)
		cout << a[i] << ' ';

	return 0;
}
