#include <iostream>
using namespace std;
/*

Text t;
Book *pb = &t;

^^^
expression: t, static type: Text, Dynamic Type: Text
expression: pb, static type: Text*, Dynamic Type: Points to a Text

Static Type : what the compiler sees at declaration
Dynamic Type : the actual object in memory

!!!

A virtual method will be called based on the dynamic type of the object that it is being called on.

- It enables polymorphism
- It enables behavior changesd based on an actual object
- Use virtual if you expect derives classes to change behaviour
- Use virtual if you will access objects with base pointers or references

*/

class Book {
    public:
    bool isHeavy() const {
        return false;
    }
    virtual bool virtual_is_heavy() const {
        return false;
    }
};

class Text : public Book {
    public:
        bool isHeavy() const {
            return true;
        }
        virtual bool virtual_is_heavy() const {
            return true;
        }
};

int main(void) {




    return 0;
}
