#include <iostream>
#include <vector>
#include <algorithm>

int main(void){
    int n, m, k;
    std::vector<int> desired_sizes, actual_sizes;
    std::vector<int> sizes;
    std::cin >> n >> m >> k;
    int tmp = n;
    while(tmp--){
        int foo;
        std::cin >> foo;
        desired_sizes.push_back(foo);
    }
    tmp = m;
    while(tmp--){
        int foo;
        std::cin >> foo;
        actual_sizes.push_back(foo);
    }
    
    // Sort actual_sizes and desired_sizes
    sort(actual_sizes.begin(), actual_sizes.end());
    sort(desired_sizes.begin(), desired_sizes.end());

    // Keep Allocating Greedily
    int appl_idx = 0;
    int ap_idx = 0;
    int result = 0;
    while(appl_idx < n && ap_idx < m){
        int desired_size = desired_sizes[appl_idx];
        int actual_size = actual_sizes[ap_idx];
        if(actual_size < desired_size - k){
            // Apartment is too small for occupant. Go to next Apartment.
            ap_idx++;
        } else if(actual_size > desired_size + k){
            // Apartment is too big for occupant. Go to next Applicant.
            appl_idx++;
        } else {
            // Give Applicant the Apartment
            appl_idx++;
            ap_idx++;
            result++;
        }
    }

    std::cout << result;
    return 0;
}