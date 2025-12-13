#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> degree(m, 0);

    int u, v;
    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }

    int isolated = 0;
    for (int i = 0; i < m; i++) {
        if (degree[i] == 0) {
            isolated++;
        }
    }

    cout << isolated;
    return 0;
}