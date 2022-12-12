#include <iostream>
#include <fstream>
#include <string>
#include <vector>

bool readFile();
void partOne();


bool readFile (const std::string& FileName, std::vector<std::string>& lines) {
    std::ifstream inf {FileName};
    if (!inf) {
        std::cerr << "Couldn't open file";
        return false;
    }
    std::string dataString;
    // while the list of string is not empty
    while (std::getline(inf, dataString)) {
        // put the strings in a array
        lines.push_back(dataString);
    }
    return true;
}

void partOne(std::vector<std::string>& lines) {
    // maximum amount of size max and sum can hold in this case 8 bytes
    size_t max {};
    size_t sum {};
    for (auto line : lines) {
        if (!line.empty()) 
            // stoul converts a string to an unsinged integer
            // and sum out all the numbers until we find a whitespace or a empty line
            sum += std::stoul(line);
        else {
            // if the sum is > max then change the value of max
            if (sum > max) 
                max = sum;
            // and reset of value of sum back to 0
            sum = 0;
        }
    }
    std::cout << max << '\n';
}

// we are passing the name of the file as command line argument
int main(int argc, char* argv[]) {  
    std::vector<std::string> lines{};
    if (argc == 2) {
        if (!readFile(argv[1], lines)) 
            return EXIT_FAILURE;
    }
    partOne(lines);
    return 0;
}
