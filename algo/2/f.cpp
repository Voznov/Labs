#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int tmp;
	queue<int> data;
	stack<int> s;
	queue<string> result;
	int lastPop = INT_MIN;

	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		data.push(tmp);
	}

	while (data.size() || s.size())
	{
		bool wasChange = false;
		while (data.size() && (s.empty() || s.top() >= data.front()))
		{
			wasChange = true;
			s.push(data.front());
			result.push("push");
			data.pop();
		}
		while (s.size() && (data.empty() || s.top() < data.front()))
		{
			if (lastPop > s.top())
			{
				cout << "impossible";
				return 0;
			}
			wasChange = true;
			lastPop = s.top();
			s.pop();
			result.push("pop");
		}
		if (!wasChange)
		{
			cout << "impossible";
			return 0;
		}
	}

	while (result.size())
	{
		cout << result.front() << '\n';
		result.pop();
	}

	return 0;
}
