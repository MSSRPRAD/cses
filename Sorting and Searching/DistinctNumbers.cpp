#include <vector>
#include <iostream>
#include <set>

int main(void){
    int n;
    std::set<int> set;
    std::vector<int> input;

    std::cin >> n;

    while(n--){
        int foo;
        std::cin >> foo;
        input.push_back(foo);
    }

    for(auto it: input){
        set.insert(it);
    }

    std::cout << set.size();

    return 0;
}