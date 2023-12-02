#include <iostream> 
#include <fstream>
#include <string>


int Extractfirstdigit(const std::string& str) { 
     for (size_t pos = 0; pos < str.length(); pos ++) {
        if (isdigit(str[pos])) { 
            return str[pos] - '0';
        }
     }


    return -1; 
}

int Extractlastdigit(const std::string& str) {
    size_t pos = str.length();
    while(pos > 0 && !isdigit(str[--pos])) {}

    return std::stoi(str.substr(pos));

    }



int main() {
    std::string filepath = "/Users/nate/Downloads/adventimport.txt";

    std::ifstream file(filepath);

    int sumOfTwoDigitNumbers = 0;

   std::string line;
    while (std::getline(file, line)) {
    int firstDigit = Extractfirstdigit(line);
    int lastDigit = Extractlastdigit(line);

    // int twoDigitNumber = firstDigit + lastDigit;

    unsigned int firstDigit_copy = firstDigit;
    unsigned int lastDigit_copy = lastDigit;

    unsigned int temp = lastDigit_copy;

    do {
        temp /= 10;
        firstDigit_copy *=10;
    } while (temp > 0);


    unsigned int twoDigit = firstDigit_copy + lastDigit_copy;

    sumOfTwoDigitNumbers += twoDigit;


    std::cout << sumOfTwoDigitNumbers << std::endl;
    }
    

        //std::cout << twoDigit << std::endl;


   file.close();
   

   return 0;
}