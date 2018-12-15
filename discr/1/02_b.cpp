#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ifstream fin = ifstream("bwt.in");
	ofstream fout = ofstream("bwt.out");

	string initS;
	fin >> initS;

	int len = initS.length();
	string s[len];
	for (int i = 0; i < len; ++i)
		s[i] = initS.substr(i) + initS.substr(0, i);

	sort(s, s + len);

	for (int i = 0; i < len; ++i)
		fout << s[i][len - 1];

	return 0;
}
