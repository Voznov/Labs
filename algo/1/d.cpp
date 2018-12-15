#include <iostream>

using namespace std;

int a[100000];
int size = 0;

void push(int x)
{
	int i = size;
	int p = (i - 1) / 2;
	a[size++] = x;

	while ((i > 0) && (a[i] > a[p]))
	{
		swap(a[i], a[p]);
		i = p;
		p = (i - 1) / 2;
	}
}

int pop()
{
	int result = a[0];
	a[0] = a[--size];
	
	int i = 0;
	while (true)
	{
		int li = 2 * i + 1;
		int ri = 2 * i + 2;
		int l = (li < size ? a[li] : 0);
		int r = (ri < size ? a[ri] : 0);

		int maxci = (l > r ? li : ri);
		int maxc = (l > r ? l : r);

		if (a[i] < maxc)
		{
			swap(a[i], a[maxci]);
			i = maxci;
		}
		else
			break;
	}
	return result;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int com;
		cin >> com;
		if (com)
			cout << pop() << endl;
		else
		{
			int x;
			cin >> x;
			push(x);
		}
	}

	return 0;
}
