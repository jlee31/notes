#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main () {
    ostringstream ss; // used for string construction not for input
    int low {1}, high{100};
    ss << "Enter a number between " << low << " and " << high << endl; // this allows us to mix numbers and string
    string s {ss.str()}; // this is the string created
    cout << s << endl;

}
