#include<iostream> // Include input/output stream library for cout, cin, endl
using namespace std; // Use standard namespace to avoid writing std:: prefix

// Class demonstrating the Rule of Five for proper resource management
class Foo
{
    private:
    int* array, size; // Pointer to dynamically allocated array and its size (Note: should be int *array, size;)

    public:
    // Regular constructor: creates a Foo object with array of given size
    Foo(int s)
    {
        size = s; // Store the size parameter
        array = new int[size] {0}; // Allocate array on heap, initialize all elements to 0
    }


    // Copy constructor: creates a new Foo as a deep copy of another Foo
    // Called when: Foo f(g); or Foo f = g; where g is an existing Foo
    Foo(const Foo& rhs) // rhs = "right hand side", const prevents modification
    {
        cout << "Copy constructor executes." << endl; // Debug message to track when this runs
        size = rhs.size; // Copy the size from source object
        array = new int[size]; // Allocate NEW memory (deep copy, not sharing pointer)

        for(int i = 0; i < size; i++) // Loop through all elements
            array[i] = rhs.array[i]; // Copy each element individually
    }

    // Move constructor: transfers ownership from temporary (r-value) object
    // Called when creating object from temporary, like: Foo f = createFoo();
    Foo(Foo&& rhs) noexcept // && means r-value reference, noexcept promises no exceptions
    {
        cout << "move constructor executes." << endl; // Debug message
        size = rhs.size; // Copy the size value
        array = rhs.array; // STEAL the pointer (shallow copy, taking ownership)
        rhs.array = nullptr; // Set source pointer to null so its destructor won't delete our array
    }

    // Destructor: cleans up dynamically allocated memory when object is destroyed
    ~Foo()
    {
        if(array) // Check if pointer is not null (could be null after move)
            delete [] array; // Free the dynamically allocated array
    }

    // Operator+ overload: concatenates two Foo objects into a new one
    // Called when: f + g; creates temporary r-value result
    Foo operator+(const Foo& rhs)
    {
        Foo temp(size + rhs.size); // Create temporary Foo with combined size

        auto i = 0; // Index variable, auto deduces type as int
        for(; i < size; i++) // Copy elements from left operand (this object)
            temp[i] = array[i]; // Use overloaded [] operator to assign

        for(auto j = 0; j < rhs.size; i++, j++) // Copy elements from right operand
            temp[i] = rhs.array[j]; // j indexes rhs, i continues from previous loop

        return temp; // Return by value, triggers move constructor (temp is r-value)
    }

    // Copy assignment operator: assigns one existing Foo to another
    // Called when: f = g; where both f and g already exist
    Foo& operator=(const Foo& rhs) // Returns reference to allow chaining (a = b = c)
    {
        cout << "Copy assignment operator executes." << endl; // Debug message
        if(this == &rhs) // Check if assigning object to itself
            return *this; // Return early to avoid unnecessary work

        if(array) // Check if this object has allocated memory
            delete [] array; // Delete old array to prevent memory leak

        size = rhs.size; // Copy the size
        array = new int[size]; // Allocate new memory

        for(int i = 0; i < size; i++) // Loop through all elements
            array[i] = rhs.array[i]; // Deep copy each element

        return *this; // Return reference to this object
    }

    // Move assignment operator: transfers ownership from temporary object
    // Called when: f = createFoo(); or h = f + g; (assigning r-value)
    Foo& operator=(Foo&& rhs) noexcept // && = r-value reference, noexcept = no exceptions
    {
        cout << "move assignment operator executes." << endl; // Debug message

        if(this != &rhs) { // Check we're not moving object to itself
            if (array) {
                delete [] array;
            }
            size = rhs.size; // Take the size from source
            array = rhs.array; // STEAL the pointer (take ownership)
            rhs.array = nullptr; // Nullify source pointer so it doesn't delete our array
            rhs.size = 0; // Reset source size for consistency
        }

        return *this; // Return reference to this object for chaining
    }


    // Subscript operator overload: allows array-style access to elements
    // Called when: f[i] to get or set elements
    int& operator[](int i) // Returns reference so we can modify: f[i] = 5;
    { return array[i]; } // Return reference to element at index i

    // Getter method: returns the size of the array
    int length() const // const means this method doesn't modify the object
    { return size; } // Return the size value

    // Stream insertion operator: allows printing Foo objects with cout
    // Called when: cout << f; where f is a Foo object
    friend ostream& operator<<(ostream& o, const Foo& rhs) // friend = can access private members
    {
        for(int i = 0; i < rhs.size; i++) // Loop through all elements
            o << rhs.array[i] << " "; // Output each element followed by space

        return o; // Return stream reference for chaining: cout << f << g;
    }
};

// Main function: entry point of the program
int main()
{
    Foo f(5); // Create Foo object with array of 5 elements (calls regular constructor)

    for(int i = 0; i < f.length(); i++) // Loop from 0 to 4
        f[i] = 3 * i; // Set elements to 0, 3, 6, 9, 12 using overloaded []

    cout << f << endl; // Print f using overloaded << operator, then newline

    Foo g(f); // Create g as copy of f (calls copy constructor)
    cout << g << endl; // Print g (should be same as f: 0 3 6 9 12)

    Foo h(3); // Create h with array of 3 elements (calls regular constructor)

    cout << h << endl; // Print h (will be 0 0 0)

    // Expression f + g creates temporary r-value with 10 elements (0 3 6 9 12 0 3 6 9 12)
    // Then move assignment operator transfers this temporary to h (efficient, no copying!)
    h = f + g;

    cout << h << endl; // Print h (should now be 0 3 6 9 12 0 3 6 9 12)


    cin.get(); // Wait for user to press Enter before closing console window
    return 0; // Return 0 to indicate successful program execution
}
