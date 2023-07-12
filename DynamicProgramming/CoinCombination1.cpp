#include<iostream>
#include<vector>
#include <limits>
#define ll long long
#define fio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)

const ll max_val = std::numeric_limits<ll>::max();

ll combinations(ll no_coins, ll value, std::vector<ll> &coins){
  std::vector<ll> dp(value+1, max_val);
  dp[0] = 0;
  // Go Through Values
  for(ll val = 1; val <= value; ++val){
    // Go Through Coins
    for(ll coin = 0; coin < no_coins; ++coin){
      // Check if the coin can be used
      if( ( coins[coin] <= val ) && ( dp[val-coins[coin]] != max_val ) ){
        // If it can be used:
        dp[val] = std::min(dp[val], dp[val-coins[coin]]+1);
      }
    }
  }
  if(dp[value] == max_val){
    return -1;
  } else {
    return dp[value];
  }
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
