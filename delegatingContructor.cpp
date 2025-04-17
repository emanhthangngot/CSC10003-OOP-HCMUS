#include <iostream>
using namespace std;

class A {
    int x, y, z;
public:
    A() : x(0), y(0), z(0) {}
    A(int z) : A() {
    this->z = z;
}
void show() {
    cout << x << '\n' << y << '\n' << z;
}
};

int main() {
    A obj(3);
    obj.show();
    return 0;
}