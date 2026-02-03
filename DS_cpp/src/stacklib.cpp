#include "../include/stacklib.h"

Stack::Stack() : top(EMPTY_STACK_VAL){
    for (int i = 0; i < BUFFER_SIZE; i++){ buffer[i] = 0; }
}

Stack::~Stack(){}

bool Stack::isEmpty(){
    if (top <= EMPTY_STACK_VAL) return true;
    else return false;
}

bool Stack::isFull(){
    if (top >= BUFFER_SIZE - 1) return true;
    else return false;
}

bool Stack::validPos(int pos){
    if (pos < BUFFER_SIZE && pos > EMPTY_STACK_VAL) return true;
    else return false;
}

void Stack::push(int val){
    if (isFull()) { std::cout << "STACK OVERFLOW!\n"; return; }
    top++;
    buffer[top] = val;
    return;
}

int Stack::pop(){
    if (isEmpty()) { std::cout << "STACK UNDERFLOW\n"; return 0; }
    int popValue = buffer[top];
    buffer[top] = 0;
    top--;
    return popValue;
}

const int Stack::count() const{ return top; }
const int Stack::getBufferSize() const { return BUFFER_SIZE; }

void Stack::showStack() const{
    std::cout << top << std::endl;
    for (int i = BUFFER_SIZE - 1; i > EMPTY_STACK_VAL; i--){
        std::cout << "POS: " << i << " || VAL: " << buffer[i] << std::endl;
    }
}
