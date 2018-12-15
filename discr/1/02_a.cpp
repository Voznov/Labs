#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ifstream fin = ifstream("huffman.in");
	ofstream fout = ofstream("huffman.out");

	int n;
	fin >> n;

	queue<pair<unsigned long long, unsigned long long> > q1, q2;
	int tmp;
	int forSort[n];
	for (int i = 0; i < n; ++i)
	{
		fin >> tmp;
		forSort[i] = tmp;
	}
	sort(forSort, forSort + n);
	for (int i = 0; i < n; ++i)
	{
		q1.push({forSort[i], 0});
	}

	while ((q1.size() != 0) || (q2.size() != 1))
	{
		pair<unsigned long long, unsigned long long> work[2];
		for (int i = 0; i < 2; ++i)
		{
			if (!q2.size())
			{
				work[i] = q1.front();
				q1.pop();
				continue;
			}

			if (!q1.size())
			{
				work[i] = q2.front();
				q2.pop();
				continue;
			}

			if (q1.front().first < q2.front().first)
			{
				work[i] = q1.front();
				q1.pop();
			}
			else
			{
				work[i] = q2.front();
				q2.pop();
			}
		}
		q2.push({work[0].first + work[1].first, work[0].second + work[1].second + work[0].first + work[1].first});
	}

	fout << q2.front().second;

	return 0;
}
