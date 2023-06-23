#include <iostream>
#include <vector>
#include <numeric>

int main(void){
    long n, sum=0;
    std::cin>>n;
    for(long i=0;i<n-1;i++){
        long no;
        std::cin>>no;
        sum+=no;
    }
    long actual_sum = n*(n+1)/2;
    long missing = actual_sum - sum;
    std::cout<<missing;
    return 0;
}