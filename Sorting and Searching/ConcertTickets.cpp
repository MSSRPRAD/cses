#include <iostream>
#include <algorithm>
#include <set>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::multiset<int> mset;
    std::cin >> n >> m;
    
    int tmp = n;
    while(n--){
        int foo;
        std::cin >> foo;
        mset.insert(foo);
    }

    tmp = m;
    while(m--){
        int max_price;
        std::cin >> max_price;

        auto it = mset.upper_bound(max_price);
        
        if(it == mset.begin()){
            std::cout << -1 << std::endl;
        } else {
            std::cout << *(--it) << std::endl;
            mset.erase(it);
        }
    }

    return 0;
}