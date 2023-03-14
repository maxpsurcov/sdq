#include <iostream>

using namespace std;

const int MAX_SIZE = 100; // максимальний розмір черги

class Queue {
    private:
        int data[MAX_SIZE]; // масив даних
        int front, rear; // індекси переднього та заднього елементів черги
    public:
        Queue() {
            front = rear = -1; // початкове значення індексів переднього та заднього елементів
        }
        bool isEmpty() {
            return front == -1; // перевірка, чи черга порожня
        }
        bool isFull() {
            return rear == MAX_SIZE - 1; // перевірка, чи черга заповнена
        }
        void enqueue(int value) {
            if (isFull()) {
                cout << "Queue is full\n"; // повідомлення про те, що черга заповнена
                return;
            }
            if (isEmpty()) {
                front = 0; // якщо черга була порожня, то передній елемент стає першим доданим елементом
            }
            rear++; // збільшення індексу заднього елемента
            data[rear] = value; // додавання елемента до черги
        }
        void dequeue() {
            if (isEmpty()) {
                cout << "Queue is empty\n"; // повідомлення про те, що черга порожня
                return;
            }
            if (front == rear) {
                front = rear = -1; // якщо черга містить один елемент, то індекси переднього та заднього елементів стають -1
            } else {
                front++; // збільшення індексу переднього елемента
            }
        }
        int peek() {
            if (isEmpty()) {
                cout << "Queue is empty\n"; // повідомлення про те, що черга порожня
                return -1;
            }
            return data[front]; // повернення значення переднього елемента черги
        }
};

int main() {
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    cout << q.peek() << endl; 
    q.dequeue();
    cout << q.peek() << endl; 
    q.dequeue();
    cout << q.peek() << endl; 
    q.dequeue();
    q.dequeue(); // виведе повідомлення про те, що черга порожня
    return 0;
}
