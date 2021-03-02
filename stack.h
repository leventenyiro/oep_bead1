#pragma once

#include <iostream>

#define SIZE 100

using namespace std;

class Stack {
    private:
        int top;
    public:
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

        void toString() {
            if (isEmpty()) {
                cout << "Stack is empty";
            } else {
                for (int n : arr) {
                    cout << n << " ";
                }
            }
            cout << endl;
        }
};