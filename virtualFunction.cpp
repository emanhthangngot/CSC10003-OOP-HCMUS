#include <iostream>
using namespace std;

class Base {
public:
    void show() {  // Không có virtual
        cout << "Base class function\n";
    }
    virtual void show2() {
        cout << "Base class function\n";
    }
};

class Derived : public Base {
public:
    void show() {  // Hàm có cùng tên nhưng không ghi đè thực sự
        cout << "Derived class function\n";
    }
};

class Derived2 : public Base {
public:
    void show2() {
        cout << "Derived class function\n";
    }
};

int main() {
    Base* bptr; // Con trỏ lớp cơ sở
    Derived d;
    
    bptr = &d;  // Trỏ đến đối tượng lớp dẫn xuất
    bptr->show();  // Gọi hàm show() 
    // Result : Base class function

    Base* bptr2;
    Derived2 d1;
    // Derived 2 have virtual function
    bptr2= &d1;
    bptr2->show2();
    // Result: Derived class function

    return 0;
}