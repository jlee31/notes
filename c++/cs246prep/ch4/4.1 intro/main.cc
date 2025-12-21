#include <iostream>
#include "student.h"

int main() {
    Student s{60, 70, 80};
    std::cout << s.grade() << std::endl;

    Student *p = new Student{50, 50, 50};
    std::cout << p->grade() << std::endl;
    delete p;

}
