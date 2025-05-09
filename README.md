# Data Structures and Algorithms

## Introduction to Data Structures

### What are Data Structures?

Data structures are a way of organizing and storing data in a computer so that it can be accessed and modified efficiently. They are fundamental to computer science and are used in almost every program or software system.

### Types of Data Structures

#### 1. Linear Data Structures

Linear data structures store data in a sequential manner. Examples include:

* **Arrays**: A collection of elements identified by index or key.

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

* **Linked Lists**: A series of connected nodes where each node contains data and a reference to the next node.

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

* **Stacks**: Follows the Last-In-First-Out (LIFO) principle.

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

* **Queues**: Follows the First-In-First-Out (FIFO) principle.

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

#### 2. Non-Linear Data Structures

Non-linear data structures store data in a hierarchical or interconnected manner. Examples include:

* **Trees**: A hierarchical structure with a root node and child nodes.

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

* **Graphs**: A set of nodes connected by edges.

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

### Why are Data Structures Important?

Data structures are essential for:

* Efficient data management
* Optimizing algorithms
* Reducing time and space complexity

## Stack Implementation Using Linked List

### Overview

This project demonstrates a stack data structure implemented using a linked list in C++. The implementation provides a clean, efficient, and memory-safe way to use the stack data structure with all standard operations.

### Data Structures

#### Linked List

A linked list is a linear data structure where elements (nodes) are not stored in contiguous memory locations. Each node contains data and a reference (pointer) to the next node in the sequence.

**Key Characteristics:**

* Dynamic size - can grow or shrink at runtime
* Efficient insertions and deletions (O(1) time when position is known)
* Random access is inefficient (O(n) time)
* Memory efficient - allocates memory as needed

In this implementation, each node contains:

* An integer value (`data`)
* A pointer to the next node (`next`)

#### Stack

A stack is an abstract data type that follows the Last-In-First-Out (LIFO) principle. The last element added to the stack will be the first element to be removed.

**Key Operations:**

* **Push (Insert):** Add an element to the top of the stack
* **Pop:** Remove and return the top element of the stack
* **isEmpty:** Check if the stack is empty
* **Peek (Top):** View the top element without removing it

### Implementation Details for Stack

#### Node Class

```cpp
class node {
public:
    int data;
    node *next;

    explicit node(const int val) {
        data = val;
        next = nullptr;
    }
};
```

#### Stack Class

```cpp
class stack {
    node *tail_ = nullptr;

public:
    [[nodiscard]] bool isEmpty() const;
    void insert(const int data);
    void display() const;
    int pop();
    [[nodiscard]] bool search(const int data) const;
    ~stack();
};
```

### Memory Management in Stack

The implementation ensures proper memory management:

* Each `new` operation in `insert()` is balanced with a `delete` in `pop()`
* The destructor properly deallocates all remaining nodes when the stack is destroyed
* No memory leaks occur during normal operations

### Usage Example for Stack

```cpp
int main() {
    stack s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s1.pop();  // Removes 4
    s1.insert(5);
    s1.display();  // Displays: 5 <= 3 <= 2 <= 1
    return 0;
}
```

### Time Complexity for Stack Operations

* **insert():** O(1)
* **pop():** O(1)
* **isEmpty():** O(1)
* **search():** O(n)
* **display():** O(n)

## Algorithms

### Linear Search Algorithm

Linear search is a simple searching algorithm that sequentially checks each element in a collection until the target element is found or the entire collection has been searched.

```cpp
int search(const int arr[], const int n, int sz) {
    for (int i = 0; i < sz; i++) {
        if (arr[i] == n) {
            return i;
        }
    }
    return -1;
}
```

### Quick Sort Algorithm

Quick Sort is a divide-and-conquer algorithm that picks an element as a pivot and partitions the given array around the picked pivot.

#### Implementation Details for Quick Sort

```cpp
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
```

### Time Complexity for Quick Sort

* **Best case:** O(n log n)
* **Average case:** O(n log n)
* **Worst case:** O(n^2) (when pivot is smallest or largest element every time)

### Space Complexity for Quick Sort

* O(log n) for recursive stack (in-place sort)

### Advantages of Quick Sort

* Faster in practice for large datasets
* In-place sorting algorithm

### Disadvantages of Quick Sort

* Not stable (relative order of equal elements may not be preserved)
* Worst-case time complexity is poor without careful pivot selection

Quick sort is best used when:

* You need fast average-case performance
* Memory usage needs to be minimal
* Stability is not a concern
