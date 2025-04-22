// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;

    explicit node(const int val) {
        data = val;
        next = nullptr;
    }
};

class stack {
    node *tail_ = nullptr;

public:
    [[nodiscard]] bool isEmpty() const {
        return (tail_ == nullptr);
    }

    void insert(const int data) {
        const auto new_node = new node(data);
        if (isEmpty()) {
            tail_ = new_node;
        } else {
            new_node->next = tail_;
            tail_ = new_node;
        }
    }

    void display() const {
        node *temp = tail_;
        while (temp != nullptr) {
            cout << temp->data;
            temp = temp->next;
            if (temp != nullptr) {
                cout << " <= ";
            }
        }
        cout << endl;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        const node *temp = tail_;
        const auto data = tail_->data;
        tail_ = tail_->next;
        delete temp;
        return data;
    }

    [[nodiscard]] bool search(const int data) const{
        const node *temp = tail_;
        while (temp != nullptr) {
            if (temp->data == data) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    ~stack() {
        const node *current = tail_;
        while (current != nullptr) {
            node *next = current->next;
            delete current;
            current = next;
        }
        tail_ = nullptr;
        cout << "Stack destroyed, all memory freed" << endl;
    }
};

int main() {
    stack s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s1.pop();
    s1.insert(5);
    s1.display();
    return 0;
}
