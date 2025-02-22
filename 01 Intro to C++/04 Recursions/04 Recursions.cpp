#include <iostream>
using namespace std;

void PlaceTrade(int trade) {
    if (trade > 0) {
        cout << "You've made a trade! \n";
        PlaceTrade(trade - 1);
        // function PlaceTrade takes in parameter trade
        // if the parameter is bigger than 0 then output you've made a trade
        // Invoke the function again but reduce trade by 1
        // this will keep repeating until trade is smaller than 0
        // this creates a function within a function
    }
}

int factorial(int num) {
    if (num > 1) {
        return num * factorial(num - 1);
    // returns num and calls the function again with a deincrement on num
    // if num is still greater than 1, then the process will repeat
    }
    else {
        return 1;
 
    }
}

       
    


int main()
{

    // recursion = a programming technique where a function invokes itself
    //            from within
    //            break a complex concept into a repeatable single step


    // advantages = less code and is cleaner
    //              useful for sorting and searching algorithms

    // disadvantages = uses more memory
    //                 slower



    PlaceTrade(10);
    cout << endl;
    cout << factorial(10);
    //invokes a function passing in a parameter 10
    return 0;
}
