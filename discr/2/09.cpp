#include <iostream>

using namespace std;

string next(string s)
{
	int all = s.length() / 2;
	int t = -1;
	int l_, r_;
	int l = 0, r = 0;
	for (int i = 0; i < s.length(); ++i)
		if (s[i] == '(')
		{
			if (l > r)
			{
				t = i;
				l_ = l;
				r_ = r;
			}
			++l;
		}
		else
			++r;

	if (t == -1)
		return "";
	s = s.substr(0, t) + ')';
	++r_;

	for (int i = 0; i < (all - l_); ++i)
		s += '(';
	for (int i = 0; i < (all - r_); ++i)
		s += ')';

	return s;
}

int main()
{
	freopen("brackets.in", "r", stdin);
	freopen("brackets.out", "w", stdout);

	int n;
	cin >> n;

	string s;
	for (int i = 0; i < n; ++i)
		s += '(';
	for (int i = 0; i < n; ++i)
		s += ')';
	while (s.length())
	{
		cout << s << endl;
		s = next(s);
	}

	return 0;
}
