#include <iostream>
using namespace std;

bool LinearSearch(int Arr[100], int Size, int Value) {
    for (int i = 0; i < Size; i++) {
        if (Arr[i] == Value) {
            return true;
        }
    }
    return false;
}
 
int main() {
    int Size, Value, Array[100];
    cin >> Size >> Value;
    for (int i = 0; i < Size; i++) {
        cin >> Array[i];
    }
    if (LinearSearch(Array, Size, Value)) {
        cout << 1;
    } else {
        cout << 0;
    }
}