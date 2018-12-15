#include <iostream>
#include <string>

using namespace std;

const int sizeInt = 33;
int main()
{
	int n;
	cin >> n;

	bool a[sizeInt][n + 1];

	unsigned int tmp;
	for (int i = 1; i <= n; ++i)
	{
		cin >> tmp;
		for (int j = 0; j < sizeInt; ++j)
		{
			a[j][i] = (tmp % 2);
			tmp /= 2;
		}
	}

	cin >> tmp;
	if (!tmp)
	{
		cout << "1&~1";
		return 0;
	}

	for (int j = 0; j < sizeInt; ++j)
	{
		a[j][0] = (tmp % 2);
		tmp /= 2;
	}

	for (int i = 0; i < sizeInt - 1; ++i)
		for (int j = i + 1; j < sizeInt; ++j)
			if (a[i][0] != a[j][0])
			{
				bool same = true;
				for (int k = 1; k <= n; ++k)
					if (a[i][k] != a[j][k])
						same = false;
				if (same)
				{
					cout << "Impossible";
					return 0;
				}
			}

	bool isNotFirst = false;
	for (int i = 0; i < sizeInt - 1; ++i)
		if (a[i][0])
		{
			cout << (isNotFirst ? "|" : "") << "(";
			for (int j = 1; j <= n; ++j)
				cout << (j != 1 ? "&" : "") << (a[i][j] ? "" : "~") << to_string(j);
			cout << ")";
			isNotFirst = true;
		}

	return 0;
}

