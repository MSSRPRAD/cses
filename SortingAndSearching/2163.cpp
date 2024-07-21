#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

#define endl '\n'
 

// using namespace std;
typedef long long ll;

int main(void){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    ll n, k;
    cin >> n >> k;

    indexed_set st;
    for(ll i = 1; i <= n; i++){
        st.insert(i);
    }
    
    int index = k % n;
    while(n--){
        auto element = st.find_by_order(index);
        cout << *element << ' ';

        st.erase(element);
        
        if(n){
            index = (index % n  + k)%n;
        }
    }
    return 0;
}