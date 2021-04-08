#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
    Node *prev, *next;
    string name;

    Node(string name_ = "") : prev(NULL), next(NULL), name(name_) {}
};

Node *nilNode;

void init() {
    nilNode = new Node();
    nilNode->next = nilNode;
    nilNode->prev = nilNode;
}

void printList() {
    Node *current = nilNode->next;
    for (; current != nilNode; current = current->next) {
        cout << current->name << " -> ";
    }
    cout << endl;
}

void insert(Node *v, Node *p = nilNode) {
    v->next = p->next;
    p->next->prev = v;
    p->next = v;
    v->prev = p;
}

void erase(Node *v) {
    if (v == nilNode) return;
    v->prev->next = v->next;
    v->next->prev = v->prev;
    delete v;
}

int main() {
    init();

    vector <string> names = {"yama", "nabe", "ito", "taka", "suzuki", "sato"};

    Node *nabe;
    for (int i = 0; i < names.size(); ++i) {
        Node *node = new Node(names[i]);
        insert(node);

        cout << "step " << i << ": ";
        printList();

        if (names[i] == "nabe") nabe = node;
    }

    cout << endl;
    cout << "before: ";
    printList();
    erase(nabe);
    cout << "after: ";
    printList();
}
