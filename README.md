# Stack Implementation Using Linked List
## Overview
This project demonstrates a stack data structure implemented using a linked list in C++. The implementation provides a clean, efficient, and memory-safe way to use the stack data structure with all standard operations.
## Data Structures
### Linked List
A linked list is a linear data structure where elements (nodes) are not stored in contiguous memory locations. Each node contains data and a reference (pointer) to the next node in the sequence.
**Key Characteristics:**
- Dynamic size - can grow or shrink at runtime
- Efficient insertions and deletions (O(1) time when position is known)
- Random access is inefficient (O(n) time)
- Memory efficient - allocates memory as needed

In this implementation, each node contains:
- An integer value (`data`)
- A pointer to the next node (`next`)

### Stack
A stack is an abstract data type that follows the Last-In-First-Out (LIFO) principle. The last element added to the stack will be the first element to be removed.
**Key Operations:**
- **Push (Insert)**: Add an element to the top of the stack
- **Pop**: Remove and return the top element of the stack
- **isEmpty**: Check if the stack is empty
- **Peek (Top)**: View the top element without removing it

## Implementation Details
### Node Class
``` cpp
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
The node class stores an integer value and a pointer to the next node.
### Stack Class
``` cpp
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
#### Methods
- **isEmpty()**: Returns true if the stack is empty
- **insert(int data)**: Adds a new element to the top of the stack
- **pop()**: Removes and returns the top element of the stack
- **display()**: Prints all elements in the stack (from top to bottom)
- **search(int data)**: Searches for a given value in the stack
- **~stack()**: Destructor that properly cleans up all allocated memory

## Memory Management
The implementation ensures proper memory management:
- Each `new` operation in `insert()` is balanced with a `delete` in `pop()`
- The destructor properly deallocates all remaining nodes when the stack is destroyed
- No memory leaks occur during normal operations

## Usage Example
``` cpp
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
## Time Complexity
- **insert()**: O(1)
- **pop()**: O(1)
- **isEmpty()**: O(1)
- **search()**: O(n)
- **display()**: O(n)

This implementation provides an efficient way to use a stack data structure with minimal memory overhead
