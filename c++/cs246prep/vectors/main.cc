#include <iostream>
#include <stdio.h>

// while we have arrays, adding and deleting items in a linked list is quite memory intensive
// arrays you have to declare space for , that you might not use
// one ADT like a Liinked List is created one at a time, but you have to track links in pointers (but it can get messy)
//

// STL - Standard Template Library
// it is a generic collection of lcass templates, algorithms and iterators that allow you to easily make queues, lists and stacks
// uses containers and container adapters

// the stl library don't give you many options to manipulate the functions

int main() {
    std::cout << "Hello world" << std::endl;

    std::vector<int> a(23);
    std::vector<int> z = {0,1,2,3,4};

    for (int i = 0; i < z.size(); i++) {
        std::cout << z.at(i) << ", ";
    }
    // an iterator is a method that looks around the memory to find each element in a vector
    // there are functions that tell you if you are at the end of a vector
    // there is begin, end, rbegin, rend

    // vectors sorting methods are very good
    //

    return 0;
}
