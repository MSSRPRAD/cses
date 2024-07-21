#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, x;
    cin >> n >> x;
    vector<int> array(n);
    for(int i = 0; i < n; i++) cin >> array[i];

    // mp[i] = index in array that has value i
    map<int, int> mp;
    for(int i = 0; i < n; i++) mp[array[i]] = i;

    for(int i = 0; i < n; i++){
        // Can array[i] and something else give us x?
        if(mp.find(x-array[i]) != mp.end()){
            if(mp[x-array[i]] != i){
                cout << (i+1) << ' ' << (mp[x-array[i]]+1);
                exit(0);
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}