#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> songs(n);
    for(int i = 0; i < n; i++){
        cin >> songs[i];
    }

    map<int, int> mp;

    int start = 0, end = 0;
    mp[songs[0]] = 0;

    int maxlen = 1;
    while(end < n){
        // If next element doesn't exist
        if(end == n-1) break;

        // If next element exists and is in window
        if(mp.find(songs[end+1])!= mp.end() && mp[songs[end+1]] >= start){
            start = mp[songs[end+1]] + 1;
        }
         // Add the next element to map and increase maxlen optionally
        mp[songs[end+1]] = end+1;
        end += 1;
        maxlen = max(maxlen, end-start+1);
    }

    cout << maxlen;

    return 0;
}