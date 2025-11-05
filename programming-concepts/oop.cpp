// https://www.youtube.com/watch?v=0NwsayeOsd4 <- youtube video

#include <iostream> // For input/output operations like std::cout and std::cin
#include <string>

// class - describe the structure
// object - a specific example of the structure (aka an instance)
// data members - variables
// methods - functions
// instantiating - create an object from a class

// pillars of oop: encapsulation, inheritance, polymorphism, and abstraction

// abstraction -- making something easy by hiding the functionality
// encapsulation -- granting access to private data only through controlled public interfaces
// inheritance -- creating devired classes that inheric properties from their parent classes
// polymorphism -- treating multiple different objects as their base object type

class Person{
    private:
    std::string first;
    std::string last;

    public:
    void setFirstName(std::string firstName) {
        first = firstName;
    }
    void setLastName(std::string last) { // if you want param to be the same name as the value
        this->last = last; // you have to assign it with ->
    }
    std::string getName(){ 
        return first + " " + last;
    } // from this function, they can only GET the full name, but cannot get the individal first and last name
    void printFullName(){ std::cout << first << " " << last << std::endl; }
};


int main() {
    
    Person p;
    p.setFirstName("Joseph");
    p.setLastName("Lee");
    p.printFullName();
    std::cout << p.getName() << std::endl;


    std::cout << "Hello, C++!" << std::endl; // Example output

    return 0; // Indicates successful program execution
} 