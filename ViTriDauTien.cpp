#include <iostream>
using namespace std;

int ViTriDauTien(int Arr[100], int Size, int Value) {
    int Res = -1, Left = 0, Right = Size - 1, Mid;
    while (Left <= Right) {
        Mid = (Left + Right) / 2;
        if (Arr[Mid] == Value) {
            Res = Mid + 1; 
            Right = Mid - 1;
        }
        else if (Arr[Mid] < Value) 
            Left = Mid + 1;
        else 
            Right = Mid - 1;
    }
    return Res;
}
 
int main() {
    int Quantity, Size, Value, Array[100];
    cin >> Quantity;
    while (Quantity--) {
        cin >> Size >> Value;
        for (int i = 0; i < Size; i++) {
            cin >> Array[i];
        }
        cout << ViTriDauTien(Array, Size, Value);
    }
}