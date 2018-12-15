#include <iostream>
#include <cmath>

using namespace std;

long long w, h, n;

bool can(long long x)
{
	return n <= (x / w) * (x / h);
}

long long binSearch(long long l, long long r)
{
	if (l + 1 >= r)
		return r;
	long long m = (l + r) / 2;
	//cout << "L: " << l << ", M: " << m << ", R: " << r << endl;
	if (can(m))
		return binSearch(l, m);
	else
		return binSearch(m, r);
}

int main()
{
	cin >> w >> h >> n;

	cout << binSearch((long long) sqrt(n) * sqrt(w) * sqrt(h) - 1, max(n * min(w, h), max(w, h)));

	return 0;
}
