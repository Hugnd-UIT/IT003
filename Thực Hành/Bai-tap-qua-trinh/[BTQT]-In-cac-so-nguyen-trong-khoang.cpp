#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> vt;
    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        vt.push_back(x);
    }
    int a; cin >> a;
    int b; cin >> b;
    for (int i = 0; i < vt.size(); i++) {
        if (vt[i] > a && vt[i] < b) {
            cout << vt[i] << " ";
        }
    }
}
