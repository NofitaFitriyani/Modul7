#include <iostream>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
};

struct Node {
    Mahasiswa data;
    Node* next;
};

Node* front = nullptr;
Node* back = nullptr;
const int maksimalQueue = 5; // Batas maksimal antrian

int countQueue();  // Deklarasi fungsi countQueue

bool isFull() {
    return countQueue() == maksimalQueue;
}

bool isEmpty() {
    return front == nullptr;
}

void enqueueAntrian(Mahasiswa data) {
    if (isFull()) {
        cout << "Antrian penuh" << endl;
        return;
    }
    
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    
    if (isEmpty()) {
        front = back = newNode;
    } else {
        back->next = newNode;
        back = newNode;
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            back = nullptr;
        }
    }
}

int countQueue() {
    int count = 0;
    Node* temp = front;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void clearQueue() {
    while (!isEmpty()) {
        dequeueAntrian();
    }
}

void viewQueue() {
    cout << "Data antrian teller:" << endl;
    Node* temp = front;
    int index = 1;
    for (int i = 0; i < maksimalQueue; i++) {
        if (temp != nullptr) {
            cout << index << ". Nama: " << temp->data.nama << ", NIM: " << temp->data.nim << endl;
            temp = temp->next;
        } else {
            cout << index << ". (kosong)" << endl;
        }
        index++;
    }
}

int main() {
    Mahasiswa mhs1 = {"Andi", "2311102001"};
    Mahasiswa mhs2 = {"Maya", "2311102002"};
    
    enqueueAntrian(mhs1);
    enqueueAntrian(mhs2);
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
