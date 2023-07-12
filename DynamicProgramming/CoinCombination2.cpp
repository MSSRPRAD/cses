#include<iostream>
#include<vector>
#include <limits>
#define ll long long
#define fio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)

const ll MAX = std::numeric_limits<ll>::max();
const unsigned ll MOD = 1000000007;

ll combinations(ll no_coins, ll value, std::vector<ll> &coins){
  std::vector<ll> dp(value+1, 0);
  dp[0] = 1;
  for(ll coin = 0; coin < no_coins; coin++){
    for(ll val = 1; val <= value; val++){
      if(coins[coin] <= val){
        dp[val] += dp[val-coins[coin]]%MOD;
      }
    }
  }
  return dp[value]%MOD;
}

int main(void){

  fio;
  ll no_of_coins, value;
  std::cin>>no_of_coins>>value;
  std::vector<ll> coins(no_of_coins);
  for(ll i = 0; i < no_of_coins; i ++){
    std::cin>>coins[i];
  }
  std::cout<<combinations(no_of_coins, value, coins);
  return 0;
}
