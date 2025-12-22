#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<long long> vt;
    int n; cin >> n;
    while (n--) {
        long long x; cin >> x;
        vt.push_back(x);
    }
    sort(vt.begin(), vt.end(), greater<long long>());
    cout << vt[0] + vt[1];
}
