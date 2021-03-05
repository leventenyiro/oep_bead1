#include "stack.h"

using namespace std;

void Stack::push(int x) {
    if (isFull()) throw FULL_STACK;
    arr[++top] = x;
}

int Stack::pop() {
    if (isEmpty()) throw EMPTY_STACK;
    return arr[top--];
}

int Stack::peek() {
    if (isEmpty()) throw EMPTY_STACK;
    return arr[top]; 
}

bool Stack::isFull() const {
    return top == size - 1;
}

bool Stack::isEmpty() const {
    return top == -1;
}

ostream &operator<<(std::ostream& os, Stack &s) {
    os << "Elements: ";
    for (int i = s.top; i >= 0; i--) {
        os << s.arr[i] << " ";
    }
    return os;
}