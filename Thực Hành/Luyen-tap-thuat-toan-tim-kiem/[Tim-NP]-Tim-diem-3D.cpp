#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <iostream>
using namespace std;

#define MAX 10000

struct Diem {
    double x, y, z;
};

int Compare(Diem a, Diem b) {
    if (a.x == b.x) {
        if (a.y == b.y) {
            if (a.z == b.z) {
                return 0;
            } else if (a.z < b.z) {
                return -1;
            } else {
                return 1;
            }
        } else if (a.y < b.y) {
            return -1;
        } else {
            return 1;
        }
    } else if (a.x < b.x) {
        return -1;
    } else {
        return 1;
    }
}

int Search(vector<Diem> Ds, Diem Toado) {
    int left = 0, right = Ds.size() - 1, middle, step = 0;
    while (left <= right) {
        middle = (left + right) / 2;
        step++;
        if (Compare(Toado, Ds[middle]) == -1) {
            right = middle - 1;
        } else if (Compare(Toado, Ds[middle]) == 1) {
            left = middle + 1;
        } else {
            return step;
        }
    }
    return -1;
}

int main() {
    vector<Diem> A;
    vector<Diem> Pi;
    int sizeA, sizePi;
    cin >> sizeA;
    for (int i = 0; i < sizeA; i++) {
        Diem temp;
        cin >> temp.x >> temp.y >> temp.z;
        A.push_back(temp);
    } 
    cin >> sizePi;
    for (int i = 0; i < sizePi; i++) {
        Diem temp;
        cin >> temp.x >> temp.y >> temp.z;
        Pi.push_back(temp);
    }
    vector<string> ans;
    for (int i = 0; i < sizePi; i++) {
        if (Search(A, Pi[i]) == -1) {
            ans.push_back("KHONG");
        } else {
            ans.push_back(to_string(Search(A, Pi[i])));
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}