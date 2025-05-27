#include <iostream>
using namespace std;

class Queue {
private:
    int arr[3];
    int front;
    int rear;
    int size;
public:
    Queue() {
        front = -1;
        rear = -1;
        size = 3;
    }

    bool isFull() {
        return rear == size - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue penuh" << endl;
            return;
        }
        if (front == -1) front = 0;
        rear++;
        arr[rear] = value;
        cout << value << " dimasukkan ke antrian." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue kosong" << endl;
            return;
        }
        cout << arr[front] << " dikeluarkan dari antrian." << endl;
        front++;
        if (front > rear) {  // Reset queue ketika kosong
            front = -1;
            rear = -1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue kosong" << endl;
            return;
        }
        cout << "Isi queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue queue;
    int pilihan, nilai;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue (Tambah antrian tiket)\n";
        cout << "2. Dequeue (Hapus antrian tiket)\n";
        cout << "3. Tampilkan antrian\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                cout << "Masukkan nomor tiket: ";
                cin >> nilai;
                queue.enqueue(nilai);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.display();
                break;
            case 4:
                cout << "Keluar program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 4);

    return 0;
}
