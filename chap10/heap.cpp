#include <iostream>
#include <vector>

using namespace std;

struct Heap {
    vector<int> heap;

    Heap() {}

    void push(int x) {
        heap.push_back(x);
        int index = heap.size() - 1;

        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] >= x) break;

            heap[index] = heap[parent];
            index = parent;
        }
        heap[index] = x;
    }

    int top() {
        if (!heap.empty()) return heap[0];
        else return -1;
    }

    void pop() {
        if (heap.empty()) return;
        int x = heap.back();
        heap.pop_back();

        int index = 0;
        while (index * 2 + 1 < heap.size()) {
            int child = index * 2 + 1;
            int right = index * 2 + 2;
            if (right < heap.size() && heap[right] > heap[child]) {
                child = right;
            }

            if (heap[child] <= x) break;
            heap[index] = heap[child];
            index = child;
        }
        heap[index] = x;
    }
};

int main() {
    Heap h;

    h.push(6);
    h.push(3);
    h.push(7);
    h.push(1);

    cout << h.top() << endl;
    h.pop();
    cout << h.top() << endl;

    h.push(11);
    cout << h.top() << endl;
}
