#include "queue.h"

void Queue::push(int data) {
    insert(size_, data);
}

int Queue::pop() {
    int value = get(0);
    remove(0);
    return value;
}

int Queue::peek() {
    return get(0);
}

void Queue::operator+=(int value) {
    Queue::push(value);
}