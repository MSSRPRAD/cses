#include<iostream>
#define fio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)

int count = 0;
char board[8][8];
// Availibility of a particular left/right diagonal and row
bool left_diag[15] = {false}, right_diag[15] = {false}, rows[7] = {false};


void calculate_possibilities(int col){
  if(col == 8){
    count++;
    return;
  } else {
    for(int row = 0; row < 8; ++row){
      if(board[row][col] == '.' &&
         left_diag[row-col+7] == false &&
         right_diag[row+col] == false &&
         rows[row] == false) {

        left_diag[row-col+7] = true;
        right_diag[row+col] = true;
        rows[row] = true;

        calculate_possibilities(col+1);

        left_diag[row-col+7] = false;
        right_diag[row+col] = false;
        rows[row] = false;
      }
    }
  }
}

int main(void){
  fio;
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      std::cin>>board[i][j];
    }
  }
  calculate_possibilities(0);
  std::cout<<count;
  return 0;
}
