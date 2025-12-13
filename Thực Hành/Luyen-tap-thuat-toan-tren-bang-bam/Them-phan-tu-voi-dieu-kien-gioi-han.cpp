#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Hashtable {
    int m;
    int n;
    double load;
    vector<vector<int>> vt;
};

void InitHashtable(Hashtable& ht) {
    ht.vt.resize(ht.m);
}

void Insert(Hashtable& ht, int key) {
    int current_load = 0;
    for (auto &v : ht.vt)
        current_load += v.size();
    if ((current_load + 1.0) / ht.m > ht.load)
        return;
    int j = key % ht.m;
    ht.vt[j].push_back(key);
}

int Search(Hashtable& ht, int key) {
    int j = key % ht.m;
    for (int i = 0; i < ht.vt[j].size(); i++) {
        if (ht.vt[j][i] == key) {
            return i;
        }
    }
    return -1;
}

int main()
{
    Hashtable ht;
    cin >> ht.m >> ht.load >> ht.n;
    InitHashtable(ht);
    int n = ht.n;
    while (n != 0) {
        int k;
        cin >> k;
        Insert(ht, k);
        n--;
    }
    cin >> n;
    while (n != 0) {
        int k;
        cin >> k;
        k = Search(ht, k);
        if (k == -1) {
            cout << "KHONG\n";
        } else {
            cout << k + 1 << "\n";
        }
        n--;
    }
}