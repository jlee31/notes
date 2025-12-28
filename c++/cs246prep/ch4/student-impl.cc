#include "student.h"

// FUNCTIONS

float Student::grade() {
    return 0.4f * assns + 0.2f * mt + 0.4f * final;
}

int capGrade(int grade) {
    if (grade > 100)
        return 100;
    else if (grade < 0)
        return 0;
    else
        return grade;
}

// CONSTRUCTOR
// what is different with constructors is that they don't have a return type
//
Student::Student(int assns, int mt, int final) {
    this -> assns = assns;
    this -> mt = mt;
    this -> final = final;
}
