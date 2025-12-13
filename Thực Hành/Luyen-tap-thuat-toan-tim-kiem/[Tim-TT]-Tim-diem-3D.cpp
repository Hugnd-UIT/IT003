#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <iostream>
using namespace std;

struct Diem {
    double x, y, z;
};

bool compare(Diem a, Diem b) {
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

int main() {
    int sizeA, sizeB;
    vector<Diem> A;
    vector<Diem> B;
    cin >> sizeA;
    for (int i = 0; i < sizeA; i++) {
        Diem tempA;
        cin >> tempA.x >> tempA.y >> tempA.z;
        A.push_back(tempA);
    }
    cin >> sizeB;
    for (int i = 0; i < sizeB; i++) {
        Diem tempB;
        cin >> tempB.x >> tempB.y >> tempB.z;
        B.push_back(tempB);
    }
    vector<string> ans;
    int i, j;
    for (i = 0; i < sizeB; ++i) {
        for (j = 0; j < sizeA; j++) {
            if (compare(A[j], B[i])) {
                ans.push_back(to_string(j));
                break;
            }
        }
        if (j == sizeA) {
            ans.push_back("KHONG");
        }
    }
    for (size_t i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}