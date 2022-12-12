#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>

bool readFile();
void partOne();


bool readFile (const std::string& FileName, std::vector<std::string>& calorie) {
    std::ifstream inf {FileName};
    if (!inf) {
        std::cerr << "Couldn't open file";
        return false;
    }
    std::string dataString;
    // while the list of string is not empty
    while (std::getline(inf, dataString)) {
        // put the strings in a array
        calorie.push_back(dataString);
    }
    return true;
}

void partOne(std::vector<std::string>& calorie) {
    // maximum amount of size max and sum can hold in this case 8 bytes
    size_t max {};
    size_t sum {};
    for (auto line : calorie) {
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

void partTwo(std::vector<std::string>& calorie) {
    std::array<int, 3> topThree {};
    int max1 {};
    int max2 {};
    int max3 {};
    int sum {};
    for (auto line : calorie) {
        if (!line.empty()) {
            sum += std::stoul(line);
        }
        else {
            if (sum > max1) {
                max3 = max2;
                max2 = max1;
                max1 = sum;
            } else if (sum > max2) {
                max3 = max2;
                max2 = sum;
            } else if (sum > max3) 
                max3 = sum;
            sum = 0;
        }
    }
    int total = max1 + max2 + max3;
    std::cout << "The Top Three Are: " << max1 << ' ' << max2 << ' ' << max3 << '\n';
    std::cout << "The Total Sum: " << total << '\n';
}

// we are passing the name of the file as command line argument
int main(int argc, char* argv[]) {  
    std::vector<std::string> lines{};
    if (argc == 2) {
        if (!readFile(argv[1], lines)) 
            return EXIT_FAILURE;
    }
    partOne(lines);
    partTwo(lines);
    return 0;
}
