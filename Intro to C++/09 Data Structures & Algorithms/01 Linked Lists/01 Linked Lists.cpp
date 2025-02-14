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

            cout << temp->value << " " << endl;
         // output the value that temp is pointing to

            temp = temp->NextNode;
        // move temp to the next node

        }

    }

    void append(int value) {

        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        // if linked list is empty, make head and tail equal newNode
        }
        else {
            tail->NextNode = newNode;
            tail = newNode;
        // otherwise make the current tails nextNode equal to NewNode and make tail the newNode
        }
        length++;
    
     
    }

   


    void DeleteLast() {
        if (length == 0) {
            return;
        }
        // if linkedlist is empty then return
        else {
            Node* Temp = head;
            Node* PreviousNode = head;

        // set 2 pointers equal to head
            while (Temp->NextNode) {
                PreviousNode = Temp;
                Temp = Temp->NextNode;
                // while temps next node isnt nullptr, set previousNode equal to temp

            }
            tail = PreviousNode;
        // once Temps next node becomes nullptr, the previous node should be the new tail so set tail = previous node

            tail->NextNode = nullptr;
        // cut the list off from the about-to-be-deleted node
            length--;
            if (length == 0) {
                head = nullptr;
                tail = nullptr;
            }
        // if the length of the list is now zero, set the tail/heads to be nullptr
            delete Temp;
        // finally delete temp
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

   

    void prepend(int value) {

        Node* newNode = new Node(value);
        if (length == 0) {

            head = newNode;
            tail = newNode;
        }
        else {
            newNode->NextNode = head;
            head = newNode;
        }
        length++;

    }

    void DeleteFirst() {

        if (length == 0) {
            return;
        }
        else {
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                head = head->NextNode;

            }
            delete temp;
            length--;
        }

    }

    Node* get(int index) {
    // create a node pointer that takes in an integer index
        if (index < 0 || index >= length) {
            // if index is smaller than 1 or is greater/larger than length
            return nullptr;
        }
        else {
            Node* temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->NextNode;
            }
            return temp;
            // return the temp pointer that points to the memory we want to get
        }
    }
    
    bool set(int index, int value) {

        Node* temp = get(index);

        // temp variable gets assigned the index of the function get
        if (temp) {
        // if temporary variable has an index the value of temp is equal to the value inside that temp

            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value) {

        if (index < 0 || index >=0) {
            return false;
        }
        if (index == 0) {
            prepend(value);
            return true;
        }
        if (index == length) {
            append(value);
            return true;
        }
        else {
            Node* newNode = new Node(value);
            Node* temp = get(index - 1);
            newNode->NextNode = temp->NextNode;
            temp->NextNode = newNode;
            length++;
            return true;
        }
        
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

   
    MyLinkedList->append(5);
    MyLinkedList->append(4);
    cout << "This is the current list: " << endl;
    
    MyLinkedList->PrintList();
    cout << endl;
    MyLinkedList->GetHead();
   
    cout << endl;
    MyLinkedList->GetLength();
   
    cout << endl;
    MyLinkedList->GetTail();
    cout << endl;


    MyLinkedList->DeleteLast();
    cout << "Linked List after deleting 1 value: " << endl;
    MyLinkedList->PrintList();
    cout << "Linked lists length after deleting that value - ";
    MyLinkedList->GetLength();
    cout << endl;
    cout << MyLinkedList->get(1);
    cout << endl;
    cout << endl;
    cout << endl;
}

