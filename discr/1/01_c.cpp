#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool sd(int size, bool *a)
{
	if (size == 1)
		return false;
	for (int i = 0; i < size / 2; ++i)
		if (a[i] == a[size - 1 - i])
			return false;
	return true;
}

bool mon(int count, bool *a)
{
	int size = (1 << count);
	for (int i = 0; i < size; ++i)
	{
		int _i = i;
		int shift = 0;
		for (int t = 0; t < count; ++t)
		{
			if (_i % 2 == 0)
				if (a[i] > a[i + (1 << shift)])
					return false;
			_i /= 2;
			++shift;
		}
	}
	return true;
}

bool lin(int count, bool *a)
{
	int size = (1 << count);
	bool g[size][size];
	for (int i = 0; i < size; ++i)
		g[0][i] = a[i];

	for (int i = 1; i < size; ++i)
		for (int j = 0; j < (size - i); ++j)
			g[i][j] = g[i - 1][j] ^ g[i - 1][j + 1];

	int t = 0;
	for (int i = 0; i < size; ++i)
		if (g[i][0])
			++t;
	for (int i = 0; i < count; ++i)
		if (g[1 << i][0])
			--t;
	if (g[0][0])
		--t;

	return (t == 0);
}

int main()
{
	bool T0, T1, S, M, L;
	T0 = T1 = S = M = L = true;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int count, size;
		cin >> count;
		size = (1 << count);
		string tmpS;
		cin >> tmpS;
		bool a[size];
		for (int j = 0; j < size; ++j)
			a[j] = (tmpS[j] == '1');

		T0 = T0 && !a[0];
		T1 = T1 && a[size - 1];
		S = S && sd(size, a);
		M = M && mon(count, a);
		L = L && lin(count, a);

		//cout << "-->" << T0 << T1 << S << M << L << endl; //
	}

	if (!T0 && !T1 && !S && !M && !L)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
