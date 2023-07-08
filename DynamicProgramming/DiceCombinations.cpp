#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long

const unsigned ll MOD = 1000000007;

ll dice_combinations(ll n){
  std::vector<ll> dp(n+6,0);
  ll i = 0;
  for(i = 0; i < 6; i++ ){
    dp[i] = 0;
  }
  for(i = 6; i < n+6 && i < 12; i++){
    dp[i] = 1;
  }
  for(i = 6; i < n+6; i++){
    dp[i] += (dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6])%MOD;
  }
  return dp[n+5]%MOD;
}

int main(void){
  ll n;
  std::cin>>n;
  std::cout<<dice_combinations(n);
  return 0;
}
