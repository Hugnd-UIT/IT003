#include <iostream>
using namespace std;

void Print(int Array[100], int Size) {
    for (int i = 0; i < Size; i++) {
        cout << Array[i] << " ";
    }
    cout << endl;
}

void InterchangeSort(int Arr[100], int Size) {
    for (int i = 0; i < Size - 1; i++) {
        for (int j = i + 1; j < Size; j++) {
            if (Arr[j] < Arr[i]) {
                swap(Arr[i], Arr[j]);
            }
        }
        cout << "Buoc " << i + 1 << ": ";
        Print(Arr, Size);
    }
}

int main() {
    int Size, Array[100];
    cin >> Size;
    for (int i = 0; i < Size; i++) {
        cin >> Array[i];
    }
    InterchangeSort(Array, Size);
}