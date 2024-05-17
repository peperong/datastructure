#include "linked_list.h"
#include <iostream>

LinkedList::LinkedList() {
    head_ = nullptr;
    size_ = 0;
}

LinkedList::~LinkedList() {
    while (head_) {
        Node* temp = head_;
        head_ = head_->next_;
        delete temp;
    }
}

void LinkedList::print() {
    Node* current = head_;
    while (current) {
        std::cout << current->value_ << " ";
        current = current->next_;
    }
    std::cout << std::endl;
}

void LinkedList::insert(int index, int value) {
    Node* newNode = new Node(value);
    if (index == 0) {
        newNode->next_ = head_;
        head_ = newNode;
    } else {
        Node* current = head_;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next_;
        }
        newNode->next_ = current->next_;
        current->next_ = newNode;
    }
    ++size_;
}

int LinkedList::get(int index) {
    Node* current = head_;
    for (int i = 0; i < index; ++i) {
        current = current->next_;
    }
    return current->value_;
}

void LinkedList::remove(int index) {
    Node* temp = nullptr;
    if (index == 0) {
        temp = head_;
        head_ = head_->next_;
    } else {
        Node* current = head_;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next_;
        }
        temp = current->next_;
        current->next_ = temp->next_;
    }
    delete temp;
    --size_;
}
