#include <iostream>

using namespace std;

int main()
{
	freopen("allvectors.in", "r", stdin);
	freopen("allvectors.out", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < (1 << n); ++i)
	{
		string s;
		int _i = i;
		for (int j = 0; j < n; ++j)
		{
			s = (char) ((_i % 2) + '0') + s;
			_i /= 2;
		}

		cout << s << endl;
	}

	return 0;
}
