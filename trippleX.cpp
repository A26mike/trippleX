#include <iostream>
#include <ctime>

int main()
{   
    int level = 2;

    int code1 = 4;
    int code2 = 3;
    int code3 = 2;

    int codeProduct = code1 * code2 * code3;
    int codeSum = code1 + code2 + code3;

    std::cout << "\nYou are a secret agent breaking into LEVEL " << level << " server room..." << std::endl;
    std::cout << "Your SuperHacker 2000 tells you the following information..." << std::endl;

    std::cout << "\nThere are three numbers in the code"  << std::endl;
    std::cout << "The codes multiply to give " << codeProduct << std::endl;
    std::cout << "The codes add-up to " << codeSum << std::endl;

    std::cout << "\nEnter the three code numbers followed by x " << std::endl;

    return 0;
}