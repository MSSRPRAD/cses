#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long
#define fio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)

const static ll MAX = 999999999999;

ll compute(ll n, ll x, std::vector<ll> &coins){
  std::vector<ll> dp(x+1, MAX);
  dp[0] = 0;
  for(ll sum = 1; sum <= x; sum++){
    for(ll coin = 0; coin < n; coin++){
      if(coins[coin] <= sum){
        dp[sum] = std::min(dp[sum-coins[coin]]+1, dp[sum]);
      }
    }
  }
  return dp[x] == MAX? -1 : dp[x];
}

int main(void){
  fio;
  ll n, x;
  std::cin>>n>>x;
  std::vector<ll> coins(n);
  for(ll i = 0; i < n; i++){
    std::cin>>coins[i];
  }
  std::cout<<compute(n, x, coins);
  return 0;
}
