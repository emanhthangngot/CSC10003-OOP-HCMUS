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
    cout << b1.author << endl; 
    Book b2("Story", "Tri Xuan", 100, 10.2);
    cout << b2.author << endl; // Tri Xuan
}