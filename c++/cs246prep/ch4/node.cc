#include <iostream>

struct Node {
    int data;
    Node *next;

    // The regular Constructor
    Node(int data, Node *next) : data{data}, next{next} {}

    // Destructor (Acts recursively)
    ~Node () {
        delete next;
    }

    // Copy Constructor
    Node (const Node& other) {
        data = other.data; // or data{other.data}
        next = other.next ? new Node(*other.next) : nullptr; // or next{other.next}
        std::cout << "Copy Constructor Called" << std::endl;
    }

    // Copy Assignment Operator
    Node &operator=(const Node &other) {
        // Simple method with swap
        // Node tmp(other);
        // swap(tmp);
        // return *this;
        std::cout << "Copy Assignment Called" << std::endl;
        // Another way
        if (this == &other) {
            return *this;
        }
        Node *tmp = other.next ? new Node{*other.next} : nullptr;
        data = other.data;
        delete next;
        next = tmp;
        return *this;
    }

    // Move Constructor
    Node(Node &&other)
        : data(other.data), next(other.next) {
            std::cout << "Move ctor called" << std::endl;
            other.next = nullptr;
        }
    // Move Assignment Operator
    Node &operator=(Node &&other) {
        swap(other);
        std::cout << "Move Assignment Operator Called" << std::endl;
        return *this;
    }

    // Helper Functions
    void swap(Node &other) {
        std::swap(data, other.data);
        std::swap(next, other.next);
    }

};

Node plusOne(Node g) {
    for (Node *p=&g; p; p=p->next) {
        ++p->data;
    }
    return g; // this is a local variable that is about to be destroyed
    // it creates a return value object that will be passed back > calls the move constructor
}

void printNode(Node &n) {
    for (Node *p=&n; p; p=p->next) {
        std::cout << p->data << "->";
    }
    std::cout << std::endl;
}

int main() {
    Node n{1, new Node{2, new Node{3, nullptr}}};
    std::cout << "n: "; printNode(n);
    Node n2 = plusOne(n); // copy ctor takes a const Node &other
    std::cout << "n2: "; printNode(n2);
    // // &other is a l-value, it is allowed to be on the right side because it is const
    // // the compiler creates a temporary location to hold the tmp object plusOne(n), so other has something to point to
    // // temp object is destroyed once the construction is done
    // Node m{1, nullptr};
    // n = n2 = m = plusOne(n2);
    // Which is equivalent to n = (n2 = (m = plusOne(n2)));
    Node m{1, nullptr};
    n = (n2 = (m = plusOne(n2)));

/*
    1. copy constructor called 3 times when doing plusOne(n2)
    2. move constructor called after returning plusOne(n2)
    3. MAO called to move m = temp
    4. copy constructor called twice to copy into n2 = m
    5. CAO called to assign n2 onto m
    6. Copy constructor called twice to copy n2 chain
    7. CAO called to assign n onto n2

    CAO is called on the head node, constructor is called for the rest of the chain
    MAO just swaps the pointers
    The compiler uses The move constructor  to move g into the temp return value

    ** KEY DIFFERENCE **
    Node x = something; // construction (copy/move operator)
    x = something; // Assignment (copy/move assignment operator)

*/

    // std::cout << "n: "; printNode(n);
    // std::cout << "n2: "; printNode(n2);
    // std::cout << "m: "; printNode(m);

    return 0;
}

/*
Node n2 = plusOne(n);

```
**Step 1:** Call `plusOne(n)`
```

Stack frame created:
├─ Parameter g is copy-constructed from n
└─ g = [1] -> [2] -> [3]
```

**Step 2:** Increment values
```
g = [2] -> [3] -> [4]
```

**Step 3:** `return g;` - **Move constructor called here!**
```
Move constructor creates temporary:
├─ temporary.data = g.data        (2)
├─ temporary.next = g.next        (steals [3]->[4])
└─ g.next = nullptr               (leaves g safe)

Result:
├─ temporary: [2] -> [3] -> [4]
└─ g: [2] -> nullptr
```

**Step 4:** `g` is destroyed
```
delete g.next;  // Deletes nothing (g.next is nullptr)
Stack frame destroyed
```

**Step 5:** Initialize `n2` with the temporary
```
n2 = temporary;  // Often elided by compiler

*/
