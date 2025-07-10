#include<vector>
#include <iostream>
using namespace std;

void Merge(int Arr[], int Left, int Mid, int Right) {
    vector<int> x (Arr + Left, Arr + Mid + 1);
    vector<int> y (Arr + Mid + 1, Arr + Right + 1);
    size_t i = 0, j = 0;
    while (i < x.size() && j < y.size()) {
        if (x[i] <= y[j]) {
            Arr[Left] = x[i];
            ++Left;
            ++i;
        } else {
            Arr[Left] = y[j];
            ++Left;
            ++j;
        }
    }
    while (i < x.size()) {
        Arr[Left] = x[i];
        ++Left;
        ++i;
    }
    while (j < y.size()) {
        Arr[Left] = y[j];
        ++Left;
        ++j;
    }
}

void MergeSort(int Arr[], int Left, int Right) {
    if (Left >= Right) 
        return;
    int Mid = (Left + Right) / 2;
    MergeSort(Arr, Left, Mid);
    MergeSort(Arr, Mid + 1, Right);
    Merge(Arr, Left, Mid, Right);
}

int main() {
    int Size, Array[100];
    cin >> Size;
    for (int i = 0; i < Size; i++) {
        cin >> Array[i];
    }
    MergeSort(Array, 0, Size - 1);
    for (int i = 0; i < Size; i++) {
        cout << Array[i] << " ";
    }
}