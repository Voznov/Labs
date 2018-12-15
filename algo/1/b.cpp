#include <iostream>

using namespace std;

int main()
{
	int n;
	int a[101];
	for (int i = 0; i < 101; ++i)
		a[i] = 0;

	while (!cin.eof())
	{
		cin >> n;
		++a[n];
	}
	--a[n];

	for (int i = 0; i < 101; ++i)
		for (int j = 0; j < a[i]; ++j)
			cout << i << ' ';

	return 0;
}
