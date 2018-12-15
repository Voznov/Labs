#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	stack<pair<int, int> > q;
	int n;
	cin >> n;

	int tmp1, tmp2;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp1;

		switch (tmp1)
		{
		case 1:
			cin >> tmp2;
			q.push({tmp2, q.size() ? min(tmp2, q.top().second) : tmp2});
			break;
		case 2:
			q.pop();
			break;
		case 3:
			cout << q.top().second << '\n';
			break;
		}
	}

	return 0;
}
