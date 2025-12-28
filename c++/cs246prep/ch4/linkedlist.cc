#include <iostream>

struct Node {
    int data;
    Node *next;
    Node (int data, Node *next) : data{data}, next{next} {}
};

int main() {
    return 0;
}
