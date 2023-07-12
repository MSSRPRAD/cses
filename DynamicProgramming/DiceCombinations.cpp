#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long

const unsigned ll MOD = 1000000007;

ll ans = 0;
// TLE
void compute(ll left){
  if(left == 0){
    ans += 1;
  } else {
    for(ll i = 1; i <= 6; i++){
      if(left-i>=0){
        compute(left-i);
      }
    }
  }
}

// DP
ll compute_dp(ll n){
  std::vector<ll> dp(n+1);
  dp[0] = 1;
  for(ll sum = 1; sum <= n; sum++){
    for(ll i = 1; i <= 6; i++){
      if(sum - i >= 0){
        dp[sum] += dp[sum-i]%MOD;
      }
    }
  }
  return dp[n]%MOD;
}

int main(void){
  ll n;
  std::cin>>n;
  std::cout<<compute_dp(n);
  return 0;
}
