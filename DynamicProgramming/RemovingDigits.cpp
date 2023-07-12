#include<iostream>
#include<vector>
#include<set>
#define ll long long
#define fio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)

ll removing_digits_greedy(ll n){
  ll steps = 0;
  while(true){
    std::set<ll> digits;
    ll tmp = n;
    while(tmp > 0){
      digits.insert(tmp%10);
      tmp /= 10;
    }
    if(digits.empty()) break;
    n -= *digits.rbegin();
    steps += 1;
  }
  return steps;
}

int main(void){
  fio;
  ll n;
  std::cin>>n;
  std::cout<<removing_digits_greedy(n);
  return 0;
}
