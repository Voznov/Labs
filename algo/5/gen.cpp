//
// Created by admin on 4/18/19.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int e9 = 1000000000;

bool rule(int a, int b) {
    return a > b;
}

int main() {
    freopen("test.in", "w", stdout);

    int n = 4;
    cout << n << '\n';

    srand(static_cast<unsigned int>(time(nullptr)));

    vector<int> arr(n / 3);
    for (int i = 0; i < n / 3; ++i) {
        arr[i] = rand() % e9;
        cout << "+1 " << arr[i] << '\n';
    }


    sort(arr.begin(), arr.end(), rule);
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    vector<int> v;
    for (int i = 0; i < (n - n / 3); ++i) {
        int now = rand() % arr.size();
        v.push_back(arr[now]);
        cout << "0 " << (now + 1) << '\n';
    }

    cout << "///////////////////////////////////\n";
    for (int i : v)
        cout << i << '\n';

    return 0;
}