#include<iostream>

int main(void){
    const long long MOD = 1000000007; // 10^9 + 7
    long long input;
    std::cin>>input;
    long long res = 1;
    for(long long i=0;i<input;i++){
        res = (res*2);
        res = res%MOD;
    }
    std::cout<<res;
    return 0;
}