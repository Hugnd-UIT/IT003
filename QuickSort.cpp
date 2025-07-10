#include<iostream>
using namespace std;

// Phan hoach Lomuto
void Partition(int Arr[], int Left, int Right) {
    int Pivot = Arr[Right];
    int i = Left - 1;
    for (int j = Left; j < Right; j++) {
        if (Arr[j] <= Pivot) {
            ++i;
            swap(Arr[i], Arr[j]);
        }
    }
    ++i;
    swap(Arr[i], Arr[Right]);
    for (int k = Left; k < Right; k++) {
        if (i == k) {
            cout << "[" << Arr[k] << "] ";
        }
        else 
            cout << Arr[k] << " ";
    }
}

//Quick Sort(
//void QuickSort(int Arr[], int Left, int Right) {
//    if (Left >= Right) 
//        return;
//    int p = Partition(Arr, Left, Right);
//    QuickSort(Arr, Left, p - 1);
//    QuickSort(Arr, p + 1, Right);
//}

int main() {
    int Size, Array[100];
    cin >> Size;
    for (int i = 0; i < Size; i++) {
        cin >> Array[i];
    }
    Partition(Array, 0, Size - 1);
}