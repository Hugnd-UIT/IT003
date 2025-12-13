#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> adj(m);

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(m, false);
    queue<int> q;

    visited[0] = true;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    bool empty = true;
    for (int i = 1; i < m; i++) {
        if (visited[i]) {
            if (!empty) cout << " ";
            cout << i;
            empty = false;
        }
    }

    if (empty) cout << "KHONG";

    return 0;
}
