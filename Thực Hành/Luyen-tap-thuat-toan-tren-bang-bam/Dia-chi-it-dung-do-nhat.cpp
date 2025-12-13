#include <iostream>
#include <map>
#include <vector>
#include <climits>
using namespace std;

struct Hashtable {
    int m;
    int n;
    vector<vector<int>> bucket;
};

void InitHashtable(Hashtable& ht, int m) {
    ht.bucket.resize(m);
    ht.m = m;
    ht.n = 0;
}

int main() {
    Hashtable ht;
    int m;
    int n;
    cin >> n >> m;
    InitHashtable(ht, m);
    while (n != 0) {
        int key;
        cin >> key;
        int i = key % ht.m;
        ht.bucket[i].push_back(key);
        ht.n++;
        n--;
    }
    int min = INT_MAX;
    for (int i = 0; i < ht.m; i++) {
        if (ht.bucket[i].size() < min && ht.bucket[i].size() > 1) {
            min = ht.bucket[i].size();
        }
    }
    for (int i = 0; i < ht.m; i++) {
        if (ht.bucket[i].size() == min) {
            cout << i << " ";
        }
    }
}