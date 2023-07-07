#include<iostream>
#include<vector>
#include<utility>

typedef long long ll;
typedef std::pair<int, int> Move;

void tower_of_hanoi(ll from_tower, ll using_tower, ll to_tower, ll no_of_disks, std::vector<Move> &moves){
    if(no_of_disks == 0){
        // Base Case
        return;
    } else {
        // First move the N-1 disks to the middle tower
        tower_of_hanoi(from_tower, to_tower, using_tower, no_of_disks-1, moves);
        // Move one disk from the left tower to the right tower
        // Add the move to the moves vector
        moves.push_back(std::make_pair(from_tower, to_tower));
        // Move N-1 disks from the middle tower to the right tower
        tower_of_hanoi(using_tower, from_tower, to_tower, no_of_disks-1, moves);
    }
}


int main(void){
    ll n;
    std::cin>>n;
    std::vector<Move> moves;
    tower_of_hanoi(1, 2, 3, n, moves);
    std::cout<<moves.size()<<"\n";
    for(const auto &move: moves) {
        std::cout<<move.first<<" "<<move.second<<"\n";
    }
    return 0;
}
