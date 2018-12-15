#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

const double eps = 10e-8;

double f(double x)
{
	return x * x + sqrt(x);
}

double binSearch(double x, double l, double r)
{
	if ((r - l) < eps)
		return l;

	double m = (l + r) / 2;
	if (l == m || m == r)
		return m;

	//cout << "L: " << l << ", M: " << m << ", R: " << r << endl;

	if (f(m) > x)
		return binSearch(x, l, m);
	else
		return binSearch(x, m, r);
}

int main()
{
	double c;
	cin >> c;

	cout << setprecision(15) << binSearch(c, 0, c);
	
	return 0;
}
