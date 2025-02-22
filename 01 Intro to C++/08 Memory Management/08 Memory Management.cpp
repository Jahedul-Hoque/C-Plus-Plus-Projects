using namespace std;
#include <iostream>





int main()
{
    // Dynamic Memory = Memory that is allocated after the program is already
    //                  compiled and running.
    //                  Use the 'new' operater to allocate memory in the heap
    //                  rather than the stack.
                                      
    //                  Useful when we don't know how much memory is needed.
    //                  Makes programs more flexible, especially when
    //                  accepting user input.



    int* ReferenceNum = NULL;
    // initialising a reference variable that points to a memory address of NULL
    ReferenceNum = new int;
    // using the Reference variable and given it an integer value that we can assign later
    *ReferenceNum = 21;
    // Dereferencing the variable ReferenceNum and giving the actual value of the address "21"

    cout << "The Address of ReferenceNum: " << ReferenceNum << endl;
    cout << "The Value of ReferenceNum: " << *ReferenceNum << endl;

    delete ReferenceNum;
    // This frees up the memory space in this address


    int * Trades = NULL;
    //creates a memory address called Trades which has no memory space
    int size;
    cout << "How many trades did you want to enter?: ";
    cin >> size;

    Trades = new int[size];
    //initialises the previous memory address with the amount of numbers needed from user input

    for (int i = 0; i < size;i++) {
        cout << "Enter Trade Price #" << i+1 << ": ";
        cin >> Trades[i];
    // for every trade entered, populate the array with the user input
    }

    for (int i = 0; i < size; i++) {
        cout << "$"<< Trades[i] << " ";
    // output all the values within the memory address space mentioned
    }

    delete[] Trades;

}

