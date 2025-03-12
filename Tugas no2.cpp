#include <iostream>
#include <string>

using namespace std;

void inputBuku(string buku[], int &n) {
    cout << "Masukkan jumlah buku: ";
    cin >> n;
    cin.ignore();

    cout << "Masukkan judul buku:\n";
    for (int i = 0; i < n; i++) {
        cout << "Buku ke-" << i + 1 << ": ";
        getline(cin, buku[i]);
    }
}

void urutkanBuku(string buku[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (buku[j] > buku[j + 1]) {
                swap(buku[j], buku[j + 1]);
            }
        }
    }
}

void tampilkanBuku(string buku[], int n) {
    cout << "\nDaftar Buku Setelah Diurutkan:\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << buku[i] << endl;
    }
}

int cariBuku(string buku[], int n, string judulCari) {
    for (int i = 0; i < n; i++) {
        if (buku[i] == judulCari) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    string buku[100], judulCari;

    inputBuku(buku, n);

    urutkanBuku(buku, n);
    
    tampilkanBuku(buku, n);

    cout << "\nMasukkan judul buku yang ingin dicari: ";
    getline(cin, judulCari);
    
    int index = cariBuku(buku, n, judulCari);
    
    if (index != -1) {
        cout << "Buku ditemukan di indeks ke-" << index + 1 << " dalam daftar.\n";
    } else {
        cout << "Buku tidak ditemukan.\n";
    }

    return 0;
}
