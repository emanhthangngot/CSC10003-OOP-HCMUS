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

       Fraction operator+(int num)  {
            int num1 = num * denominator + numerator;
            return Fraction(num1, denominator);
       }

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

        friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
            os << fraction.numerator << "/" << fraction.denominator;
            return os;
        }

};

int main() {
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    Fraction f3 = f1 + f2;
    cout << "f1: " << f1 << endl;
    // cout << "f2: " << f2 << endl;
    // cout << "f1 + f2 = " << (f3) << endl;
    // cout << "f1 - f2 = " << (f1 - f2) << endl;
    // cout << "f1 * f2 = " << (f1 * f2) << endl;
    // cout << "f1 / f2 = " << (f1 / f2) << endl;
    // cout << "f1 + 2 = " << (f1 + 2) << endl;
    cout << "++f1 = " << ++f1 << endl;  
    cout << "f1++ = " << f1++ << endl;
    cout << "f1: " << f1 << endl;
    return 0;
}