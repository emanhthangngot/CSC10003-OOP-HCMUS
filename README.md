# OOP
This is my journey learning OOP in second semester in HCMUS 
I begin in 27th February 2025 
## Resources
- [https://www.learncpp.com/](https://www.learncpp.com/), chapter 13. 14. 16, 17, 18, 19
- Phương pháp lập trình hướng đối tượng - *Đinh Bá Tiến, Lê Khánh Duy, Phạm Nguyễn Sơn Tùng, Mai Anh Tuấn*
- C++ Object Oriented Programming
# C++
### Object and classes
- UML(**Unified Modeling Language**)
```cpp
 #include <iostream>
 using namespace std;
 ////////////////////////////////////////////////////////////////
 class Date             //define a class
 {
    private:
        int iDay, iMonth, iYear;
    public:
        Date(); 
        Date(int iNewDay, int iNewMonth, int iNewYear); 
        int getDay();  // return day 
        int getMonth();  // return month 
        int getYear();  // return year
 };
///////////////////////////////////////////////////////
 int main() {
    Date today(20, 10, 2008); 
    Date tomorrow, someDay; 
    // can I do this? 
    cout << today.iMonth; 
    // how about this? 
    cout << today.getMonth(); 
 }
```
- Private data or functions can only be accessed from within the class
- The data items within a class are called **data members** (or sometimes member data)
-  **Member functions** are functions that are included within a class. (also methods)
## Access spectifiers 
- `public`: can be accessed by anyone.
- `private`: can only be accessed by other members of the class or friends.
- `protected`: can be accessed by other members of the class, friends, and derived classes.
## Encapsulation and data hiding
- Encapsulation
    - A C++ class provides a mechanism for 
    packaging data and the operations that may be 
    performed on that data into a single entity
- Information hiding 
    - A C++ class provides a mechanism for specifying access

## Static
Static memeber variables are shared by all objects of the class
```
class Bruh {
private:
    static int count; // Biến đếm số lượng đối tượng của class Bruh
public:
    static int show() { return count; }
    Bruh() { count++; }
    ~Bruh() { count--; }
};
int Bruh::count = 0;
int main() { 
    Bruh a, b; 
    // Bruh::show() will return 2 
}
```
### Static variable
As the variables declared as static are initialized only once as they are allocated space in separate static storage so, the static member variables in a class are shared by the objects. There cannot be multiple copies of the same static variables for different objects. Also because of this reason static variables cannot be initialized using constructors
```
#include <iostream>
using namespace std;

class GfG {
public:
    // Static data member
    static int i;

    GfG(){
        // Do nothing
    };
};

// Static member inintialization
int GfG::i = 1;

int main() {
  
    // Prints value of i
    cout << GfG::i;
}
```
The static data members can be used to implement the following:
- Counting Objects of a Class
- Store and share configuration or settings globally.
- Tracking Shared Resources
- Regulate or limit operations performed by multiple objects.
- Ensure a class has only one instance by using static members.

### Static Member Functions in a Class
Static member functions are allowed to access only the static data members or other static member functions, they cannot access the non-static data members or member functions of the class
```
#include <iostream>
using namespace std;

class GfG {
public:
    // Static member function
    static void printMsg() { cout << "Welcome to GfG!"; }
};

int main() {
    // Invoking a static member function
    GfG::printMsg();
}

```

### Const member function
- Is a member function that guarantees it will not modify the object or call any non-const member functions (as they may modify the object)
- Append the `const` keyword to the funnction prototype, after tthe parameter list, before the function body
```
int Bruh(int lmao) const {}
```
- For member functions defined outside of the class definition, the const keyword must be used on both the **function prototype** in the class definition and on the **function definition**
```
class Bruh {
public:
    int lmao() const; 
};
int Bruh::lmao() const {
    return lmao;
}
```
- Best practice: **Make any member function that does not modify the state of the class object const, so that it can be called by const objects**
  
The below C++ code demonstrates how to define constant member functions outside the class definition and showcases the usage of a constant member function to set and retrieve the value of a private member variable
```
// Constant member function defined outside the class
#include <iostream>
using namespace std;

class Demo {
    int x;

public:
    void set_data(int);

    // const member function
    int get_data() const;
};

// Function definition for setting the value of x.
void Demo::set_data(int a) { x = a; }

// Function definition for retrieving the value of x (const
// member function).
int Demo::get_data() const { return x; }

main()
{
    Demo d;
    // Set the value of x to 10 using the non-const member
    // function.
    d.set_data(10);
    // Print the value of x using the const member function.
    cout << d.get_data(); // 10

    return 0;
}

```
The below C++ program demonstrates that const functions can be called by non-const objects.
```
// C++ program to demonstrate that const functions can be
// called by non const objects

#include <iostream>
using namespace std;

class Test {
    int value;

public:
    Test(int v = 0) { value = v; }

    // const member function
    int getValue() const { return value; }
};

int main()
{
    // non const object
    Test t(20);
    cout << t.getValue(); // 20
    return 0;
}

```




## Taxonomy of member functions
- `Constructor`: an operation that creates a new instance of a class
- `Mutator`: an operation that changes the state of the data members of an object
- `Observer`: an operation that reports the state of the data members (aka Accessors, Getters)
- `Iterator`: an operation that allows processing of all the components of a data structure sequentially


## Constructor & Destructor
- Constructor is a physical piece of code (in fact, it is a special type of method) that is used to construct and initialize objects.
- It is automatically invoked when a new object is created.
- There is no returned value, even a void.
- A class can have many constructors (overload)
- Name of the constructors must be the same class name
### Copy Constructor
```cpp
#include<iostream>
using namespace std;

class Book {
    public:
        string title;
        string author;
        int pages;
        double prices;

        Book() {
            title = "Unknown Title";
            author = "Unknown Author";
            pages = 0;
            prices = 0.0;
        }
        ~Book() {
            cout << "The book was destroyed\n";
        }
        Book(string title, string author, int pages, double prices) {
            this->title = title;
            this->author = author;
            this->pages = pages;
            this->prices = prices;
            }
};

int main() {
    Book b1;
    cout << b1.author << endl; // Unknown Author
    Book b2("Story", "Tri Xuan", 100, 10.2);
    cout << b2.author << endl; // Tri Xuan
}
```
- If there is at least one construtor, the default constructor will not be created by the compiler
- They allow users different options to create a new object
```cpp
class Date {
public:
   Date();
   Date(int, int);
   Date(int, int, int);
   …
private:
   int iDay, iMonth, iYear;
};
```
####  The **this* pointer
- **this pointer* is a hidden const pointer (can change the value oof the object it points to, but can not make it point to something else) that holds the address of the object the member function was called on
- All non-static member functions have a "this" pointer
- "this" always points to the object being operated on, and because "this" is just a function parameter, it doesn't add any memory usage to class
- Use to makke function chainable. Most often used when overloading operators for classes.
```cpp
#include<iostream>
class Calc {
    private:
        int m_value;
    public:
        Calc(): m_value(1) {}
        Calc& add(int value) { 
            m_value += value; 
            return *this; 
        }
        Calc& sub(int value) {
            m_value -= value; 
            return *this;
        }
        Calc& mult(int value) {
            m_value *= value; 
            return *this;
        }
        int get() {
            return m_value;
        }
};
int main() {
    Calc calc;
    calc.add(5).sub(3).mult(4); // returning *this, reference to calc
    std::cout << calc.get(); // = 12
}
```

### Destructor
- Invoked automatically, when the variable is removed from memory (e.g. goes out of scope).
- Each class can have at most one destructor
- The destructor name is a name of a class preceded by a tilde sign (~).
- Destructor, the same as constructor, has no return type (even void)
- Destructor frees the resources used by the object (allocated memory, file descriptors, semaphores etc.)
```cpp
class MyArray {
 public:
   MyArray();
   ~MyArray() {
   n = 0;
   delete [] pArr; 
   pArr = NULL;
   }
 private:
   int n;
   int *pArr;
 };
```
- You don’t need to write a destructor if your class has nothing to clean up.
- If you are using resources, for example dynamic memory allocation, and you forget to have your destructor, the program will create the memory leaking.

### Delegating constructors (constructor chaining)
Constructors are allowed to call other constructors from the same class
```
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
    obj.show(); // 0 0 3
    return 0;
}
```

### Members Initialization
```cpp
 class Date {
 public:
   Date();
   Date(int iNDay, int iNMonth, int iNYear)
: iDay(iNDay), iMonth(iNMonth), iYear(iNYear) {}
   ~Date(); 
   …
 private:
   int iDay, iMonth, iYear;
 };
```
- Mandatory Member Initialization
    - Const members
    - References
    - Sub-objects which require arguments in constructors
    ```cpp
    class Test
    {
    private:
        Another& refA; // reference member
        const int MAX; // const member 
        vector arr;
    public:
        Test(Another& r) : refA(r), MAX(100), arr (MAX) {}
    };

    ```

## Operator Overloading
### Overloading
- There are many different 'definitions' for the same name
- In C++, overloading functions are differentiated by their signatures 
### Operator Overloading
- To define operator implementations for our new user-defined types
- When we have a new data type Fraction we need to define new operator implementations to work with it
**Note**:
  - Operator `::` or `.` or `.*` cannot be defined by users
  -  Operators `sizeof`, `typeid`, `?`: cannot be overloaded
  -  Operators `=`, `->`, `[]`, `()` can only be overloaded by non-static functions
#### Syntax
Syntax: `<returned-type> operator<op> (arguments)`
Example:
```cpp
bool FullName::operator==(const FullName& rhs) {
    return ((sFirstName==rhs.sFirstName) && (sSurName==rhs.sSurName))
int main() 
{ 
   FullName s1, s2; 
   if (s1 == s2)    // s1.operator==(s2) 
    { 
        ... 
    } 
        ... 
    } 
}
```
#### Exercise:
1. Implement a Fraction class with basic arithmetic operators: +, -, *, /
```cpp
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
class Fraction {
    private:
        int numerator;
        int denominator;
        // Function to simplify the fraction
        void simplify() {
            int gcd = __gcd(numerator, denominator);
            numerator /= gcd;
            denominator /= gcd;
            if (denominator < 0) { // Ensure denominator is always positive
                numerator = -numerator;
                denominator = -denominator;
            }
        }
    public:
        // Constructors
        Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
            if(denominator == 0) {
                throw invalid_argument("Denominator cannot be zero");
            }
            simplify();
        }

        // Overloading the + operator
        Fraction operator+(const Fraction &others) {
            int num = numerator * others.denominator + others.numerator * denominator;
            int dem = denominator * others.denominator;
            return Fraction(num, dem);
        }

        // Overloading the - operator
        Fraction operator-(const Fraction &others) {
            int num = numerator * others.denominator - others.numerator * denominator;
            int dem = denominator * others.denominator;
            return Fraction(num, dem);
        }

        // Overloading the * operator
        Fraction operator*(const Fraction &others) {
            int num = numerator * others.numerator;
            int dem = denominator * others.denominator;
            return Fraction(num, dem);
        }

        // Overloading the / operator
        Fraction operator/(const Fraction &others) {
            int num = numerator * others.denominator;
            int dem = denominator * others.numerator;
            return Fraction(num, dem);
        }

        friend ostream& operator<<(ostream& os, const Fraction& fraction) {
            os << fraction.numerator << "/" << fraction.denominator;
            return os;
        }

};

int main() {
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    cout << "f1: " << f1 << endl;
    cout << "f2: " << f2 << endl;
    cout << "f1 + f2 = " << (f1 + f2) << endl;
    cout << "f1 - f2 = " << (f1 - f2) << endl;
    cout << "f1 * f2 = " << (f1 * f2) << endl;
    cout << "f1 / f2 = " << (f1 / f2) << endl;
}
```
2. Remember to handle: 
Fraction x, y; 
y = x + 5; 
y = 5 + x;
```cpp
Add this function to above program so that we can calculate 
Fraction operator+(int num)  {
    int num1 = num * denominator + numerator;
    return Fraction(num1, denominator);
}
```
3. Implement prefix and postfix increment: x++ and ++x. Hint: using dummy int
```cpp
// Prefix Increment (++x)
    Fraction& operator++() {
        numerator += denominator; // Add 1 to the fraction
        simplify();
        return *this; // Return updated object
}

// Postfix Increment (x++)
    Fraction operator++(int) {
        Fraction temp = *this; // Store original value
        numerator += denominator; // Increment fraction
        simplify();
        return temp; // Return original value
}

```
## Inheritance
### Type of inheritance
- **public**: public and protected of the base class become public and protected of the derived class.  
- **protected**: public and protected of the base class become protected of the derived class.  
- **private**: public and protected of the base class become private of the derived class

### Constructor in inheritance
When a new object of a derived class is created
- The constructor of the base class is invoked first.
- Then, the constructor of the derived class is invoked 
-  In the constructor of the derived class, we can specify which constructor of the base class is called. Otherwise, the default constructor of the base class will be invoked
  
Sometimes we need to redefine the member functions of the base class in the derived class

***Notes***: **this re-definition will hide the other overloading member functions of this function from the base class**
Ex1:
```cpp
class A {
    public:
        void test();
        void test(int);
        void test(int, int);
        ...
};

class B : public A {
    public:
        void test(int);
};

int main() {
    B b; 
    int x, y; 
    ... 
    b.test(x); // OK 
    b.test(x, y); //error
}
```

Ex2:
```cpp
class A { 
public: 
    void test(); 
    void test(int); 
    void test(int, int); 
    ... 
}; 
class B : public A 
{ 
public: 
    using A::test; 
    void test(int); 
};

int main() 
{ 
    B b; 
    int x, y; 
    ... 
    b.test(x); // OK 
    b.test(x, y); //OK 
... 
}
```
### Pure virtual function
```cpp

class Animal {
public:
    virtual void talk() = 0;
};

int main() {
    Animal a;
    a.talk();  // error: abstract class 
}
```
Any class with one or more pure functions becomes an **abstruct base class**

### Interface classes
An interface class is a class that has no member variables, and where all of the functions are pure virtual.
```cpp
class IBruh {
public:
    virtual void Bruh() = 0;
    virtual ~IBruh() {} // virtual destructor
};
```



## Polymorphism
### Virtual functions
- A **virtual function**    is a special type of function that called, resolve to the most-derived version of the function that exists between the base and derived class. This capability is known as polymorphism. A derived function is considered a match if it has the same signature as the base version of the function. Such functions are called overrides.
```cpp
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
```
- Virtual function resolution only works when a member function is called through a pointer or reference to a class type object
- If a function id virtual, all matching overrides in derived classes are implicitly virtual
- There may be cases when you dont want so to be able to overide a virtual function or inherit from a class the `final specifier` can be used to tell the compiler to enforce this
```cpp
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
```

