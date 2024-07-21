#include <bits/stdc++.h>

using namespace std;

const vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const string dir_chars = "RLDU";

bool isValid(int y, int x, const vector<vector<bool>>& map) {
    return y >= 0 && y < map.size() && x >= 0 && x < map[0].size() && map[y][x];
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<bool>> map(n, vector<bool>(m));
    pair<int, int> start, end;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == 'A') {
                start = {i, j};
                map[i][j] = true;
            } else if (c == 'B') {
                end = {i, j};
                map[i][j] = true;
            } else {
                map[i][j] = (c == '.');
            }
        }
    }
    
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m));
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    
    dist[start.first][start.second] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [d, curr] = pq.top();
        pq.pop();
        
        if (curr == end) break;
        
        for (int i = 0; i < 4; i++) {
            int ny = curr.first + dirs[i].first;
            int nx = curr.second + dirs[i].second;
            
            if (isValid(ny, nx, map) && d + 1 < dist[ny][nx]) {
                dist[ny][nx] = d + 1;
                parent[ny][nx] = curr;
                pq.push({d + 1, {ny, nx}});
            }
        }
    }
    
    if (dist[end.first][end.second] == 1e9) {
        cout << "NO\n";
    } else {
        cout << "YES\n" << dist[end.first][end.second] << '\n';
        
        string path;
        auto curr = end;
        while (curr != start) {
            auto prev = parent[curr.first][curr.second];
            for (int i = 0; i < 4; i++) {
                if (prev.first + dirs[i].first == curr.first && prev.second + dirs[i].second == curr.second) {
                    path += dir_chars[i];
                    break;
                }
            }
            curr = prev;
        }
        reverse(path.begin(), path.end());
        cout << path << '\n';
    }
    
    return 0;
}