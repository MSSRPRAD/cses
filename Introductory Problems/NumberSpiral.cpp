#include<iostream>

long find_no(long row, long col){
    long num;
    // Lower Left
    if (row>col){
        long starting_element_of_row = row%2==1? (row+1)*(row+1) : row*row+1; 
        num = row%2==0? starting_element_of_row + col : starting_element_of_row - col;
    } 
    // Upper Right
    else if (row<col) {
        long starting_element_of_column = col%2==0? (col+1)*(col+1) : col*col+1; 
        num = col%2==0? starting_element_of_column - row : starting_element_of_column + row; 
    } else 
    // Diagonal
    {
        num = row*row+row+1;
    }
    return num;
}

int main(void){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long t;
    std::cin>>t;
    for(long i=0;i<t;i++){
        long x, y;
        std::cin>>y>>x;
        std::cout<<find_no(y-1, x-1)<<std::endl;
    }
    return 0;
}