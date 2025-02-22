#include <iostream>
#include <memory>  // Required for smart pointers

using namespace std;

class Node {
public:
    int value;
    // this will be the value being assigned to Node

    unique_ptr<Node> NextNode;
    // this will create a smart pointer to the next node

    Node(int value) {
        this->value = value;
        this->NextNode = nullptr;
    }
};

class LinkedList {

private:
    unique_ptr<Node> head;
    Node* tail;  // tail is now a unique_ptr as well
    int length;

public:
    LinkedList(int value) {
        head = make_unique<Node>(value);
        tail = head.get();  // Move ownership to tail as well
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
