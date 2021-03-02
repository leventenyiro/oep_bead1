#pragma once

#include <iostream>

#define SIZE 100

using namespace std;

class Stack {
    public:
        int top;
        int arr[SIZE];

        Stack() {
            top = -1;
        }

        void push(int x) {
            if (isFull())
                cout << "Stackoverflow";
            else
                arr[++top] = x;
        }

        int pop() {
            if (isEmpty()) {
                exit(0);
            } else
                return arr[top--];
        }

        int peek() {
            if (isEmpty()) {
                exit(0);
            } else {
            return arr[top];
            }
        }

        bool isFull() {
            return top == SIZE - 1;
        }

        bool isEmpty() {
            return top == -1;
        }
        
    private:
        friend std::ostream &operator<<(std::ostream &os, Stack &s);
};

inline std::ostream &operator<<(std::ostream& os, Stack &s) {
    os << "Elements: ";
    for (int i = 0; i < s.top; i++) {
        os << s.arr[i] << " ";
    }
    os << s.arr[s.top];
    return os;
}