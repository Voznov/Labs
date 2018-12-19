//
// Created by admin on 12/17/18.
//

#include <iostream>

using namespace std;

const long long mod = 1000 * 1000 * 1000;

int main()
{
    int n;
    cin >> n;

    long long a[n + 1][10];
    for (int i = 0; i < 10; ++i)
        a[1][i] = ((i == 8) || !i ? 0 : 1);

    for (int i = 2; i <= n; ++i)
    {
        a[i][0] = a[i - 1][4] + a[i - 1][6];
        a[i][1] = a[i - 1][6] + a[i - 1][8];
        a[i][2] = a[i - 1][7] + a[i - 1][9];
        a[i][3] = a[i - 1][4] + a[i - 1][8];
        a[i][4] = a[i - 1][0] + a[i - 1][3] + a[i - 1][9];
        a[i][5] = 0;
        a[i][6] = a[i - 1][0] + a[i - 1][1] + a[i - 1][7];
        a[i][7] = a[i - 1][2] + a[i - 1][6];
        a[i][8] = a[i - 1][1] + a[i - 1][3];
        a[i][9] = a[i - 1][2] + a[i - 1][4];

        for (int j = 0; j < 10; ++j)
            a[i][j] %= mod;
    }

    long long result = 0;
    for (int i = 0; i < 10; ++i)
        result += a[n][i];

    cout << (result % mod);

    return 0;
}
