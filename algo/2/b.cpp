#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int l = -1, r, result = 0;

	for (int i = 0; i < n - 2; ++i)
		if ((a[i] == a[i + 1]) && (a[i + 1] == a[i + 2]))
		{
			l = i;
			break;
		}

	if (l == -1)
	{
		cout << 0;
		return 0;
	}

	r = l + 2;
	while ((r + 1 < n) && (a[r] == a[r + 1]))
		++r;

	result = r - l + 1;
	--l; ++r;

	while ((l >= 0) && (r < n) && (a[l] == a[r]))
	{
		//cout << "result=" << result << "; l=" << l << "; r=" << r << endl; //
		while ((l >= 1) && (a[l] == a[l - 1]))
			--l;
		while ((r + 1 < n) && (a[r] == a[r + 1]))
			++r;

		int result_ = r - l + 1;
		if (result + 3 > result_)
			break;

		result = result_;
		--l; ++r;
	}

	cout << result;

	return 0;
}
