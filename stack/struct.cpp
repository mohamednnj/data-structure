// stack
#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *ptr;

    explicit node(const int value) {
        data = value;
        ptr = nullptr;
    }
};

node *tail = nullptr;

bool isEmpty() {
    return (tail == nullptr);
}

void insert(int data) {
    const auto new_node = new node(data);

    if (isEmpty()) {
        tail = new_node;
    } else {
        new_node->ptr = tail;
        tail = new_node;
    }
}

int pop() {
    if (isEmpty()) {
        cout << "The stack is empty." << endl;
        return -1;
    }
    const node *temp = tail;
    tail = tail->ptr;
    return temp->data;
}

bool search(int data) {
    const node *temp = tail;
    while (temp != nullptr) {
        if (temp->data == data) {
            return true;
        }
        temp = temp->ptr;
    }
    return false;
}

void display() {
    node *temp = tail;
    while (temp != nullptr) {
        cout << temp->data;
        temp = temp->ptr;
        if (temp != nullptr) {
            cout << " <= ";
        }
    }
    cout << endl;
}


int main() {
    insert(10);
    insert(20);
    insert(30);
    cout << search(20) << endl;
    cout << search(60) << endl;
    display();
    cout << pop() << endl;
    insert(60);
    cout << search(60) << endl;
    display();
    return 0;
}
