#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ifstream fin = ifstream("lzw.in");
	ofstream fout = ofstream("lzw.out");

	string initS;
	fin >> initS;

	vector<string> v;
	for (int i = 0; i < 26; ++i)
	{
		char c = 'a' + i;
		string s;
		v.push_back(s + c);
	}

	string t;
	for (int i = 0; i < initS.length(); ++i)
	{
		char c = initS[i];
		bool wasEq = false;
		for (int j = 0; j < v.size(); ++j)
			if (v[j] == (t + c))
			{
				wasEq = true;
				t += c;
				break;
			}
		if (wasEq)
			continue;
		for (int j = 0; j < v.size(); ++j)
			if (v[j] == t)
				fout << j << ' ';
		v.push_back(t + c);
		t = c;
	}
	for (int j = 0; j < v.size(); ++j)
		if (v[j] == t)
			fout << j << ' ';

	return 0;
}
