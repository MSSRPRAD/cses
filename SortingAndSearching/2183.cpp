#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> coins(n);
    for(ll i = 0; i < n; i++) cin >> coins[i];
    
    sort(coins.begin(), coins.end());

    ll coinSum = 1;
    for(ll i = 0; i < n; i++){
        if(coins[i] > coinSum){
            cout << coinSum;
            exit(0);
        } else {
            coinSum += coins[i];
        }
    }

    cout << coinSum;
    return 0;
}