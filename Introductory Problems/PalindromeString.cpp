#include<iostream>

int main(void){
    std::string input;
    std::cin>>input;
    int freq[26] = {0};
    for(int i=0; i<input.length(); i++){
        freq[input[i]-'A']++;
    }
    bool isOdd = input.length()%2 == 1;
    int noOfOdd = 0;
    for(int i=0; i<26; i++){
        if(freq[i]%2 == 1){
            noOfOdd++;
        }
    }
    if (noOfOdd > 1){
        std::cout<<"NO SOLUTION";
    } else {
        std::string outputleft = "";
        std::string outputright = "";
        // Fill all the even freq characters first
        for(int i=0; i<26; i++){
            if(freq[i]%2 == 0){
                int num = freq[i]/2;
                while(num--){
                    outputleft += (char)('A'+i);
                    outputright += (char)('A'+i);
                }
            }
        }
        // Print the outputleft + odd freq character + outputright
        for(int i=0;i<outputleft.length();i++) std::cout<<outputleft[i];
        for(int i=0;i<26;i++){
            if(freq[i]%2 == 1){
                int num = freq[i];
                while(num--) std::cout<<(char)('A'+i);
            }
        }
        for(int i=outputright.length()-1;i>=0;i--) std::cout<<outputright[i];
    }
    return 0;
}