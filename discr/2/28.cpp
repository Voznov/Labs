#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	freopen("nextmultiperm.in", "r", stdin);
	freopen("nextmultiperm.out", "w", stdout);

	int n;
	cin >> n;

	vector<int> v;
	int tmp;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	bool was = false;
	for (int i = v.size() - 1; i >= 1; --i)
		if (v[i] > v[i - 1])
		{
			int x = v[i - 1];
			vector<int> tmp;
			while (v.size() > i - 1)
			{
				tmp.push_back(v.back());
				v.pop_back();
			}
			sort(tmp.begin(), tmp.end());
			for (int j = 0; j < tmp.size(); ++j)
				if (tmp[j] > x)
				{
					v.push_back(tmp[j]);
					for (int k = 0; k < j; ++k)
						v.push_back(tmp[k]);
					for (int k = j + 1; k < tmp.size(); ++k)
						v.push_back(tmp[k]);
					break;
				}
			was = true;
			break;
		}

	for (int i = 0; i < v.size(); ++i)
		cout << (was ? v[i] : 0) << ' ';
	cout << endl;

	return 0;
}
