#include <iostream>

long no_of_ways(long n){
    return (n*n*(n*n-1))/2 - 4*(n-1)*(n-2); 
}

int main(void){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long n;
    std::cin>>n;
    for(long i=1;i<=n;i++){
        std::cout<<no_of_ways(i)<<std::endl;
    }
    return 0;
}