#include <iostream>
#include <map>
using namespace std;

int m;

int h(int key)
{
    return key % m;
}

int main()
{
    int n;
    cin >> n >> m;
    map<int, int> mp;
    while (n != 0) {
        int number;
        cin >> number;
        int i = 0;
        int j = h(number);
        mp[j]++;
        n--;
    }
    int max = 0;
    for (pair<int, int> p : mp) {
        if (p.second > max) {
            max = p.second;
        }
    }
    for (pair<int, int> p : mp) {
        if (p.second == max) {
            cout << p.first << "\n";
        }
    }
}