# Introduction to Data Structures

## What are Data Structures?

Data structures are a way of organizing and storing data in a computer so that it can be accessed and modified efficiently. They are fundamental to computer science and are used in almost every program or software system.

## Types of Data Structures

### 1. Linear Data Structures

Linear data structures store data in a sequential manner. Examples include:

- **Arrays**: A collection of elements identified by index or key.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
```

- **Linked Lists**: A series of connected nodes where each node contains data and a reference to the next node.

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* n) {
    while (n != nullptr) {
        cout << n->data << " ";
        n = n->next;
    }
}

int main() {
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};

    printList(head);
    return 0;
}
```

- **Stacks**: Follows the Last-In-First-Out (LIFO) principle.

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
```

- **Queues**: Follows the First-In-First-Out (FIFO) principle.

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
```

### 2. Non-Linear Data Structures

Non-linear data structures store data in a hierarchical or interconnected manner. Examples include:

- **Trees**: A hierarchical structure with a root node and child nodes.

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root = new Node{1, nullptr, nullptr};
    root->left = new Node{2, nullptr, nullptr};
    root->right = new Node{3, nullptr, nullptr};

    inorderTraversal(root);
    return 0;
}
```

- **Graphs**: A set of nodes connected by edges.

```cpp
#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V) {
    for (int v = 0; v < V; ++v) {
        cout << "Adjacency list of vertex " << v << "\nhead ";
        for (auto x : adj[v])
            cout << "-> " << x;
        cout << endl;
    }
}

int main() {
    int V = 5;
    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    printGraph(adj, V);
    return 0;
}
```

## Why are Data Structures Important?

Data structures are essential for:

- Efficient data management
- Optimizing algorithms
- Reducing time and space complexity

## Example: Stack Implementation Using Linked List

### Overview

This project demonstrates a stack data structure implemented using a linked list in C++. The implementation provides a clean, efficient, and memory-safe way to use the stack data structure with all standard operations.

### Key Operations

- **Push (Insert)**: Add an element to the top of the stack.
- **Pop**: Remove and return the top element of the stack.
- **isEmpty**: Check if the stack is empty.
- **Peek (Top)**: View the top element without removing it.

### Code Example

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int data) {
        Node* newNode = new Node{data, top};
        top = newNode;
    }

    int pop() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;

    return 0;
}
```
