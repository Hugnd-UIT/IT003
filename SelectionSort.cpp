#include <iostream>
using namespace std;

void Print(int Array[100], int Size) {
    for (int i = 0; i < Size; i++) {
        cout << Array[i] << " ";
    }
    cout << endl;
}

void SelectionSort(int Arr[100], int Size) {
    for (int i = 0; i < Size - 1; i++) {
        int MinPos = i;
        for (int j = i + 1; j < Size; j++) {
            if (Arr[j] < Arr[MinPos]) {
                MinPos = j;
            }
        }
        if (MinPos != i) {
            swap(Arr[MinPos], Arr[i]);
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
    SelectionSort(Array, Size);
}