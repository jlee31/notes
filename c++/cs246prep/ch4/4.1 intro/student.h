#ifndef STUDENT_H
#define STUDENT_H

struct Student {
    int assns, mt, final;
    float grade();
    Student(int assns = 0, int mt = 0 , int final = 0);
};

#endif
