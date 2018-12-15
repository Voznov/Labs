#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool sortF(pair<int, int> a, pair<int, int> b)
{
	if (a.first != b.first)
		return a.first < b.first;

	return a.second < b.second;
}

bool equalF(pair<int, int> a, pair<int, int> b)
{
	return (a.first == b.first) && (a.second == b.second);
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<pair<int, int> > a;

	for(int i = 0; i < m; ++i)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		a.push_back({tmp1, tmp2});
	}

	sort(a.begin(), a.end(), sortF);
	a.erase(unique(a.begin(), a.end(), equalF), a.end());

	bool z[n + 1];
	for (int i = 0; i < (1 << n); ++i)
	{
		int _i = i;
		for (int it = 1; it <= n; ++it)
		{
			z[it] = _i % 2;
			_i /= 2;
		}

		bool ans = true;
		for (int it = 0; it < a.size(); ++it)
		{
			int f = a[it].first, s = a[it].second;
			ans = ans && ((f < 0 ? !z[-f] : z[f]) || (s < 0 ? !z[-s] : z[s]));
		}
		if (ans)
		{
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
	return 0;
}
