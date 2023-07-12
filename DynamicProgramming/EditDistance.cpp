#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define ll long long
#define fio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)
long long int MOD = 1e9+7;

ll edit_distance_rec(ll i, ll j, std::string str1, std::string str2, std::vector<std::vector<ll>> &memo){
  if(i == str1.size()){
    return str2.size()-j;
  } else if( j == str2.size()){
    return str1.size()-i;
  }
  if(memo[i][j] != -1) return memo[i][j];
  if(str1[i] == str2[j]){
      memo[i][j] = edit_distance_rec(i+1, j+1, str1, str2, memo);
      return memo[i][j];
  } else {
    // Do Operations
    // Replace str1[i] with str2[j] or vice verse
    ll rep = edit_distance_rec(i+1, j+1, str1, str2, memo)+1;
    ll del = edit_distance_rec(i+1, j, str1, str2, memo)+1;
    ll add = edit_distance_rec(i, j+1, str1, str2, memo)+1;
    memo[i][j] = std::min(std::min(rep, del), add);
    return memo[i][j];
  }
}

ll edit_distance(std::string str1, std::string str2){
  ll len1 = str1.size();
  ll len2 = str2.size();
  std::vector<std::vector<ll>> dp(len1+1, std::vector<ll>(len2+1, 0));
  for(ll i = len1; i > -1; i--){
    for(ll j = len2; j > -1; j--){
      if(i == len1){
        dp[i][j] = len2-j;
      } else if (j == len2) {
        dp[i][j] = len1-i;
      } else if(str1[i] == str2[j]) {
        dp[i][j] = dp[i+1][j+1];
      } else {
        ll rep = dp[i+1][j+1];
        ll del = dp[i+1][j];
        ll add = dp[i][j+1];
        dp[i][j] = std::min(std::min(rep, del), add)+1;
      }
    }
  }
  return dp[0][0];
}

int main(void){
  fio;
  std::string str1;
  std::string str2;
  std::cin>>str1;
  std::cin>>str2;
  std::vector<std::vector<ll>> memo(str1.size(), std::vector<ll>(str2.size(), -1));
  std::cout<<edit_distance(str1, str2);
  return 0;
}
