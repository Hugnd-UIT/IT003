#include <iostream>
using namespace std;

void Print(int Array[100], int Size) {
    for (int i = 0; i < Size; i++) {
        cout << Array[i] << " ";
    }
    cout << endl;
}

void BubbleSort(int Arr[100], int Size) {
    for (int i = 0; i < Size - 1; i++) {
        bool Sorted = false;
        for (int j = 0; j < Size - i - 1; j++) {
            if (Arr[j] > Arr[j + 1]) {
                swap(Arr[j], Arr[j + 1]);
                Sorted = true;
            }
        }
        if (Sorted) {
            cout << "Buoc " << i + 1 << ": ";
            Print(Arr, Size);
        } else {
            break;
        }
    }
}

int main() {
    int Size, Array[100];
    cin >> Size;
    for (int i = 0; i < Size; i++) {
        cin >> Array[i];
    }
    BubbleSort(Array, Size);
}