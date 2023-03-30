#include"DoubleStack.h"
#include <iostream>
using namespace std;

int main() {
	DoubleStack ts(8);
    ts.push0(1);
    ts.push0(2);
    ts.push0(3);
    ts.push0(4);
    ts.push1(5);
    ts.push1(6);
    ts.push1(7);
    ts.push1(8);
    
    ts.push0(555);
    ts.printAll();
    
    cout << "\nPopped element from stack0 is " << ts.pop0() << endl;
    cout << "\nPopped element from stack1 is " << ts.pop1() << endl;
    ts.printAll();
    return 0;
}