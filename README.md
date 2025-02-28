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
## Taxonomy of member functions
- `Constructor`: an operation that creates a new instance of a class
- `Mutator`: an operation that changes the state of the data members of an object
- `Observer`: an operation that reports the state of the data members (aka Accessors, Getters)
- `Iterator`: an operation that allows processing of all the components of a data structure sequentially
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
```
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
```
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
```
Add this function to above program so that we can calculate 
Fraction operator+(int num)  {
    int num1 = num * denominator + numerator;
    return Fraction(num1, denominator);
}
```
3. Implement prefix and postfix increment: x++ and ++x. Hint: using dummy int
```
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