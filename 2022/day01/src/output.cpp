#include <iostream>
#include <fstream>

int main() {
    std::ofstream outf {"Sample.txt", std::ios::app}; // we are appending new strings into the file by not overwriting
    if (!outf) {
        std::cerr << "Couldn't load file";
        return 1;
    }

    // we are writing two lines into the file
    outf << "something\n";
    return 0;
    // when outf goes out of scope , the ofstream destructor will close the file
}
