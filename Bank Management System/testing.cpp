#include <iostream>

int main() {
    char fullName[100]; // Declare a character array to store the input

    std::cout << "Enter your full name: ";
    
    // Use std::cin.getline() to read input with spaces into the character array
    std::cin.getline(fullName, 100);

    std::cout << "Your full name is: " << fullName << std::endl;

    return 0;
}

