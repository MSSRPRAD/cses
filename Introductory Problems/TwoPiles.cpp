#include <iostream>

int main(void){
    long long t;
    std::cin >> t;
    for (long long i = 0; i<t; i++){
        long long a, b;
        std::cin >> a >> b;
        if ((a+b)%3 == 0 && 2*a >= b && 2*b >= a)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }
    return 0;
}