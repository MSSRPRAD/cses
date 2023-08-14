#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define ll long long
#define fio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)
long long int MOD = 1e9+7;

std::vector<std::vector<ll>> counting_towers(ll n){
  std::vector<std::vector<ll>> dp(n+1, std::vector<ll>(2, 0));
  dp[1][0] = 1;
  dp[1][1] = 1;
  for(ll i = 2; i <= n; i++){
    dp[i][0] = (2*dp[i-1][0]+dp[i-1][1])%MOD;
    dp[i][1] = (dp[i-1][0] + 4*dp[i-1][1])%MOD;
  }
  return dp;
}

int main(void){
  fio;
  ll t;
  std::cin>>t;
  std::vector<ll> inputs;
  ll max = -1;
  while(t--){
    ll n;
    std::cin>>n;
    if(max < n){max = n;}
    inputs.push_back(n);
  }
  std::vector<std::vector<ll>> dp = counting_towers(max);
  for(auto x: inputs){
    std::cout<<(dp[x][0]+dp[x][1])%MOD<<"\n";
  }
  return 0;
}
