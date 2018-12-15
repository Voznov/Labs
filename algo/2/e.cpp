#include <iostream>
#include <stack>

using namespace std;

int op(int a, int b, int c)
{
	switch (c)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);

	stack<int> q;

	char c;
	cin >> c;
	while (!cin.eof())
	{
		//cout << "#" << c << "#" << endl; //
		switch (c)
		{
		case ' ':
			break;
		case '+':
		case '-':
		case '*':
		{
			int b = q.top();
			q.pop();
			int a = q.top();
			q.pop();

			q.push(op(a, b, c));
			break;
		}
		default:
			q.push(c - '0');
			break;
		}
		cin >> c;
	}

	cout << q.top();

	return 0;
}
