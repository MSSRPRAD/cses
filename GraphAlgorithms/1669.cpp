#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

bool found = false;
vector<int> correctPath;

void dfs(int current, int source, int pathLength, vector<int> path, vector<vector<int>> &adj, vector<bool> &visited){
    if(found) return;

    if(!visited[current]) visited[current] = true;

    for(int neighbour : adj[current]){
        if(found) return;
        path.push_back(neighbour);
        if(neighbour ==  source && pathLength > 2){
            for(int i : path) correctPath.push_back(i);
            found = true;
        }
        if(found) return;
        if(!visited[neighbour]) dfs(neighbour, source, pathLength + 1, path, adj, visited);
        path.pop_back();
    }
}

int main(void){
    IOS;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    while(m--) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    for(int i = 0; i < n; i++){
        vector<bool> visited(n, false);
        dfs(i, i, 1, {i}, adj, visited);
        if(found){
            cout << correctPath.size() << endl;
            for(int it : correctPath) cout << it+1 << ' ';
            exit(0);
        }
    }

    if(!found) cout << "IMPOSSIBLE";
    return 0;
}