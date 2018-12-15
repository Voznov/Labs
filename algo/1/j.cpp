#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

const double eps = 10e-10;

double a, vp, vf;

double f(double x)
{
	return sqrt(x * x + (1 - a) * (1 - a)) / vp + sqrt((1 - x) * (1 - x) + a * a) / vf;
}

double binSearch(double l, double r)
{
	if ((r - l) < eps)
		return l;

	double ml = (r + 2 * l) / 3;
	double mr = (l + 2 * r) / 3;
	if (ml == mr)
		return ml;

	//cout << "L: " << l << ", ML: " << ml << ", MR: " << mr << ", R: " << r << endl;

	if (f(ml) < f(mr))
		return binSearch(l, mr);
	else
		return binSearch(ml, r);
}

int main()
{
	cin >> vp >> vf >> a;

	cout << setprecision(15) << binSearch(0, 1);
	
	return 0;
}
