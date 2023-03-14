#include <iostream>

using namespace std;

// Оголошення класу "вузол"
class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

// Оголошення класу "дек"
class Deque {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Deque() {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    // Функція, що повертає розмір дека
    int getSize() {
        return size;
    }

    // Функція, що додає елемент зліва
    void addLeft(int item) {
        Node* newNode = new Node();
        newNode->data = item;
        newNode->next = front;
        newNode->prev = NULL;

        if (front != NULL) {
            front->prev = newNode;
        } else {
            rear = newNode;
        }

        front = newNode;
        size++;
    }

    // Функція, що додає елемент праворуч
    void addRight(int item) {
        Node* newNode = new Node();
        newNode->data = item;
        newNode->next = NULL;
        newNode->prev = rear;

        if (rear != NULL) {
            rear->next = newNode;
        } else {
            front = newNode;
        }

        rear = newNode;
        size++;
    }

    // Функція, що видаляє елемент зліва
    void removeLeft() {
        if (front == NULL) {
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        } else {
            front->prev = NULL;
        }

        delete temp;
        size--;
    }

    // Функція, що видаляє елемент праворуч
    void removeRight() {
        if (rear == NULL) {
            return;
        }

        Node* temp = rear;
        rear = rear->prev;

        if (rear == NULL) {
            front = NULL;
        } else {
            rear->next = NULL;
        }

        delete temp;
        size--;
    }

    // Функція, що повертає значення першого елемента
    int peekLeft() {
        return front->data;
    }

    // Функція, що повертає значення останнього елемента
    int peekRight() {
        return rear->data;
    }
};

int main() {
    Deque dq;

    dq.addLeft(1);
    dq.addRight(2);
    dq.addRight(3);
    dq.addLeft(4);

    cout << "Peek left: " << dq.peekLeft() << endl;
    cout << "Peek right: " << dq.peekRight() << endl;

    dq.removeLeft();
    dq.removeRight();

    cout << "Size: " << dq.getSize() << endl;

    return 0;
}