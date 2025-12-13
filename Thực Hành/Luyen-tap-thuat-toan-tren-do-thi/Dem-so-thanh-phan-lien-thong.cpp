#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    adj.assign(m, vector<int>());
    visited.assign(m, false);

    int u, v;
    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int components = 0;

    for (int i = 0; i < m; i++) {
        if (!visited[i]) {
            components++;
            dfs(i);
        }
    }

    cout << components;
}
