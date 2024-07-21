#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MX = LLONG_MAX;
const int M = 1000000007;

int main(void){
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];
    vector<ll> dp(x+1, MX);
    dp[0] = 0;
    for(int i = 1; i <= x; i++){
        for(int coin : coins){
            if(i - coin >= 0 && coin <= i && dp[i - coin] != MX){
                // Can we make using this coin?
                dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
    }
    cout << (dp[x] == MX? -1 : dp[x]) << endl;
    return 0;
}