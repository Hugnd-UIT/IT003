#include <iostream>
using namespace std;

void InsertionSort(int Arr[100], int Size) {
    for (int i = 0; i < Size; i++) {
        int Temp = Arr[i], Pos = i - 1;
        while(Pos >= 0 && Temp < Arr[Pos]) {
            Arr[Pos + 1] = Arr[Pos];
            --Pos;
        }
        Arr[Pos + 1] = Temp;
        cout << "Buoc " << i << ": ";
        for (int j = 0; j <= i; j++) {
            cout << Arr[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int Size, Array[100];
    cin >> Size;
    for (int i = 0; i < Size; i++) {
        cin >> Array[i];
    }
    InsertionSort(Array, Size);
}