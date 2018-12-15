#include <iostream>

using namespace std;

int main()
{
	freopen("nextvector.in", "r", stdin);
	freopen("nextvector.out", "w", stdout);

	string s;
	cin >> s;

	bool has1 = false;
	for (int i = 0; i < s.length(); ++i)
		if (s[i] == '1')
			has1 = true;

	if (!has1)
		cout << '-' << endl;
	else
	{
		string _s(s);
		for (int i = s.length() - 1; i >= 0; --i)
			if (_s[i] == '1')
			{
				for (int j = s.length() - 1; j > i; --j)
					_s[j] = '1';
				_s[i] = '0';
				break;
			}
		cout << _s << endl;
	}

	bool has0 = false;
	for (int i = 0; i < s.length(); ++i)
		if (s[i] == '0')
			has0 = true;

	if (!has0)
		cout << '-' << endl;
	else
	{
		string _s(s);
		for (int i = s.length() - 1; i >= 0; --i)
			if (_s[i] == '0')
			{
				for (int j = s.length() - 1; j > i; --j)
					_s[j] = '0';
				_s[i] = '1';
				break;
			}
		cout << _s << endl;
	}

	return 0;
}
