#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> dirs = {
    {-1, 0},
    {1, 0},
    {0, 1},
    {0, -1}
};

bool withinBounds(int x, int y, vector<vector<bool>> &map){
    int n = map.size();
    int m = map[0].size();
    if(x >= 0 && x < n && y >= 0 && y < m){
        return true;
    }
    return false;
}

void dfs(int i, int j, vector<vector<bool>> &map, vector<vector<bool>> &reached){

    reached[i][j] = true;

    for(pair<int, int> dir : dirs){
        int newX = i + dir.first;
        int newY = j + dir.second;

        if(withinBounds(newX, newY, map) && map[newX][newY] && !reached[newX][newY]){
            dfs(newX, newY, map, reached);
        } 
    }
}

int main(void){

    int n, m;
    cin >> n >> m;
    vector<vector<bool>> map(n, vector<bool>(m));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            map[i][j] = (c == '.' ? true : false);
        }
    }

    vector<vector<bool>> reached(n, vector<bool>(m,false));
    int noRooms = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] and !reached[i][j]){
                noRooms++;
                dfs(i, j, map, reached);
            }
        }
    }

    cout << noRooms;
    return 0;
}