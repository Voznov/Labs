#include <iostream>
#include <vector>

using namespace std;

int main()
{
	freopen("vectors.in", "r", stdin);
	freopen("vectors.out", "w", stdout);

	int n;
	cin >> n;

	vector<string> v;
	for (int i = 0; i < (1 << n); ++i)
	{
		string s;
		int _i = i;
		for (int j = 0; j < n; ++j)
		{
			s = (char) ((_i % 2) + '0') + s;
			_i /= 2;
		}

		bool was = false;
		for (int j = 0; j < n - 1; ++j)
			if ((s[j] == '1') && (s[j + 1] == '1'))
				was = true;

		if (!was)
			v.push_back(s);
	}

	cout << v.size() << endl;
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;

	return 0;
}
