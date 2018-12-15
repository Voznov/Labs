#include <iostream>

using namespace std;

string heh(char *s, int length)
{
	cerr << "length=" << length << endl; //
	int all = length / 2;
	int t = -1;
	int l_, r_;
	int l = 0, r = 0;
	for (int i = 0; i < length; ++i)
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

	cerr << "length=" << length << endl; //
	if (t == -1)
		return "-";
	length = t;
	s[length++] = ')';
	++r_;

	for (int i = 0; i < (all - l_); ++i)
		s[length++] = '(';
	for (int i = 0; i < (all - r_); ++i)
		s[length++] = ')';

	cerr << "length=" << length << endl; //
	return string(s, length);
}

int main()
{
	freopen("nextbrackets.in", "r", stdin);
	freopen("nextbrackets.out", "w", stdout);

	string s;
	cin >> s;
	cerr << "s.length()=" << s.length() << endl; //
	cerr << "s.c_str()=" << s.c_str() << endl; //
	string result = heh((char*) s.c_str(), s.length());
	cout << result;

	return 0;
}
