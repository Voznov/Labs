#include <iostream>

using namespace std;

bool a[10];
int n;

void kek(int now, string s)
{
	//cout << "now=" << now << "; s=" << s << endl; //
	if (!now)
		cout << s.substr(1) << endl;
	for (int i = 1; i <= n; ++i)
		if (!a[i])
		{
			a[i] = true;
			kek(now - 1, s + " " + (char) (i + '0'));
			a[i] = false;
		}
}

int main()
{
	freopen("permutations.in", "r", stdin);
	freopen("permutations.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		a[i] = false;

	kek(n, "");

	return 0;
}
