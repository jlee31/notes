#include <cstring>
#include <iostream>

struct Vector {
    int x, y;
};

class String {
    private:
    char* m_buffer;
    unsigned int m_size;

    public:
    String(const char* string) {
        m_size = strlen(string);
        m_buffer = new char[m_size + 1];
        // for (int i = 0; i < m_size; i++) {
        //     m_buffer[i] = string[i];
        // }
        // or
        std::memcpy(m_buffer, string, m_size + 1);
    }

    // copy constructor
    String(const String& other)
        : m_size(other.m_size)
    {
        std::cout << "Copying the string" << std::endl;

        m_buffer = new char[m_size + 1];
        memcpy(m_buffer, other.m_buffer, m_size + 1);
    }

    ~String() {
        delete[] m_buffer;
    }

    // subscript operator
    char& operator[](unsigned int index){
        return m_buffer[index];
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string) {
    stream << string.m_buffer;
    return stream;
}

void PrintString1(String string) { // right now it takes a copy of the string
    std::cout << string << std::endl;
}

void PrintString2(const String& string) { // by taking a const reference, you copy only once instead of three times
    std::cout << string << std::endl;
}

int main() {
    int a = 2;
    int b = a;
    b = 3;

    Vector m = {2,3};
    Vector n = m; // this code creates two different addresses with the same values
    n.x = 5;

    std::cout << m.x << " " << n.x << std::endl;

    // if you copy the address, then you are pointing to the same part of memory\


String string = "Jsoeph";
String second = string;

second[2] = 'a';

PrintString2(string);
PrintString2(second);

}
