// rvalues = memory location without a name (ex a temp value)
//          you can directly access this value and it gets assigned to something else
// lvalues =

#include <iostream>
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
    return 0;
}
