// https://www.youtube.com/watch?v=0NwsayeOsd4 <- youtube video

#include <iostream> // For input/output operations like std::cout and std::cin
#include <string>
#include <vector>

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

// static methods -- functions somehow related to a Person 

// constructors -- instantiates objects from your class

class Person{
    private:
    std::string first;
    std::string last;
    // if you change private to protected, inherited subclasses can
    // access first and class individually

    public:
    // Person(std::string first, std::string last): first(first), last(last) {} // <- this is the constructor
    // constructor
    Person(std::string first, std::string last) {
        this->first = first;
        this->last = last;
    } // another way to set a constructor 
    Person() = default;
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

    static void printPeople(std::vector<Person*> people) {
        for (auto person: people) {
            person->printFullName();
        }
    }

};

class Employee : public Person{ // now Employee INHERITS from person
// if you don't include the "public" part, all the public stuff in the Person class turns private

    private:
    std::string department;

    public:
        Employee(std::string firstName, std::string lastName, 
            std::string department)
        : Person(firstName, lastName), department(department) {} //constructor

        std::string getDepartment() {
            return department; // GETTER
        }
    void setDepartment(std::string department) {
        this->department = department;
    } // SETTER


    void printInfo() {
        std::cout << "name: " << getName() << std::endl;
        std::cout << "department: " << getDepartment() << std::endl;
    }

}; 


int main() {
    
    std::vector<Person*> people;

    Person p("Joseph", "Lee");
    
    // p.printFullName();
    // std::cout << p.getName() << std::endl;

    Person p2; // using default allows you to have something without setting parameters

    Employee e("Rob", "Bob", "Food"); // Polymorphism is happening where employee is treated as a Person in the People* vector
    // e.printInfo();

    people.push_back(&p);
    people.push_back(&e); // adding 2 people to a person vector

    Person::printPeople(people); // now you can print this multiple times
    // you are invoking it through the Person class

    return 0;
}    