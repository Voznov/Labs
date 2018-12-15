#include <iostream>
#include <vector>

using namespace std;

int main()
{
	freopen("nextpartition.in", "r", stdin);
	freopen("nextpartition.out", "w", stdout);

	int n;
	cin >> n;

	vector<int> v;
	char tmpC;
	int tmpI;
	while (cin >> tmpC >> tmpI)
	{
		v.push_back(tmpI);
	}

	if (v.size() == 1)
	{
		cout << "No solution";
		return 0;
	}

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

	cout << n << '=';
	bool isFirst = true;
	for (int vi : v)
	{
		cout << (isFirst ? "" : "+") << vi;
		isFirst = false;
	}
	cout << endl;

	return 0;
}
