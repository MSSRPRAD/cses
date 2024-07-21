#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> array(n);
    vector<int> num2indices(n);
    for(int i = 0; i < n; i++){
        cin >> array[i];
        num2indices[array[i]] = i;
    }

    int result = 1;
    for(int i = 1; i < n; i++){
        if(num2indices[i] > num2indices[i+1]) result++;        
    }

    cout << result;

    return 0;
}

