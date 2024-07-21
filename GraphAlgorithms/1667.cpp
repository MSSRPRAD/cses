#include <bits/stdc++.h>

using namespace std;

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

    vector<int> parent(n, -1);
    vector<int> distance(n, 1e9);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, 0});
    while(!q.empty()){
        pair<int, int> front = q.top();
        q.pop();

        for(int neighbour : adj[front.second]){
            int newDistance = front.first + 1;
            if(newDistance < distance[neighbour]){
                distance[neighbour] = newDistance;
                q.push({newDistance, neighbour});
                parent[neighbour] = front.second;
            }
        }
    }
    if(distance[n-1] == 1e9){
        cout << "IMPOSSIBLE";
        return 0;
    }
    // Get the path
    vector<int> path;
    int node = n-1;
    while(parent[node] != -1 && node > 0){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(0);
    reverse(path.begin(), path.end());

    cout << path.size() << endl;
    for(int p : path){
        cout << p + 1 << ' ';
    }
    return 0;
}