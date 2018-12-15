#include <iostream>
#include <vector>

using namespace std;

int kek[105][105];

int main()
{
	//freopen("part2num.in", "r", stdin);
	//freopen("part2num.out", "w", stdout);

	int n = 0;

	vector<int> v;
	char tmpC;
	int tmpI;
	cin >> tmpI;
	v.push_back(tmpI);
	while (cin >> tmpC >> tmpI)
		v.push_back(tmpI);

	for(int i = 0; i < v.size(); ++i)
		n += v[i];

	for (int i = 1; i <= 100; ++i)
		for (int j = i; j <= 100; ++j)
		{
			if (i == j)
			{
				kek[j][i] = 1;
				continue;
			}

			int _i = i;
			for (int _i = 0; _i < i; ++_i)
				if (j >= 2 * _i)
					kek[j][i] += kek[j - _i][_i];
				else
					break;
		}

	int result = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		int vi = v[i];
		while (vi)
			result += kek[n][--vi];
		n -= v[i];
	}
	cout << result;

	return 0;
}
