#include <iostream>
#include <map>
using namespace std;

int m;

int h(int key, int i)
{
    return (key + i) % m;
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
        int j = 0;
        do {
            j = h(number, i);
            mp[j]++;
            if (mp[j] == 1) {
                break;
            }
            else {
                i++;
            }
        }
        while (i < m);
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
            cout << p.first << " ";
        }
    }
}