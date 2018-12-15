#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int size = (1 << n);
	bool a[size][size];
	int tmpI;
	string tmpS;
	for (int i = 0; i < size; ++i)
	{
		cin >> tmpS;
		cin >> tmpI;
		a[0][i] = (tmpI == 1);
	}

	for (int i = 1; i < size; ++i)
		for (int j = 0; j < (size - i); ++j)
			a[i][j] = a[i - 1][j] ^ a[i - 1][j + 1];

	for (int i = 0; i < size; ++i)
	{
		string s = "";
		int _i = i;
		for (int j = 0; j < n; ++j)
		{
			s = (_i % 2 ? '1' : '0') + s;
			_i /= 2;
		}
		cout << s << ' ' << a[i][0] << endl;
	}

	return 0;
}
