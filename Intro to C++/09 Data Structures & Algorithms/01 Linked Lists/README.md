<div align="center">

# 🔗 Linked List Implementation in C++ 📋

</div>

## 📖 Overview
This project explores **Linked Lists**, a fundamental data structure in C++ that allows dynamic memory allocation and efficient node management. Unlike arrays, linked lists enable efficient insertion and deletion of elements.

## 🔑 Key Concepts
- **Nodes**: Each element in a linked list contains a value and a pointer to the next node.
- **Head & Tail**: The head points to the first node, and the tail points to the last node.
- **Dynamic Memory Allocation**: Using `new` to create nodes dynamically.
- **Iteration**: Traversing through the linked list using a loop.

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
//
    void PrintList() {
        Node* temp = head;
        while (temp) {
            cout << temp->value << endl;
            temp = temp->NextNode;
        }
    }

    void GetHead() {
        cout << "Head: " << head->value << endl;
    }

    void GetTail() {
        cout << "Tail: " << tail->value << endl;
    }

    void GetLength() {
        cout << "Length: " << length << endl;
    }
};

int main() {
    LinkedList* MyLinkedList = new LinkedList(4);
    MyLinkedList->GetHead();
    MyLinkedList->GetLength();
    MyLinkedList->GetTail();
    MyLinkedList->PrintList();
}
```

## 🔍 Explanation
1. **Node Class**
   - Each `Node` object stores an integer value and a pointer to the next node.
   - The `NextNode` pointer is initialized to `nullptr`.

2. **LinkedList Class**
   - Contains private members: `head`, `tail`, and `length`.
   - The constructor initializes a linked list with a single node.
   - Implements methods to print the list, get head, tail, and list length.

3. **Operations & Complexity**
   - **Adding at the End**: `O(1)` (Update tail pointer)
   - **Removing at the End**: `O(n)` (Traversal required)
   - **Adding at the Start**: `O(1)` (Update head pointer)
   - **Removing at the Start**: `O(1)` (Update head pointer)
   - **Searching by Value/Index**: `O(n)` (Requires traversal)

## 🎯 Summary
This project provides a simple **Linked List** implementation in C++. It demonstrates **dynamic memory allocation**, **pointer manipulation**, and **basic linked list operations**.

Stay tuned for more advanced linked list features such as **insertion, deletion, and searching!** 🚀

