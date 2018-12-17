//
// Created by admin on 12/17/18.
//

#include <iostream>
#include <stack>

using namespace std;

struct A {
    int result = 0;
    int diff = 0;
    int diffPrev = 0;
};

int main() {
#ifndef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    cout << "#DEBUG" << endl;
#endif

    int n, k;
    cin >> n >> k;

    A a[n];
    for (int i = 1; i < n - 1; ++i)
        cin >> a[i].diff;

    for (int i = 1; i < n; ++i) {
        a[i].result = a[i - 1].result;
        a[i].diffPrev = 1;
        for (int j = 2; (j <= k) && (j <= i); ++j)
            if (a[i - j].result > a[i].result) {
                a[i].result = a[i - j].result;
                a[i].diffPrev = j;
            }
        a[i].result += a[i].diff;
    }

    cout << a[n - 1].result << endl;

    int nowStep = n - 1;
    stack<int> steps;

    while (true) {
        steps.push(nowStep + 1);
        if (!nowStep)
            break;
        nowStep -= a[nowStep].diffPrev;
    }

    cout << steps.size() - 1 << endl;

    while (!steps.empty()) {
        cout << steps.top() << ' ';
        steps.pop();
    }

    return 0;
}
