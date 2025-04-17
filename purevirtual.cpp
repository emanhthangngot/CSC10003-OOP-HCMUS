#include<iostream>
using namespace std;

class Animal {
public:
    virtual void talk() = 0;
};

int main() {
    Animal a;
    a.talk();
}