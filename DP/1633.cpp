#include <bits/stdc++.h>
using namespace std;

int M = 1000000007;

int main(void){
    int n;
    cin >> n;
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    
    // Recursion:
    for(int i = 3; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            if(i-j >= 0){
                dp[i] += dp[i-j];
                dp[i] = dp[i]%M;
            }        
        }
    }

    cout << dp[n] << endl;
    return 0;
}