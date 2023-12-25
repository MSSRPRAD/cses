#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::cout << std::flush;

    std::vector<std::pair<int, bool>> customer_times;

    while(n--) {
        int start, end;
        std::cin >> start >> end;
        customer_times.push_back({start, true});
        customer_times.push_back({end, false});
    }

    auto custom_comparator = [](const auto &a, const auto &b){
        return a.first < b.first;
    };

    std::sort(customer_times.begin(), customer_times.end(), custom_comparator);

    int max_capacity = 0, capacity = 0;
    for(auto it: customer_times){
        if(it.second){
            capacity++;
            max_capacity = std::max(capacity, max_capacity);
        } else {
            capacity--;
        }
    }

    std::cout << max_capacity << std::flush;
    return 0;
}
