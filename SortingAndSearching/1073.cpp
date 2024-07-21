#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;

    vector<int> towers;
    for(int i = 0; i < n; i++){
        int cube;
        cin >> cube;
        // Get the smallest tower that is greater than cube
        int low = 0;
        int high = towers.size();
        int mid;
        while(low < high){
            mid = (low + high) / 2;
            if(towers[mid] <= cube){
                low = mid+1;
            } else if(towers[mid] > cube){
                high = mid;
            }
        }

        // If we couldn't find such a tower, create it with cube
        if(low == towers.size()){
            towers.push_back(cube);
        } else {
            towers[low] = cube;
        }
    }

    cout << towers.size();
    return 0;
}