using namespace std;

#include <iostream>

class number {
public:
    int n;

    number(int set_n) {
        n = set_n;
    }
    number operator+(const number& numA) {
        return number(this->n + numA.n);
        //" this->n " represents the left number thats being added
        //" numA " represents the right number thats being added
    }

    number operator-(const number& numA) {
        return number(this->n - numA.n);
        //" this->n " represents the left number thats being added
        //" numA " represents the right number thats being added
    }

    bool operator== (const number& numA) {
        if (this->n == numA.n)
        // compares "this->n" to "numA.n" and if they match, return true
        // Else return false
            return true;
        else return false;
    }

};




int main() {


    number a(5);
    number b(10);
    number c = a + b;
    // after defining what "+" means in the constructor in the class "Number" a can be added to b
    cout << "c.n: " << c.n << endl;
    // this will output c being 15

    number d(15);
    number e(10);
    number f = d - e;
    cout << "f.n: " << f.n << endl;
    // this will use the "-" constructor

    if (a == f)
        cout << "a does equal c" << endl;
    else cout << "a does not equal c" << endl;
    

    if (a == b)
        cout << "a does equal b" << endl;
    else cout << "a does not equal b" << endl;
    return 0;


}

