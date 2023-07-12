#include<iostream>
#include<vector>
#include<set>
#define ll int
#define fio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)
long long int MOD = 1e9+7;

ll max_pages(ll no_books, ll total, std::vector<ll> &prices, std::vector<ll> &pages){
  std::vector<std::vector<ll>> dp(no_books, std::vector<ll>(total+1, 0));
  // dp[1][0] = prices[0] > 1 ? 0 : 1;
  // dp[i][j] = max_pages with j price and books 0th through ith
  for(ll book = 0; book < no_books; book++){
    for(ll amt = 1; amt <= total; amt++){
      if(amt < prices[book] && book > 0){
        // Can't use the book
        dp[book][amt] = dp[book-1][amt];
      } else if(book > 0) {
        // Max of:
        // 1. Max Pages without this book's pages
        // 2. Max Pages with this book's pages
        dp[book][amt] = std::max(dp[book-1][amt], dp[book-1][amt-prices[book]]+pages[book]);
      } else if(book == 0){
        dp[0][amt] = prices[0] > amt ? 0 : pages[0];
      }
    }
  }
  return dp[no_books-1][total];
}

int main(void){
  ll n, x;
  std::cin>>n>>x;
  std::vector<ll> prices(n);
  std::vector<ll> pages(n);
  for(ll i = 0; i < n; i++){
    std::cin>>prices[i];
  }
  for(ll i = 0; i < n; i++){
    std::cin>>pages[i];
  }
  std::cout<<max_pages(n, x, prices, pages);
  return 0;
}
