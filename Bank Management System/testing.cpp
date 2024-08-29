#include <iostream>
#include <cstdio> // For remove()

int main() {
    const char* filename = "Employee.txt";

    if (remove(filename) != 0) {
        std::perror("Error deleting file");
    } else {
        std::cout << "File successfully deleted\n";
    }

    return 0;
}

