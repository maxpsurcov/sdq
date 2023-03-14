#include <iostream>
#include <conio.h>

using namespace std;

class Stack {
public:
    Stack();
    ~Stack();

    void push(int data);
    int pop();
    int peek();
    bool isEmpty();
    int size();
    void clear();

private:
    int* data;
    int top;
    int capacity;
    const int INITIAL_CAPACITY = 10;

    void resize(int newCapacity);
};

Stack::Stack() {
    capacity = INITIAL_CAPACITY;
    data = new int[capacity];
    top = -1;
}

Stack::~Stack() {
    delete[] data;
}

void Stack::push(int data) {
    if (top == capacity - 1) {
        resize(capacity * 2);
    }
    top++;
    this->data[top] = data;
}

int Stack::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    int result = data[top];
    top--;
    if (top < capacity / 4) {
        resize(capacity / 2);
    }
    return result;
}

int Stack::peek() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    return data[top];
}

bool Stack::isEmpty() {
    return top == -1;
}

int Stack::size() {
    return top + 1;
}

void Stack::clear() {
    delete[] data;
    capacity = INITIAL_CAPACITY;
    data = new int[capacity];
    top = -1;
}

void Stack::resize(int newCapacity) {
    int* newData = new int[newCapacity];
    for (int i = 0; i <= top; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}
int main() {
    Stack stack;

    stack.push(17);
    stack.push(46);
    stack.push(81);
    stack.push(24);
    stack.push(2);

    std::cout << "Size: " << stack.size() << std::endl; 

    std::cout << "Top: " << stack.peek() << std::endl; //останній елемент, що був доданий до стеку і що буде видалений першим

    std::cout << "Popped: " << stack.pop() << std::endl; //це процес вилучення елементу з вершини стеку
    std::cout << "Popped: " << stack.pop() << std::endl; 

    stack.clear();
    std::cout << "Size after clear: " << stack.size() << std::endl; 

    char ch = _getch(); // читання символу без очікування Enter
    std::cout << "You pressed the key: " << ch << std::endl;

    return 0;
}
