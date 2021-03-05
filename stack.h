#pragma once

#include <iostream>
#define SIZE 100

using namespace std;

inline bool valid(int a) { return true }

class Stack {
    public:
    enum Exception{ EMPTY_STACK, FULL_STACK };

        Stack() {
            top = -1;
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
        int top;
        int arr[SIZE];
};