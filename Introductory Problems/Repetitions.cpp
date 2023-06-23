#include <iostream>
#include <string>

int main(void){
    std::string s;
    std::cin >> s;
    long len = s.length();
    long ans = 1;
    long max = 1;
    for(long i=0;i<len;i++){
        if(i<len-1){
            if(s[i]==s[i+1]){
                max++;
            } else {
                ans = std::max(max, ans);
                max = 1;
            }
        } else {
            ans = std::max(max, ans);
        }
    }
    std::cout<<ans;
    return 0;
}