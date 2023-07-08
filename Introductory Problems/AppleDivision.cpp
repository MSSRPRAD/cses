#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

#define ll long long
#define fio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)

ll partition(const std::vector<ll>& input, std::vector<ll>& grp1, std::vector<ll>& grp2, ll n) {
    std::vector<ll> tmp_grp1, tmp_grp2;
    ll diff = std::numeric_limits<ll>::max();
    for (ll i = 0; i < (1 << n) - 1; i++) {
        ll sum1 = 0, sum2 = 0;
        tmp_grp1.clear();
        tmp_grp2.clear();
        for (ll index = 0; index < input.size(); index++) {
            if ((i & (1 << index)) == 0) {
                tmp_grp1.push_back(input[index]);
                sum1 += input[index];
            } else {
                tmp_grp2.push_back(input[index]);
                sum2 += input[index];
            }
        }
        if (std::abs(sum1 - sum2) < diff) {
            diff = std::abs(sum1 - sum2);
            grp1 = tmp_grp1;
            grp2 = tmp_grp2;
        }
    }
    return diff;
}

int main() {
    fio;
    ll n;
    std::cin>>n;
    std::vector<ll> input(n);
    for(ll i = 0; i < n; ++i){
      std::cin>>input[i];
    }
    std::vector<ll> grp1, grp2;
    ll diff = partition(input, grp1, grp2, n);
    std::cout << diff << std::endl;

    return 0;
}
