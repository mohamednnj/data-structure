#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

node *head = nullptr;
node *tail = nullptr;

bool isEmpty() {
    return (head == nullptr);
}

void insert_end(int data) {
    node *new_node = new node();
    new_node->data = data;
    new_node->next = nullptr;
    if (isEmpty()) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

void insert_begin(int data) {
    node *new_node = new node();
    new_node->data = data;
    if (isEmpty()) {
        head = new_node;
        tail = new_node;
        return;
    } else {
        new_node->next = head;
        head = new_node;
    }
}

void insert_after(const int data, const int pos) {
    if (isEmpty()) {
        cout << "The list is empty." << endl;
        return;
    }

    node *temp = head;
    while (temp != nullptr) {
        if (temp->data == pos) {
            node *new_node = new node();
            new_node->data = data;
            new_node->next = temp->next;
            temp->next = new_node;
            break;
        }
        temp = temp->next;
    }
}

bool found(const int data) {
    if (isEmpty()) {
        cout << "The list is empty." << endl;
        return false;
    }
    node *temp = head;
    while (temp != nullptr) {
        if (temp->data == data) {
            cout << "The element is found." << endl;
            return true;
        }
        temp = temp->next;
    }
    cout << "The element is not found." << endl;
    return false;
}

void display() {
    if (isEmpty()) {
        cout << "The list is empty." << endl;
        return;
    }

    node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    insert_end(11);
    insert_end(20);
    cout << found(15) << endl;
    insert_after(15, 11);
    insert_end(30);
    insert_begin(9);
    cout << found(15) << endl;
    cout << "List contents: ";
    display();

    return 0;
}
