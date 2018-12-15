#include <iostream>

using namespace std;

bool a[20];
int n, k;

void kek(int now, int nowmax, string s)
{
	//cout << "now=" << now << "; s=" << s << endl; //
	if (!now)
	{
		cout << s.substr(1) << endl;
		return;
	}

	int nowsize = s.size() / 2;
	for (int i = nowmax + 1; i <= n; ++i)
		if (!a[i])
		{
			a[i] = true;
			kek(now - 1, i, s + " " + to_string(i));
			a[i] = false;
		}
}

int main()
{
	freopen("choose.in", "r", stdin);
	freopen("choose.out", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		a[i] = false;

	kek(k, 0, "");

	return 0;
}
