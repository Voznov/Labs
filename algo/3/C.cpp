//
// Created by admin on 12/17/18.
//

#include <iostream>
#include <stack>

using namespace std;

struct A {
    int result = 0;
    int input = 0;
    int diffPrev = 0;
};

int main() {
#ifndef _DEBUG
#else
    cout << "#DEBUG" << endl;
#endif

    int n;
    cin >> n;

    A a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i].input;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j)
            if (a[j].result > a[i].result && a[j].input < a[i].input) {
                a[i].result = a[j].result;
                a[i].diffPrev = i - j;
            }
        a[i].result += 1;
    }

    int nowStep = 0;
    for (int i = 0; i < n; ++i)
        if (a[nowStep].result < a[i].result)
            nowStep = i;
    stack<int> steps;

    while (true) {
        steps.push(a[nowStep].input);
        if (!a[nowStep].diffPrev)
            break;
        nowStep -= a[nowStep].diffPrev;
    }

    cout << steps.size() << endl;

    while (!steps.empty()) {
        cout << steps.top() << ' ';
        steps.pop();
    }

    return 0;
}
