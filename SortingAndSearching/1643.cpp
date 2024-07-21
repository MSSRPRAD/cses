#include <bits/stdc++.h>

using namespace std;

int main(void){
    long long n;
    cin >> n;
    vector<long long> array(n);
    for(long long i = 0; i < n; i++) cin >> array[i];

    long long max_ending_here;
    long long max_so_far;
    max_ending_here = 0;
    max_so_far = LLONG_MIN;

    for(long long i = 0; i < n; i++){
        max_ending_here = max_ending_here + array[i];
        if(max_so_far < max_ending_here) 
            max_so_far = max_ending_here;
        if(max_ending_here < 0)
            max_ending_here = 0;
    }

    cout << max_so_far;
    return 0;
}