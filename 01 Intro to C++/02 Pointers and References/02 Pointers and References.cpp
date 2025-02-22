#include <iostream>
using namespace std;

int main()

{
   
    //pointers = variable that stores a memory address of another variable 
    //           sometimes it's easier to carry the address of something instead of carrying the whole thing
    // & address-of operator
    // * dereference operator

    string name = "Jad";
    string *ReferenceName = &name;
    //initialises a memory address called "ReferenceName" and gives it the value of the variable "name"
    cout << "My name is " << ReferenceName << endl;
    //when outputting this, it will give you the memory address of "ReferenceName" not the value itself
    cout << "My name is " << *ReferenceName << endl;
    //this will output the value of whats inside the memory address "ReferenceName"
    cout << endl;

    int age = 23;
    int *ReferenceAge = &age;
    //when outputting this, it will give you the memory address of "ReferenceAge" not the value itself
    cout << "My age is " << ReferenceAge << endl;
    //this will output the value of whats inside the memory address "ReferenceAge"
    cout << "My age is " << *ReferenceAge << endl;
    cout << endl;

    string FreePizzas[5] = { "Pizza 1", "Pizza 2", "Pizza 3", "Pizza 4", "Pizza 5" };
    //initialises an array with 5 elements
    string *ReferencePizza = FreePizzas;
    //you dont need to use & for arrays as they will already print memory address by default when printing arrays
    cout << "I'm giving out 5 pizzas, this is your " << ReferencePizza << endl;
    //this will give out the memory address of the "ReferencePizza" as we didnt use the * symbol to deference the address
    cout << "I'm giving out 5 pizzas, this is your " << *ReferencePizza << endl;
    //this will give out the value of the first ReferencePizza

    cout << endl;

    int* pointer = nullptr;
    //gives the pointer value null meaning empty
    int x = 10;

    pointer = &x;
    //assigns pointer the memory address of x

    if (pointer == nullptr) {
        cout << "Pointer was not assigned";
    }
    else cout << "Pointer was assigned";
    //since we gave pointer the memory address of x, this should print out that pointer was assigned
    
    cout << endl;

    pointer = nullptr;
    //assigns pointer the memory address of null pointer

    if (pointer == nullptr) {
        cout << "Pointer was not assigned";
    }
    else cout << "Pointer was assigned";
    //since we gave pointer the memory address of nullptr, this should print out that pointer wasnt assigned

    cout << endl;
};
