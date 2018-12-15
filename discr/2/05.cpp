#include <iostream>
#include <vector>

using namespace std;

vector<string> kek(int n, int k)
{
	vector<string> result;
	if (!n)
	{
		result.push_back("");
		return result;
	}

	vector<string> _result = kek(n - 1, k);

	for (int i = 0; i < k; ++i)
		for (int j = 0; j < _result.size(); ++j)
			result.push_back(_result[i % 2 ? _result.size() - 1 - j : j] + (char) ('0' + i));

	return result;
}

int main()
{
	freopen("telemetry.in", "r", stdin);
	freopen("telemetry.out", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	vector<string> result = kek(n, k);

	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << endl;

	return 0;
}
