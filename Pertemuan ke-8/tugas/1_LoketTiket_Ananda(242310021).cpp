#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " dimasukkan ke antrian." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue kosong, tidak bisa dequeue." << endl;
            return;
        }
        Node* temp = front;
        cout << temp->data << " dikeluarkan dari antrian." << endl;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue kosong." << endl;
            return;
        }
        Node* temp = front;
        cout << "Isi queue: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int pilihan, nilai;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue (Tambah antrian tiket)\n";
        cout << "2. Dequeue (Hapus antrian tiket)\n";
        cout << "3. Tampilkan antrian\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Masukkan nomor tiket: ";
            cin >> nilai;
            q.enqueue(nilai);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
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
