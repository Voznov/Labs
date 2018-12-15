#include <iostream>

using namespace std;

int main()
{
	int n, x, y;
	cin >> n >> x >> y;

	if (x > y)
		swap(x, y);

	int result = x;
	--n;

	result += x * y * (n / (x + y));
	n %= (x + y);

	if (!n)
	{
		cout << result;
		return 0;
	}

	int xresult = 0, yresult = 0;
	while (xresult + yresult < n)
		if (xresult * x <= yresult * y)
			++xresult;
		else
			++yresult;
	
	cout << result + max(xresult * x, yresult * y);

	return 0;
}
