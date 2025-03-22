#include<iostream>
using namespace std;

class Base {
    public:
        void print() {
            cout << "Hello World \n";
        }
};

class Derived final : public Base {
    public:
        void print() {
            cout << "Hello World Tri is my name\n";
        }
};

class Derived2 : public Derived {
    public:
        void print() {
            cout << "Hello World, Hello Class\n";
        }
};

int main() {
    Base b;
    Derived d;
    Derived2 d1;
    b.print(); // Hello World
    d.print(); // Hello World Tri is my name
    // d1.print(); error
}