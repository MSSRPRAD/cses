#include <iostream>

void steps(long n) {
    while (n != 1) {
        std::cout<<n<<" ";
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
    }
    std::cout<<n;
    return;
}

int main(void) {
    long n;
    std::cin>>n;
    steps(n);
    return 0;
}