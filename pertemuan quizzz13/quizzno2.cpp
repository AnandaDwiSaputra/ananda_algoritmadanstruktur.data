#include <iostream>
using namespace std;

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int data) {
    if (rear == MAX - 1) {
        cout << "Queue penuh!\n";
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = data;
    cout << "Data " << data << " ditambahkan.\n";
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue kosong!\n";
        return;
    }
    cout << "Data " << queue[front] << " dihapus.\n";
    front++;
}

void tampilQueue() {
    if (front == -1 || front > rear) {
        cout << "Queue kosong!\n";
        return;
    }
    cout << "Isi Queue: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

void menu() {
    int pilihan, data;
    do {
        cout << "\n=== Menu Queue ===\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Tampilkan Queue\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                tampilQueue();
                break;
            case 4:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 4);
}

int main() {
    menu();
    return 0;
}
