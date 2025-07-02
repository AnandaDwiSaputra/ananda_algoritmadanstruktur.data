#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;  
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; 
}

int main() {
    int data[] = {11, 22, 33, 44, 55, 66, 77};
    int n = sizeof(data) / sizeof(data[0]);
    int cari;

    cout << "Masukkan angka yang ingin dicari: ";
    cin >> cari;

    int hasil = binarySearch(data, n, cari);

    if (hasil != -1)
        cout << "Data ditemukan di indeks ke-" << hasil << endl;
    else
        cout << "Data tidak ditemukan." << endl;

    return 0;
}
