#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int q[n], pos[101010];
	int l = 0, r = 0;

	int tmp1, tmp2;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp1;

		switch (tmp1)
		{
		case 1:
			cin >> tmp2;
			pos[tmp2] = r;
			q[r] = tmp2;
			++r;
			break;
		case 2:
			++l;
			break;
		case 3:
			--r;
			break;
		case 4:
			cin >> tmp2;
			cout << (pos[tmp2] - l) << '\n';
			break;
		case 5:
			cout << q[l] << '\n';
			break;
		}
	}

	return 0;
}
