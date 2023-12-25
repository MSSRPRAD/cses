#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::cout << std::flush;

    std::vector<std::pair<int, int>> cinema_times;

    while(n--) {
        int start, end;
        std::cin >> start >> end;
        cinema_times.push_back({start, end});
    }

    auto custom_comparator = [](const auto &a, const auto &b){
        return a.second < b.second;
    };

    std::sort(cinema_times.begin(), cinema_times.end(), custom_comparator);

    int watched = 1;
    auto currently_watching = *cinema_times.begin();
    bool foo = true;
    for(auto it: cinema_times){
        if(foo){
            foo = false;
        }
        else {
            // If this cinema is starting after currently_watching is ending
            if(it.first >= currently_watching.second){
                currently_watching = it;
                watched++;
            }
        }
    }

    std::cout << watched << std::flush;
    return 0;
}
