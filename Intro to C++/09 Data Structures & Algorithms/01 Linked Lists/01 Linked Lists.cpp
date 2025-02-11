#include <iostream>

class Node {
public:
    int value;
    // this will be the value being assigned to Node
    Node* nextNode;
    // this will create a pointer called nextNode pointing to a node
    Node(int value) {
        this->value = value;
    // this will take whatever paremeter being entered within node and assigned to the variable "value"
        this->nextNode = nullptr;
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

        Node* newNode = new Node(value);
        // the constructer Node will be invoked with a paremeter(value) and will be assigned to the address pointer "newNode"
        head = newNode;
        // head will point to the address newNode
        tail = newNode;
        length = 1;


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
    
}

