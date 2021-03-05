#pragma once

#include <iostream>

using namespace std;

class Stack {
    public:
    enum Exception{ EMPTY_STACK, FULL_STACK };

        Stack(int size) {
            top = -1;
            this->size = size;
            *arr = arr[size];
        }

        void push(int x);
        int pop();
        int peek();
        bool isFull() const;
        bool isEmpty() const;
        /*bool isFull() {
            return top == SIZE - 1;
        }

        bool isEmpty() {
            return top == -1;
        }*/
        friend std::ostream &operator<<(std::ostream &os, Stack &s);

        
    private:
        int top, size, *arr;
};