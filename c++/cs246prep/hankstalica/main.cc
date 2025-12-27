// rvalues = memory location without a name (ex a temp value)
//          you can directly access this value and it gets assigned to something else
// lvalues =

#include <iostream>
#include <utility>
using namespace std;

class Foo {
    private:
    int* array, size;

    public:
    // Constructor
    Foo(int s) {
        size = s;
        array = new int[size] { 0 };
    }

    // Copy Constructor
    // Foo f(g) where g is also a Foo
    // Foo f = g;
    Foo(const Foo& rhs) {
        cout << "Copy constructor executed here" << endl;
        size = rhs.size;
        array = new int[size];

        for (int i = 0; i < size; i++) {
            array[i] = rhs.array[i];
        }
    }

    // Move constructor
    // for dealing with r-values
    Foo(Foo&& rhs) noexcept // idk if i need to know "noexcept"
    { // 1 & = copy constructor 2 && means move constructor
        cout << "Move constructor executes" << endl;
        size = rhs.size;
        array = rhs.array;
        rhs.array = nullptr;
    }

    // Destructor
    ~Foo() {
        if (array) {
            delete[] array;
        }
    }
    //Concat method; creates an rvalue
    Foo operator+(const Foo& rhs) {
        Foo temp(size + rhs.size);
        auto i = 0;
        for(; i < size; i++)
            temp[i] = array[i];
        for(auto j = 0; j < rhs.size; i++, j++)
            temp[i] = rhs.array[j];
        return temp;
    }

    // Assignment Operator
    Foo& operator=(const Foo& rhs) {
        cout << "Copy Assignmnet Operator" << endl;
        if (this == &rhs) {
            return *this;
        }
        if (array) {
            delete [] array;
        }
        size = rhs.size;
        array = new int[size];

        for (int i = 0; i < size; i++) {
            array[i] = rhs.array[i];
        }
        return *this;
    }

    // Move assignment operator
    Foo& operator=(Foo&& rhs) noexcept
    {
        cout << "Move assignment operator executes" << endl;
        size = rhs.size;
        array = rhs.array;
        rhs.array = nullptr;

        return *this;
    }

    int& operator[](int i) {
        return array[i];
    }

    int length() const {
        return size;
    }

    friend ostream& operator<<(ostream& o, const Foo& rhs) {
        for (int i = 0; i < rhs.size; i++) {
            o << rhs.array[i] << " ";
        }
        return o;
    }
};

int main() {
    Foo f(5);
    for (int i = 0; i < f.length(); i++) {
        f[i] = 3 * i;
    }
    cout << f << endl;

    //

    Foo g(f);
    cout << g << endl;

    Foo h(3);
    cout << h << endl;

    h = f + g; // f + g creates an r value in which we store it in h
    cout << h << endl; // the move operators speed things up - instead of deleting temp items, you just directly move

    return 0;
}
