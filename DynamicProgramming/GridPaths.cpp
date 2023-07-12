#include<iostream>
#include<vector>
#include<set>
#define ll long long
#define fio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)
long long int MOD = 1e9+7;

ll paths(ll n, std::vector<std::vector<char>> &board){
  // dp[i][j] = no_of_unique_paths from board[0][0] to board[i][j] in that sub-board
  std::vector<std::vector<ll>> dp(n, std::vector<ll>(n, 0));
  // Fill first row and first column
  dp[0][0] = board[0][0] == '*' ? 0 : 1;
  // Fill the rest of the dp array
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < n; j++){
      // std::cout<<"i: "<<i<<" | j: "<<j<<"\n";
      if(board[i][j] == '.'){
        if(i > 0){
          dp[i][j] += dp[i-1][j]%MOD;
        }
        if(j > 0){
          dp[i][j] += dp[i][j-1]%MOD;
        }
      } else if(board[i][j] == '*'){
        dp[i][j] = 0;
      }
    }
  }

  return dp[n-1][n-1]%MOD;
}

int main(void){
  ll n;
  std::cin>>n;
  std::vector<std::vector<char>> board(n, std::vector<char>(n, 0));
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < n; j++){
      std::cin>>board[i][j];
    }
  }
  std::cout<<paths(n, board);
  return 0;
}
