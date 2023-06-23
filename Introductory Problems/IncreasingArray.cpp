#include <iostream>

int main(void){
    long n;
    long moves = 0;
    long prev = -1;
    std::cin>>n;
    for (long i = 0; i < n; i++)
    {
        long val;
        std::cin >> val;
        if (i > 0) {
            if (val < prev) {
                moves += prev - val;
                val = prev;
            }
        }
        prev = val;
    }
    std::cout<<moves;
    return 0;
}