#include<iostream>
#include<vector>

std::vector<std::string> gray_code(long long n){
    if(n==1){
        std::vector<std::string> vec;
        vec.push_back("0");
        vec.push_back("1");
        return vec;
    } else {
        std::vector<std::string> vec;
        std::vector<std::string> vecprev = gray_code(n-1);
        for(int i=0;i<vecprev.size();i++){
            vec.push_back("0"+vecprev[i]);
        }
        for(int i=vecprev.size()-1;i>=0;i--){
            vec.push_back("1"+vecprev[i]);
        }
        return vec;
    }

}

int main(void){
    long long n;
    std::cin>>n;
    std::vector<std::string> vec;
    vec = gray_code(n);
    for(auto i:vec){
        std::cout<<i<<std::endl;
    }
    return 0;
}