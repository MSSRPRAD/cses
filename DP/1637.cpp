#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MX = LLONG_MAX;
const int M = 1000000007;

int main(void)
{
    int n;
    cin >> n;
    vector<int> dp(n+1, INT_MAX-1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++){

        // Get all digits of the number
        string i_s = to_string(i);
        unordered_set<int> digits;
        for(char c : i_s){
            digits.insert((c-'0'));
        }

        // Check in dp
        for(int d : digits){
            dp[i] = min(dp[i],dp[i-d]+1);
        }
    }
    cout << dp[n];
    return 0;
}