#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node *next;

    explicit node(const int value) {
        data = value;
        next = nullptr;
    }
};

class linked_list {
private:
    node *head_ = nullptr;
    node *tail_ = nullptr;

public:
    void insert_first(const int data) {
        const auto new_node = new node(data);
        if (head_ == nullptr) {
            head_ = new_node;
            tail_ = head_;
        } else {
            new_node->next = head_;
            head_ = new_node;
        }
    }

    void insert_end(const int data) {
        const auto new_node = new node(data);
        if (tail_ == nullptr) {
            head_ = new_node;
            tail_ = head_;
        } else {
            new_node->next = nullptr;
            tail_->next = new_node;
            tail_ = new_node;
        }
    }

    [[nodiscard]] bool is_empty() const {
        return head_ == nullptr;
    }

    [[nodiscard]] int size() const {
        int size = 0;
        const node *temp = head_;
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }
        return size;
    }

    int delete_first() {
        if (is_empty()) {
            cout << "this list is empty\n";
            return 0;
        }
        const node *temp = head_;
        head_ = head_->next;
        const auto data = temp->data;
        delete temp;
        return data;
    }

    bool delete_data(const int data) {
        if (is_empty()) {
            cout << "List is empty. Cannot delete." << endl;
            return false;
        }

        if (head_->data == data) {
            const node *temp = head_;
            head_ = head_->next;

            if (head_ == nullptr) {
                tail_ = nullptr;
            }
            delete temp;
            return true;
        }

        node *temp = head_;

        while (temp->next != nullptr && temp->next->data != data) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Data " << data << " not found in the list." << endl;
            return true;
        }

        const node *to_delete = temp->next;
        temp->next = to_delete->next;

        if (to_delete == tail_) {
            tail_ = temp;
        }

        delete to_delete;
        return true;
    }

    void display() const {
        if (is_empty()) {
            cout << "this list is empty\n";
        }
        const node *temp = head_;
        while (temp != nullptr) {
            cout << temp->data << " → ";
            temp = temp->next;
        }
        cout << "\n";
    }

    ~linked_list() {
        node *temp = head_;
        while (temp != nullptr) {
            node *next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    linked_list list1;
    list1.insert_first(2);
    list1.insert_first(1);
    list1.insert_end(3);
    list1.insert_first(0);
    list1.insert_end(4);
    list1.display();
    list1.delete_first();
    list1.display();
    list1.delete_data(3);
    list1.display();

    return 0;
}
