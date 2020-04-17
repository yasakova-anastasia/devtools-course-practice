// Copyright 2020 Okmyanskiy Andrey

#include "include/stack.h"

Stack::Stack(int size) {
    if (size <= 0) {
        this->size = sizeDefault;
    } else {
        this->size = size;
    }
    mas = new double[this->size];
    top = 0;
}

Stack::Stack(const Stack& stack) {
    size = stack.size;
	mas = new double[size];
	top = stack.top;
	for (int i = 0; i < top; i++)
		mas[i] = stack.mas[i];
}

Stack::~Stack() {
    delete[] mas;
}

int Stack::getSize() const {
    return size;
}

int Stack::getTop() const {
    return top;
}

bool Stack::isEmpty() const {
    return (top == 0); 
}

bool Stack::isFull() const { 
    return (top == size); 
}

void Stack::put(const double value) {
    mas[top++] = value;
}

double Stack::get() {
    top--;
    return mas[top];
}

void Stack::operator = (const Stack& stack) {
    size = stack.size;
	mas = new double[size];
	top = stack.top;
	for (int i = 0; i < top; i++)
		mas[i] = stack.mas[i];
}

bool Stack::operator == (const Stack& stack) const {
    if (size == stack.size) {
        if (top == stack.top) {
            Stack st1(*this);
            Stack st2(stack);
            bool check = true;
            for (int i = 0; i < size; i++) {
                if (st1.get() != st2.get()) {
                    check = false;
                    break;
                }
            }
            if (check) {
                return true;
            }
        }
    }
    return false;
}

bool Stack::operator != (const Stack& stack) const {
    return !(*this == stack);
}
