#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int a[k][n];
	int count[k];
	int totalCount = k;
	int result[n];
	for (int i = 0; i < n; ++i)
		result[i] = -1;

	int tmp;
	for (int i = 0; i < k; ++i)
	{
		count[i] = 0;
		for (int j = 0; j < n; ++j)
		{
			cin >> tmp;
			a[i][j] = tmp;
			if (tmp != -1)
				++count[i];
		}
	}

	bool wasCount1 = true;
	while (wasCount1)
	{
		//cout << "-----" << endl;
		//for (int i = 0; i < k; ++i)
		//{
		//	for (int j = 0; j < n; ++j)
		//		cout << a[i][j] << ' ';
		//	cout << '[' << count[i] << "] <--" << endl;
		//}
		wasCount1 = false;
		for (int i = 0; i < k; ++i)
			if (count[i] == 1)
				for (int j = 0; j < n; ++j)
					if (a[i][j] != -1)
					{
						result[j] = a[i][j];
						a[i][j] = -1;

						for (int ii = 0; ii < k; ++ii)
							if (count[ii] > 0)
								if (a[ii][j] != -1)
									if (a[ii][j] == result[j])
										count[ii] = 0;
									else
									{
										a[ii][j] = -1;
										--count[ii];
										if (!count[ii])
										{
											cout << "YES";
											return 0;
										}
										if (count[ii] == 1)
											wasCount1 = true;
									}
					}
	}

	cout << "NO";
	return 0;
}
