#include <iostream>
using namespace std;

class GfG {
public:
    // Static data member
    static int i;
    // Static member function
    static void printMsg() { cout << "Welcome to GfG!"; }
    GfG(){
        // Do nothing
    };
};

int main() {
    // Invoking a static member function
    GfG::printMsg();
}


