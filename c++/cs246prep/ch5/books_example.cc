#include <iostream>
#include <vector>
using namespace std;

// Superclass : The book

class Book {
    protected :
        int length;

    public :
        // Constructor
        Book(int length) : length(length) {}
        // Virtual Method
        virtual bool isHeavy() const {
            return length > 200;
        }
        // Virtual Descructor
        virtual ~Book() {}
};

// Subclass

class Text : public Book {
    public :
        // Constructor
        Text(int length) : Book(length) {}

        // Rewriting the virtual Method
        virtual bool isHeavy() const override { // override here is used to check during compile time if the method is actually virtual
            return length > 500;
        }
};

int main(void) {
    // Creating some objects
    Book novel(350);
    Text textbook(450);
    Text hugeTextbook(1200);

    // Storing the items with pointers
    vector<Book*> library;
    library.push_back(&novel);
    library.push_back(&textbook);
    library.push_back(&hugeTextbook);

    // Using Polymorphism
    for (Book* book : library) {
        cout << (book->isHeavy() ? "Heavy" : "Not Heavy") << endl;
    }
    // without virtual, they would read the basee class pointer or reference because it only looks at the static type
    return 0;
}
