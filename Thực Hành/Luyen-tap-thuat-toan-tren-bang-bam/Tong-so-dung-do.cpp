#include <iostream>
using namespace std;

struct Hashtable {
    int m;
    int n;
    int *bucket;
};

void InitHashtable(Hashtable& ht, int m) {
    ht.bucket = new int[m];
    for (int i = 0; i < m; i++) {
        ht.bucket[i] = -1;
    }
    ht.n = 0;
    ht.m = m;
}

int main() {
    Hashtable ht;
    int n; int m;
    cin >> m >> n;
    InitHashtable(ht, m);
    int ans = 0;
    while (n != 0) {
        int i = 0;
        int j = 0;
        int key; cin >> key;
        do {
            j = (key % ht.m + i) % ht.m;
            if (ht.bucket[j] == -1) {
                ht.n++;
                ht.bucket[j] = key;
                break;
            } else {
                i++;
                ans++;
            }
        } while (i < ht.m);
        n--;
    }
    cout << ans;
}