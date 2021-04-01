#pragma once

#include <iostream>

using namespace std;

class Stack {
    public:
    enum Exception{ EMPTY_STACK, FULL_STACK };

        Stack(int size) {
            top = -1;
            this->size = size;
            arr = new int[size];
        }

        void push(int x);
        int pop();
        int peek();
        bool isFull() const;
        bool isEmpty() const;
        friend std::ostream &operator<<(std::ostream &os, Stack &s);

        ~Stack() {
            delete arr;
        }
        
    private:
        int top, size, *arr;
};