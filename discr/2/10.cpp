#include <iostream>
#include <vector>

using namespace std;

int main()
{
	freopen("partition.in", "r", stdin);
	freopen("partition.out", "w", stdout);

	int n;
	cin >> n;

	vector<int> v(n, 1);

	while (true)
	{
		bool isFirst = true;
		for (int vi : v)
		{
			cout << (isFirst ? "" : "+") << vi;
			isFirst = false;
		}
		cout << endl;

		if (v.size() == 1)
			return 0;

		int left = v[v.size() - 2], right = v[v.size() - 1];
		v.pop_back();
		v.pop_back();

		if (left + 1 <= right - 1)
		{
			++left;
			--right;
			v.push_back(left);
			while (right >= 2 * left)
			{
				v.push_back(left);
				right -= left;
			}
			v.push_back(right);
		}
		else
			v.push_back(left + right);
	}

	return 0;
}
