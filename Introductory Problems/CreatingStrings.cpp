#include<iostream>
#include<string>
#include<set>
#define ll long long
#define fio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)

void permute(std::string str, int left, int right, std::set<std::string> &outputs){
  if(left == right) {
    std::cout<<str<<std::endl;
    outputs.insert(str);
  } else {
    for(int i=left;i<=right;i++){
      std::swap(str[left], str[i]);
      permute(str, left+1, right, outputs);
      std::swap(str[left], str[i]);
    }
  }
}

int main(void){
  fio;
  std::string input;
  std::cin>>input;
  std::set<std::string> outputs;
  permute(input, 0, input.length()-1, outputs);
  std::cout<<outputs.size()<<"\n";
  for(auto line: outputs){
    std::cout<<line<<"\n";
  }
  return 0;
}
