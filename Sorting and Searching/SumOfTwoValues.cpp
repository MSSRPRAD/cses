#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, x;
    std::cin >> n >> x;

    std::pair<int, int> result;
    std::vector<std::pair<int, int>> input;
    int tmp = n;
    int idx = 1;
    while(tmp--){
        int foo;
        std::cin >> foo;
        input.push_back({idx, foo});
        idx++;
    }

    auto custom_comparator = [](const auto &a, const auto &b){
        return a.second < b.second;
    };

    std::sort(input.begin(), input.end(), custom_comparator);

    int left = 0, right = n-1;
    while(left < right){
        if(input[left].second + input[right].second < x){
            left++;
        } else if(input[left].second + input[right].second > x){
            right--;
        } else {
            std::cout << input[left].first << ' ' << input[right].first << std::endl;
            return 0;
        }
    }

    std::cout << "IMPOSSIBLE" << std::endl;
    return 0;
}
