#include <iostream>
#include <vector>

using namespace std;

const int STACK_MAX = 100000;

int st[STACK_MAX];
int top;

void init() {
    top = 0;
}

bool isEmpty() {
    return top == 0;
}

bool isFull() {
    return top == STACK_MAX;
}

void push(int x) {
    if (isFull()) {
        cout << "error: stack is full" << endl;
        return;
    }
    st[top] = x;
    top++;
}

int pop() {
    if (isEmpty()) {
        cout << "error: stack is empty" << endl;
        return -1;
    }
    top--;
    return st[top];
}

int main() {
    init();

    push(3);
    push(5);
    push(6);

    cout << pop() << endl;
    cout << pop() << endl;

    push(9);

    cout << pop() << endl;
    cout << pop() << endl;
}
