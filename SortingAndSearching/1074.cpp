#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> sticks(n);
    for(int i = 0; i < n; i++) {
        cin >> sticks[i];
    }
    sort(sticks.begin(), sticks.end());
    long long median = (n % 2 == 0) ? sticks[n/2 - 1] : sticks[n/2];
    long long res = 0;
    for(int i = 0; i < n; i++) {
        res += abs(median - sticks[i]);
    }
    cout << res;
    return 0;
}