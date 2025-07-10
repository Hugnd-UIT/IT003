#include <iostream>
using namespace std;

bool BinarySearch(int Arr[100], int Size, int Value) {
    int Left = 0, Right = Size - 1, Mid;
    while (Left <= Right) {
        Mid = (Left + Right) / 2;
        if (Arr[Mid] == Value) 
            return true;
        else if (Arr[Mid] < Value) 
            Left = Mid + 1;
        else 
            Right = Mid - 1;
    }
    return false;
}
 
int main() {
    int Size, Value, Array[100];
    cin >> Size >> Value;
    for (int i = 0; i < Size; i++) {
        cin >> Array[i];
    }
    if (BinarySearch(Array, Size, Value)) {
        cout << 1;
    } else {
        cout << 0;
    }
}