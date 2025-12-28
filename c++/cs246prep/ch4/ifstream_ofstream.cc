#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ifstream and ofstream is how you can read and write to files

void write_file() {
    cout << "Answer: ";
    string response;
    cin >> response;
    ofstream file("text.txt");
    file << response;
    file.close();
}

void read_file() {
    ifstream file_read("text.txt");
    string answer;
    file_read >> answer;
    cout << answer << endl;
    file_read.close();
}

void write_everything(string foods[], int size) {
    ofstream file("foods.txt");
    for (int i = 0; i < size; i++) {
        file << foods[i] << endl;
    }
}

void read_everything() {
    ifstream file("foods.txt");
    string line;
    string full_file_contents;

    while (getline(file, line)) {
        full_file_contents += line;
        full_file_contents.push_back('\n');
    }

    cout << full_file_contents << endl;
}

void REMEMBER() {
    // when going through a list or going through something with a for look
    // for (int i = 0; i < size; i++) { // you need the size and array because the number of items must be declared
    //      cout << arr[i] << endl;
    cout << "IMPORTANT" << endl;
}

int main() {
    write_file();
    read_file();

    string foods[3] = {"apple", "banana", "cucumber"};
    write_everything(foods, 3);
    read_everything();


    return 0;
}
