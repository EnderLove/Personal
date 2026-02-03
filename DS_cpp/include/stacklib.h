#ifndef STACK_LIB_H
#define STACK_LIB_H

#include <iostream>
#include <string>

class Stack{
    private:
        static const int BUFFER_SIZE     = 10;
        static const int EMPTY_STACK_VAL = -1;

        int buffer[BUFFER_SIZE];
        int top;

    public:
        Stack();
        ~Stack();

        bool isEmpty();
        bool isFull();
        bool validPos(int pos);

        void push(int val);
        int pop();

        const int count() const;
        const int getBufferSize() const;

        void showStack() const;

    

        
};

#endif // STACK_LIB_H!
