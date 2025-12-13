#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

struct Diem {
    double x, y, z;
};

int main() {
    double size, b, e;
    vector<Diem> KG3D;
    cin >> size;
    for (int i = 0; i < size; i++) {
        Diem temp;
        cin >> temp.x >> temp.y >> temp.z;  
        KG3D.push_back(temp); 
    }
    cin >> b >> e;
    vector<Diem> answer;
    for (int i = 0; i < size; i++) {
        double distance = sqrt(pow(KG3D[i].x, 2) + pow(KG3D[i].y, 2) + pow(KG3D[i].z, 2));
        if (distance >= b && distance <= e) {
            answer.push_back(KG3D[i]);
        }
    }
    if (answer.size() == 0) {
        cout << "KHONG";
    } else {
        for (size_t i = 0; i < answer.size(); i++) {
            cout << answer[i].x << " " << answer[i].y << " " << answer[i].z << endl;
        }
    }
}