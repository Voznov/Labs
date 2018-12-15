#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ifstream fin = ifstream("mtf.in");
	ofstream fout = ofstream("mtf.out");

	string initS;
	fin >> initS;

	vector<char> v;
	for (int i = 0; i < 26; ++i)
		v.push_back('a' + i);

	for (char c : initS)
	{
		for (int j = 0; j < 26; ++j)
			if (v[j] == c)
			{
				fout << (j + 1) << ' ';
				v.erase(v.begin() + j);
				v.insert(v.begin(), c);
			}
	}

	return 0;
}
