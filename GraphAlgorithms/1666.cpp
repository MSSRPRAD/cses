#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void dfs(int curr, vector<vector<int>> &adj, vector<bool> &reached){
    reached[curr] = true;
    for(int neighbour : adj[curr]){
        if (!reached[neighbour]) {
            dfs(neighbour, adj, reached);
        }
    }
}

int main(void){
    IOS;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    vector<bool> reached(n, false);
    dfs(0, adj, reached);
    int noRoads = 0;
    vector<int> toReach;
    for(int i = 1; i < n; i++){
        if(!reached[i]){
            noRoads++;
            toReach.push_back(i);
            dfs(i, adj, reached);
        }
    }
    cout << noRoads << endl;
    for(int tr : toReach){
        cout << 1 << ' ' << tr+1 << endl;
    }
    return 0;
}