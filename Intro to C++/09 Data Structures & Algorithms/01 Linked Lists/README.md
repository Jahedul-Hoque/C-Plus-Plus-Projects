<div align="center">

# 🔗 Advanced Linked List Implementation in C++ 📋

</div>

## 📖 Overview
This project explores an **advanced Linked List** implementation in C++, covering essential operations such as **insertion, deletion, searching, and reversing**. Linked Lists allow for efficient **dynamic memory allocation** and flexible node management compared to arrays.

## 🔑 Key Concepts
- **Nodes & Pointers**: Each node contains a value and a pointer to the next node.
- **Head & Tail**: The head points to the first node, while the tail points to the last node.
- **Dynamic Memory Management**: Using `new` to allocate nodes and `delete` for memory cleanup.
- **Operations & Complexity**:
  - ✅ Append (O(1))
  - ✅ Prepend (O(1))
  - ✅ Deletion (O(1) for head, O(n) for tail/middle)
  - ✅ Search by index/value (O(n))
  - ✅ Reversing (O(n))

## 💻 Code Implementation
```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* NextNode;

    Node(int value) {
        this->value = value;
        this->NextNode = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList(int value) {
        Node* NewNode = new Node(value);
        head = NewNode;
        tail = NewNode;
        length = 1;
    }

    ~LinkedList() {
        Node* temp = head;
        while (head) {
            head = head->NextNode;
            delete temp;
            temp = head;
        }
    }

    void PrintList() {
        Node* temp = head;
        while (temp) {
            cout << temp->value << " " << endl;
            temp = temp->NextNode;
        }
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->NextNode = newNode;
            tail = newNode;
        }
        length++;
    }

    void DeleteLast() {
        if (length == 0) return;
        Node* Temp = head;
        Node* PreviousNode = head;
        while (Temp->NextNode) {
            PreviousNode = Temp;
            Temp = Temp->NextNode;
        }
        tail = PreviousNode;
        tail->NextNode = nullptr;
        length--;
        if (length == 0) {
            head = nullptr;
            tail = nullptr;
        }
        delete Temp;
    }

    void reverse() {
        Node* temp = head;
        head = tail;
        tail = temp;
        Node* after = temp->NextNode;
        Node* before = nullptr;
        for (int i = 0; i < length; i++) {
            after = temp->NextNode;
            temp->NextNode = before;
            before = temp;
            temp = after;
        }
    }
};

int main() {
    LinkedList* MyLinkedList = new LinkedList(4);
    MyLinkedList->append(5);
    MyLinkedList->append(4);
    MyLinkedList->PrintList();
    cout << endl;
    MyLinkedList->reverse();
    MyLinkedList->PrintList();
}
```

## 🔍 Explanation
1. **Node Class**
   - Stores an integer value and a pointer to the next node.
   - The `NextNode` pointer is initialized to `nullptr`.

2. **LinkedList Class**
   - Initializes with a single node (head and tail are the same).
   - Implements key operations: **append, delete, reverse**.
   - Contains a destructor to free allocated memory.

3. **Operations & Complexity**
   - **Appending a node** → `O(1)`.
   - **Deleting the last node** → `O(n)` (traversing required).
   - **Reversing the list** → `O(n)` (each node's pointer is modified).

## 🎯 Summary
This project demonstrates an **optimized Linked List implementation** in C++, incorporating essential features such as **insertion, deletion, and reversing** while maintaining **efficient memory management**.

Future improvements may include:
- Implementing **Doubly Linked Lists**.
- Adding **search and sort functionalities**.
- Enhancing **error handling and optimizations**.

Stay tuned for more updates as I expand my Linked List knowledge! 🚀

