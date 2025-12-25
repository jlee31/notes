#include <iostream>

class Node {
    public:
    int value;
    Node* next;

    // Creating the default constructor
    Node(int val = 0, Node *nxt = nullptr)
        : value { val }, next { nxt } {}

    // Destructor
    ~ Node() {
        delete next;
    }

    // Copy Constructor

    Node(const Node& other)
        : value (other.value),
        next (other.next ? new Node(*other.next): nullptr) {}

    // Copy Assignment
    Node& operator = (const Node& other) {
        if (this == &other) {
            return *this;
        }
        value = other.value;

        delete next;
        next = other.next ? new Node(*other.next) : nullptr;
        return *this;
    }

    // Move Constructor
    Node(Node && other) noexcept
        : value(other.value),
        next(other.next) {
            other.next = nullptr;
        }

    // Move Assignmnet Operator
    Node& operator=(Node&& other) noexcept {

            if (this == &other) {
                return *this;
            }

            value = other.value;
            delete next;          // Release current chain safely
            next = other.next;    // Take ownership
            other.next = nullptr; // Null out other's pointer
            return *this;

        }

    // Other Functions

    void print() const {
        const Node* curr = this;
        while (curr) {
            std::cout << curr->value << " ";
            curr = curr->next;
        }
        std::cout << "\n";
    }

};

int main() {
    Node* head = new Node(1, new Node(2, new Node(3))); // Create a list: 1→2→3 head->print(); // Output: 1 2 3
    head->next->print();
    Node copy = *head; // Deep copy: copy prints as 1 2 3 copy.print();

    Node moved = std::move(copy); // Move: moved prints 1 2 3; copy is now empty (safe!) moved.print();

    delete head; // Safely deletes entire chain: no memory leak!
}
