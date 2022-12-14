#include <iostream>
#include <fstream>
#include <vector>
#include <map>

const int WIN  = 6;
const int LOSS = 0;
const int DRAW = 3;


void partone(std::vector<std::string>& userInput) 
{
    std::map<char, int> opponent({{'A', 1}, {'B', 2}, {'C', 3}});
    std::map<char, int> user({{'X', 1}, {'Y', 2}, {'Z', 3}});

    int sumMe = 0;
    int i = 1;

    for(auto lines : userInput) {
        char opponentOption = lines[0];
        char userOption = lines[2];

        if (user[userOption] > opponent[opponentOption]) {
            sumMe = sumMe + user[userOption] + 6;
        }
        else if (user[userOption] < opponent[opponentOption]) {
            sumMe = sumMe + user[userOption] + 0;
        }
        else {
            sumMe = sumMe + user[userOption] + 3;
        }
        std::cout << "lines number: " << i++ << '\n';
        std::cout << "sum: " << sumMe << '\n';
        std::cout << '\n';
    }
    std::cout << sumMe << '\n';
}

int main() {
    std::ifstream inf {"input.txt"};
    if (!inf) {
        std::cerr << "Couldn't open file";
        return 1;
    }

    std::string stringData;
    std::vector<std::string> userInput;

    while(std::getline(inf, stringData))
        userInput.push_back(stringData);

    partone(userInput);
    return 0;
}

