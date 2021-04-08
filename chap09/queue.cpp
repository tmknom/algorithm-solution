#include <iostream>
#include <vector>

using namespace std;

const int QUEUE_MAX = 100000;

int qu[QUEUE_MAX];
int tail, head;

void init() {
    tail = head = 0;
}

bool isEmpty() {
    return (head == tail);
}

bool isFull() {
    return (head == (tail + 1) % QUEUE_MAX);
}

void enqueue(int x) {
    if (isFull()) {
        cout << "error: queue is full" << endl;
        return;
    }
    qu[tail] = x;
    tail++;

    if (tail == QUEUE_MAX) tail = 0;
}

int dequeue() {
    if (isEmpty()) {
        cout << "error: queue is empty" << endl;
        return -1;
    }
    int result = qu[head];
    head++;

    if (head == QUEUE_MAX) head = 0;
    return result;
}

int main() {
    init();

    enqueue(3);
    enqueue(5);
    enqueue(6);

    cout << dequeue() << endl;
    cout << dequeue() << endl;

    enqueue(9);

    cout << dequeue() << endl;
    cout << dequeue() << endl;
}
