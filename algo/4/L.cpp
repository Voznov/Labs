#include <iostream>

using namespace std;

int x1, y1, z1, x2, y2, z2;

struct kek {
	long long ***arr;
	kek(int x) {
		arr = new long long**[x];

		for (int i = 0; i < x; ++i)
			arr[i] = new long long*[x];

		for (int i = 0; i < x; ++i)
			for (int j = 0; j < x; ++j)
				arr[i][j] = new long long[x];

		for (int i = 0; i < x; ++i)
			for (int j = 0; j < x; ++j)
				for (int k = 0; k < x; ++k)
					arr[i][j][k] = 0;
	}
};

kek * arr[8];

long long heh(int lvl, int xm, int ym, int zm) {
	//cerr << "heh: lvl = " << lvl << ", xm = " << xm << ", ym = " << ym << ", zm = " << zm << endl; //
	if (lvl == 8)
		return 0;

	if (
			((xm << (7 - lvl)) >= x1) && (((xm + 1) << (7 - lvl)) <= x2) &&
			((ym << (7 - lvl)) >= y1) && (((ym + 1) << (7 - lvl)) <= y2) &&
			((zm << (7 - lvl)) >= z1) && (((zm + 1) << (7 - lvl)) <= z2) ) {
		//cerr << "heh: lvl = " << lvl << ", xm = " << xm << ", ym = " << ym << ", zm = " << zm << endl; //
		//cerr << "heh: return = " << arr[lvl]->arr[xm][ym][zm] << endl; //
		return arr[lvl]->arr[xm][ym][zm];
	}
	//cerr << "heh: in -> " << endl; //

	if (
			((xm << (7 - lvl)) >= x2) || (((xm + 1) << (7 - lvl)) <= x1) ||
			((ym << (7 - lvl)) >= y2) || (((ym + 1) << (7 - lvl)) <= y1) ||
			((zm << (7 - lvl)) >= z2) || (((zm + 1) << (7 - lvl)) <= z1) )
		return 0;
	//cerr << "heh: out -> " << endl; //

	long long sum = 0;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				sum += heh(lvl + 1, 2 * xm + i, 2 * ym + j, 2 * zm + k);

	return sum;
};

int main() {
	for (int i = 0; i < 8; ++i)
		arr[i] = new kek(1 << i);

	int n, m;
	cin >> n;

	while (cin >> m) {
		switch (m) {
		case 1:
			int x, y, z, k;
			cin >> x >> y >> z >> k;

			for (int i = 7; i >= 0; --i) {
				arr[i]->arr[x][y][z] += k;
				x >>= 1;
				y >>= 1;
				z >>= 1;
			}

			break;
		case 2:
			cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
			++x2; ++y2; ++z2;

			cout << heh(0, 0, 0, 0) << endl;

			break;
		case 3:
			return 0;
		};
	};

	return 0;
}
