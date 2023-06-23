#include<iostream>

int main(void){
    long n;
    std::cin>>n;
    if(n==4){
        std::cout<<"3 1 4 2";
        return 0;
    }
    if(n==5){
        std::cout<<"2 4 1 3 5";
        return 0;
    }
    if(n==1){
        std::cout<<"1";
        return 0;
    }
    if(n<6){std::cout<<"NO SOLUTION"; return 0;}
    // If odd print the last one also
    if(n%2==1){std::cout<<n<<" ";}
    for(long i=1;i<=n/2;i++){
        std::cout<<i<<" "<<i+n/2<<" ";
    }
    return 0;
}