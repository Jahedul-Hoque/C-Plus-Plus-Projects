
# 📌 Linked List Implementation in C++

## 📖 Overview
This repository contains a custom implementation of a **Singly Linked List** in C++. The implementation utilizes **smart pointers** (`unique_ptr`) for efficient memory management and to prevent memory leaks. The list supports common operations such as **append**, **prepend**, **insert**, **delete**, and **get**.

## 📌 Key Concepts
- **Unique Pointer**: The list uses `std::unique_ptr` for dynamic memory allocation, ensuring automatic memory management and preventing memory leaks.
- **Node Structure**: Each node contains an integer value and a pointer to the next node in the list.
- **Dynamic Memory Management**: The memory is allocated and deallocated dynamically using smart pointers, which automatically handle memory cleanup.
- **Operations**: The linked list supports operations such as adding, removing, updating, and accessing nodes.

## 💻 Code Implementation
```cpp
#include <iostream>
#include <memory>  // Required for smart pointers

using namespace std;

class Node {
public:
    int value; // The value stored in the node
    unique_ptr<Node> NextNode; // Smart pointer to the next node

    Node(int value) {
        this->value = value;
        this->NextNode = nullptr;
    }
};

class LinkedList {

private:
    unique_ptr<Node> head;
    Node* tail;  // tail is now a raw pointer
    int length;

public:
    LinkedList(int value) {
        head = make_unique<Node>(value);
        tail = head.get();  // Move ownership to tail
        length = 1;
    }

    ~LinkedList() {
        // Destructor will automatically clean up the list due to unique_ptr
    }

    void PrintList() {
        Node* temp = head.get();
        while (temp) {
            cout << temp->value << " " << endl;
            temp = temp->NextNode.get();  // Move to the next node
        }
    }

    void append(int value) {
        auto newNode = make_unique<Node>(value);
        if (length == 0) {
            head = move(newNode);
            tail = head.get();  // Update tail to point to head
        }
        else {
            tail->NextNode = move(newNode);
            tail = tail->NextNode.get();  // Move tail to point to the new node
        }
        length++;
    }

    void DeleteLast() {
        if (length == 0) return;

        Node* temp = head.get();
        Node* previousNode = nullptr;

        while (temp && temp->NextNode) {
            previousNode = temp;
            temp = temp->NextNode.get();
        }

        if (previousNode) {
            previousNode->NextNode = nullptr;
            tail = previousNode;
        }
        else {
            head = nullptr;
            tail = nullptr;
        }
        
        length--;
    }

    void GetHead() {
        if (head) {
            cout << "Head: " << head->value << endl;
        }
    }

    void GetTail() {
        if (tail) {
            cout << "Tail: " << tail->value << endl;
        }
    }

    void GetLength() {
        cout << "Length: " << length << endl;
    }

    void prepend(int value) {
        auto newNode = make_unique<Node>(value);
        if (length == 0) {
            head = move(newNode);
            tail = head.get();
        }
        else {
            newNode->NextNode = move(head);
            head = move(newNode);
        }
        length++;
    }

    void DeleteFirst() {
        if (length == 0) return;

        Node* temp = head.get();
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = move(head->NextNode);
        }
        
        length--;
    }

    Node* get(int index) {
        if (index < 0 || index >= length) return nullptr;

        Node* temp = head.get();
        for (int i = 0; i < index; i++) {
            temp = temp->NextNode.get();
        }
        return temp;
    }

    bool set(int index, int value) {
        Node* temp = get(index);
        if (temp) {
            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value) {
        if (index < 0 || index > length) return false;

        if (index == 0) {
            prepend(value);
            return true;
        }
        if (index == length) {
            append(value);
            return true;
        }
        else {
            auto newNode = make_unique<Node>(value);
            Node* temp = get(index - 1);
            newNode->NextNode = move(temp->NextNode);
            temp->NextNode = move(newNode);
            length++;
            return true;
        }
    }

    void deleteNode(int index) {
        if (index < 0 || index >= length) return;

        if (index == 0) {
            DeleteFirst();
        }
        else if (index == length - 1) {
            DeleteLast();
        }
        else {
            Node* pre = get(index - 1);
            Node* temp = pre->NextNode.get();
            pre->NextNode = move(temp->NextNode);
            
            length--;
        }
    }
};

int main() {
    LinkedList* MyLinkedList = new LinkedList(4);

    MyLinkedList->append(2);
    MyLinkedList->append(1);
  
    MyLinkedList->insert(3, 67);
    MyLinkedList->insert(1, 67);
    MyLinkedList->DeleteLast();
    MyLinkedList->PrintList();

    delete MyLinkedList;
}
```

## 🔍 Explanation
1. **Node Class**: Represents each element in the list, holding an integer value and a pointer to the next node.
   - The `NextNode` is managed via a `std::unique_ptr`, ensuring automatic memory management.

2. **LinkedList Class**:
   - **head**: The start of the list, managed by `unique_ptr`.
   - **tail**: A raw pointer to the last node.
   - Operations like `append`, `prepend`, `insert`, `delete`, and `get` are implemented for list manipulation.

3. **Memory Management**:
   - The list ensures memory is dynamically allocated and automatically cleaned up due to the use of `unique_ptr`.

4. **Main Operations**:
   - **append**: Adds a node to the end of the list.
   - **prepend**: Adds a node at the beginning.
   - **insert**: Inserts a node at a specific index.
   - **deleteNode**: Removes a node from the list.

## 🚀 Advantages of This Approach
✅ **Efficient Memory Management** using `std::unique_ptr`.
✅ **Low Latency**: The implementation is optimized for time-sensitive operations, suitable for environments like hedge funds.
✅ **Automatic Cleanup**: The use of `unique_ptr` ensures memory is automatically freed without the need for manual memory management.

## ⚠️ Potential Pitfalls
❌ **Manual Tail Management**: While the list uses `unique_ptr` for head nodes, the tail is a raw pointer, requiring manual updates when nodes are added or removed.
❌ **Linked List Performance**: While linked lists offer flexibility, they may not always be as performant as arrays in certain scenarios.

## 🎯 Best Practice
Always ensure that dynamically allocated memory is handled properly. The use of `std::unique_ptr` makes it easier to avoid memory leaks.

---

🛠️ **Happy Coding!** 🚀
