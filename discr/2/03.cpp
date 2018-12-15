#include <iostream>

using namespace std;

int pow3(int x)
{
	int result = 1;
	while (x--)
		result *= 3;

	return result;
}

int main()
{
	freopen("antigray.in", "r", stdin);
	freopen("antigray.out", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < pow3(n - 1); ++i)
	{
		string s;
		int _i = i;
		for (int j = 0; j < (n - 1); ++j)
		{
			s = (char) ((_i % 3) + '0') + s;
			_i /= 3;
		}
		s = '0' + s;

		for (int j = 0; j < 3; ++j)
		{
			cout << s << endl;
			for (int k = 0; k < s.length(); ++k)
			{
				s[k] = (s[k] + 1 == '3' ? '0' : s[k] + 1);
			}
		}
	}

	return 0;
}
