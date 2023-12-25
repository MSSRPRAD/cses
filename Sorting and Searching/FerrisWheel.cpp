#include <vector>
#include <algorithm>
#include <iostream>

int main(void){
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int n, x;
    std::cin >> n >> x;
    std::vector<int> weights;

    int tmp = n;
    while(tmp--){
        int foo;
        std::cin >> foo;
        weights.push_back(foo);
    }

    int no_gondolas = 0;
    int weight_of_gondola = 0;
    
    // Sort Gondolas by weight
    std::sort(weights.begin(), weights.end());

    // Keep Track of children with Gondolas
    std::vector<bool> have_gondolas(n, false); 

    int left = 0, right = n-1;
    // Greedily assign gondolas
    while((left <= right)){
        // Pair heaviest with lightest
        if(weights[left] + weights[right] <= x){
            no_gondolas++;
            left++;
            right--;
        } else {
            // Give Gondola exclusively to heavier kid
            no_gondolas++;
            right--;
        }
    }

    std::cout << no_gondolas;
    return 0;
}