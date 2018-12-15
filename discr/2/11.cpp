#include <iostream>

using namespace std;

bool a[15];
int n;

void kek(int i)
{
	if (i > n)
		return;

	a[i] = true;
	for (int j = 1; j <= n; ++j)
		if (a[j])
			cout << j << ' ';
	cout << endl;
	kek(i + 1);
	a[i] = false;
	kek(i + 1);
}

int main()
{
	freopen("subsets.in", "r", stdin);
	freopen("subsets.out", "w", stdout);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		a[i] = false;

	cout << endl;
	kek(1);

	return 0;
}
