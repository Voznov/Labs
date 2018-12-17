//
// Created by admin on 12/17/18.
//

#include <iostream>
#include <stack>
#include <climits>

using namespace std;

struct B {
    int result = 0;
    int diff = 0;
    bool horizontal = false;
};

int main() {
#ifndef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    cout << "#DEBUG" << endl;
#endif

    int n, m;
    cin >> n >> m;

    B a[n][m];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j].diff;

    for (int i = 0; i < n; ++i)
        for (int j = (i ? 0 : 1); j < m; ++j) {
            a[i][j].result = INT_MIN;
            if (i) {
                a[i][j].result = a[i - 1][j].result;
                a[i][j].horizontal = false;
            }

            if (j && (a[i][j].result < a[i][j - 1].result)) {
                a[i][j].result = a[i][j - 1].result;
                a[i][j].horizontal = true;
            }

            a[i][j].result += a[i][j].diff;
        }

    cout << a[n - 1][m - 1].result + a[0][0].diff << endl;

    pair<int, int> nowStep = {n - 1, m - 1};
    stack<bool> steps;

    while (true) {
        if (!(nowStep.first + nowStep.second))
            break;
        steps.push(a[nowStep.first][nowStep.second].horizontal);
        (!steps.top() ? nowStep.first : nowStep.second) -= 1;
    }

    while (!steps.empty()) {
        cout << (steps.top() ? 'R' : 'D');
        steps.pop();
    }

    return 0;
}
