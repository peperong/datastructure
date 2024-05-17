#include "stack.h"

void Stack::push(int data) {
    insert(0, data);
}

int Stack::pop() {
    int value = get(0);
    remove(0);
    return value;
}

int Stack::peek() {
    return get(0);
}

void Stack::operator+=(int value) {
    Stack::push(value);
}