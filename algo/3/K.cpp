//
// Created by admin on 12/19/18.
//

#include <iostream>
#include <vector>

uint n, w;

using namespace std;

class Kek {
public:
    int lifts{};
    int nowLift{};
    int prevCow{};

    Kek() = default;

    Kek(int _lifts, int _nowLift, int _prevKek)
            : lifts(_lifts), nowLift(_nowLift), prevCow(_prevKek) {}
};

bool lesss(Kek a, Kek b) {
    return a.lifts != b.lifts ? a.lifts < b.lifts : a.nowLift < b.nowLift;
}

Kek addd(Kek a, int t, int prev = -1) {
    return {a.lifts + (a.nowLift + t > w ? 1 : 0), a.nowLift + t > w ? t : a.nowLift + t, prev};
}

void writeAndClear(vector<int> & result)
{
    cout << endl << result.size();
    for (int i : result)
        cout << ' ' << (i + 1);
    result.clear();
}

int main() {
#ifndef _DEBUG
    freopen("skyscraper.in", "r", stdin);
    freopen("skyscraper.out", "w", stdin);
#else
    cerr << "DEBUG:" << endl;
#endif

    cin >> n >> w;
    int N = 1u << n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    Kek b[N];
    b[0] = {0, 0, -1};

    for (uint i = 1; i < N; ++i) {
        b[i] = {100, 0, -1};
        for (uint j = 0; j < n; ++j) {
            uint J = (1u << j);
            if (i == (i | J) && lesss(addd(b[i - J], a[j]), b[i]))
                b[i] = addd(b[i - J], a[j], j);
        }
    }

    vector<int> result;
    int now = N - 1;
    int nowLifts = b[now].lifts;
    cout << nowLifts + (b[now].nowLift > 0);

    while (now)
    {
        uint prevCow = b[now].prevCow;
        result.push_back(prevCow);
        now -= (1u << prevCow);
        if (b[now].lifts < nowLifts)
        {
            writeAndClear(result);
            nowLifts = b[now].lifts;
        }
    }
    if (!result.empty()) {
        writeAndClear(result);
    }

    return 0;
}