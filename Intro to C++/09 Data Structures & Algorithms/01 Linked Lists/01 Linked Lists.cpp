#include <iostream>
using namespace std;

class Node {
public:
    int value;
    // this will be the value being assigned to Node

    Node* NextNode;
    // this will create a pointer called nextNode pointing to a node

    Node(int value) {

        this->value = value;
    // this will take whatever paremeter being entered within node and assigned to the variable "value"

        this->NextNode = nullptr;
    /*  this then assigns the "nextNode" variable as nullptr as this class is only used to create a node
        The other classes will define what the nextNode will point to depending on what class it is.
    */ 
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
        // the constructer Node will be invoked with a paremeter(value) and will be assigned to the address pointer "newNode"

        head = NewNode;
        // head will point to the address newNode

        tail = NewNode;
        length = 1;


    }

    ~LinkedList() {
        // the default destructor only deletes the head, tail and length
        // so we have to create a destructor to also delete the nodes

        Node* temp = head;
       
        while (head) {
            head = head->NextNode;
            delete temp;
            temp = head;
         // set a temporary pointer = to head and while head doesnt equal to node, set head = equal to the next node and delete temp
         // move temp equal to the new head.

        }
    }


    void PrintList() {
        Node* temp = head;
        //make a temporary pointer that holds the address that points to head

        while (temp) {
        // while temp doesnt equal to nullptr

            cout << temp->value << endl;
         // output the value that temp is pointing to

            temp = temp->NextNode;
        // move temp to the next node

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



int main()
{
    /*          Linked list : Contains a head and a tail
                Head points to the first node in the list
                Tail points to the last node in the list


                Adding a node at the end: O(1) since you just set the NULLptr to the new node 
                Removing a node at the end O(n) since it has to go through every node to delete a node that points to NULLptr
                
                Adding a node at the start: O(1) since you just set head to the new node and point that node to the original head
                Removing a node at the start: O(1) since you just remove the current head node and point to where it was pointing to

                Adding a node in the middle: O(n) since you have to iterate through the nodes to get there
                Removing a node in the middle: O(n) since you have to iterate through the nodes to get there

                Looking up by value: O(n) since you iterate through the nodes to find if the value exists
                Looking up by index: O(n) since you iterate through the nodes to search for the index

    */ 
    
    LinkedList* MyLinkedList = new LinkedList(4);

    MyLinkedList->GetHead();
    MyLinkedList->GetLength();
    MyLinkedList->GetTail();
    MyLinkedList->PrintList();
}

