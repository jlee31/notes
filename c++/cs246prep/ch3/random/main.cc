#include <iostream>
#include <stdio.h>
#include <string>

int main() {

    // Uniform initialization syntax

    int x { 5 };
    std::string s{ "hello" };

    std::string name;
    std::cin >> name;

    std::cout << x << " " << name << std::endl;

    // Node *ptr = new Node { 10, nullptr };

}
