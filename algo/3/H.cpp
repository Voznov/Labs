//
// Created by admin on 12/17/18.
//

#include <iostream>
#include <climits>

using namespace std;

int n;
int range[15][15];

bool nextChoose(int *a, int n, int k) {
    if (a[k - 1] != n) {
        ++a[k - 1];
        return false;
    }

    if (a[0] == (n - k + 1)) {
        return false;
    }

    int it = k - 1;
    while (it)
        if (a[it] == a[it - 1] + 1)
            --it;
        else
            break;

    ++a[--it];
    while (++it != k)
        a[it] = a[it - 1] + 1;

    return true;
}

int checkRange(const int *resultA, int k)
{
    int result = 0;
    for (int i = 0; i < k - 1; ++i)
        result += range[resultA[i]][resultA[i + 1]];
    return result;
}

int _permutation(int now, int k, int *a, int it, int *resultA, int *mask) {
    if (!now) {
        return checkRange(resultA, k);
    }
    int result = INT_MAX;
    for (int i = 0; i < k; ++i)
        if (!a[i]) {
            a[i] = true;
            resultA[it] = mask[i];
            result = min(result, _permutation(now - 1, k, a, it + 1, resultA, mask));
            a[i] = false;
        }
    return result;
}

int permutations(int *a, int k) {
    int mask[n];
    int result[n];
    bool used[n];
    return _permutation(n, k, used, 0, result, mask);
}

int main() {
    cin >> n;
    int k = n % 2;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) { cin >> range[i][j]; }

    int result = INT_MAX;
    int a[n];
    int b[n - k];
    for (int i = 0; i < n; ++i)
        a[i] = i;
    do {
        bool was[n];
        for (int i = 0; i < n; ++i)
            was[i] = false;
        for (int i = 0; i < k; ++i)
            was[a[i]] = true;
        int it = 0;
        for (int i = 0; i < n; ++i)
            if (!was[i])
                b[it++] = i;
        result = min(result, permutations(a, k) + permutations(b, n - k) + range[a[k - 1]][]);
        // GG проебали
    } while (nextChoose(a, n, k));

    return 0;
}
