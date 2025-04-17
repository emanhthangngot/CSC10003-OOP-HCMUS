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