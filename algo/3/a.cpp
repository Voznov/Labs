#include <iostream>

using namespace std;

struct AAA;

AAA * x;

struct AAA
{
	int first;
	int second;
	AAA * aaa = nullptr;
	int count = 0;
	int it;
};

void fo(AAA * aaa)
{
	if (aaa->aaa)
		fo(aaa->aaa);
	else
		return;
	//cerr << "fo: aaa=" << aaa << "; it=" << aaa->it << endl;
	cout << aaa->it + 1 << ' ';
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, k;
	cin >> n >> k;
	AAA * x = (AAA*) malloc(sizeof(AAA) * n);
	for (int i = 0; i < n - 2; ++i)
		cin >> x[i + 1].first;
	x[0].first = 0;
	x[0].second = 0;
	x[0].it = 0;

	for (int ni = 1; ni <= n - 1; ++ni)
	{
		x[ni].it = ni;
		x[ni].second = x[ni - 1].second + x[ni - 1].first;
		x[ni].aaa = &x[ni - 1];
		x[ni].count = x[ni - 1].count + 1;
		for (int ki = 2; (ki <= k) && (ni >= ki); ++ki)
			if (x[ni].second < x[ni - ki].second + x[ni - ki].first)
			{
				x[ni].second = x[ni - ki].second + x[ni - ki].first;
				x[ni].aaa = &x[ni - ki];
				x[ni].count = x[ni - ki].count + 1;
				//cerr << "ni=" << ni << "; ki=" << ki << "; second=" << x[ni].second << "; first=" << x[ni].first << "; count=" << x[ni].count << endl;
			}
	}

	cout << x[n - 1].second << endl;
	cout << x[n - 1].count << endl;
	fo(&x[n - 1]);

	return 0;
}
