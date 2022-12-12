#include <iostream>
#include <fstream>
#include <string>

// ifstream returns 0 when we reach the end of a file

int main() {
    std::ifstream inf {"Sample.txt"};
    if (!inf) {
        std::cerr << "Couldn't read file" << '\n';
        return 1;
    }

    // While there's still stuff left to read
    while (inf) {
        std::string strInput;
        std::getline(inf, strInput);
        // inf >> strInput;
        std::cout << strInput << '\n';
    }
    
    return 0;

    // When inf goes out of scope, the ifstream
    // destructor will close the file
}
