#include <bits/stdc++.h>

using namespace std;

bool impossible = false;

void dfs(int current, bool color, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &team){
    if(impossible) return;

    // If previously colored and previous color is contradicting
    if(visited[current] && team[current] != color){
        impossible = true;
        return;
    }
    
    visited[current] = true;
    team[current] = color;

    for(int neighbour : adj[current]){
        // Check if color same as any of the neighbours
        if(visited[neighbour] && team[neighbour] == color) impossible = true;
        if(!visited[neighbour])
            dfs(neighbour, !color, adj, visited, team);
    }
}

int main(void){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    vector<bool> team(n, false);
    vector<bool> visited(n, false);

    for(int i = 0; i < n; i++){
        // Start each new friend group with false
        if(!visited[i]){
            dfs(i, false, adj, visited, team);
        }
    }


    if(impossible){
        cout << "IMPOSSIBLE";
        exit(0);
    }

    for(int i = 0; i < n; i++){
        cout << team[i]+1 << ' ';
    }
                                                                                                                                                                                                                                                                                                                                                                                                                                                  
    return 0;
}