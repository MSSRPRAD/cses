#include<iostream>

int main(void){
    long long n;
    std::cin>>n;
    long long zeros = 0;
    for(long long i=5;i<=n;i*=5){
        zeros += n/i;
        if(zeros==0) {
            break;
        }
    }
    std::cout<<zeros;
    return 0;
}