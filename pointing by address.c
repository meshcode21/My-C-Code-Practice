#include <stdio.h>

int main() {
    void *ptr;  // Generic pointer to hold any data type's address
    int value_type;  // To store the type of value (int, float, char, etc.)
    int *int_ptr;  // Integer pointer for type safety
    float *float_ptr;  // Float pointer for type safety
    char *char_ptr;  // Character pointer for type safety

    printf("Enter the type of value (1 for integer, 2 for float, 3 for character): ");
    if (scanf("%d", &value_type) != 1) {
        fprintf(stderr, "Error: Invalid input for value type.\n");
        return 1;
    }

    printf("Enter the memory address (in hexadecimal format, e.g., 0x7ffe0000): ");
    if (scanf("%p", &ptr) != 1) {
        fprintf(stderr, "Error: Invalid input for memory address.\n");
        return 1;
    }

    // Type casting based on user input for type safety
    switch (value_type) {
        case 1:
            int_ptr = (int *)ptr;
            printf("The value stored at the address is: %d\n", *int_ptr);
            break;
        case 2:
            float_ptr = (float *)ptr;
            printf("The value stored at the address is: %.2f\n", *float_ptr);
            break;
        case 3:
            char_ptr = (char *)ptr;
            printf("The value stored at the address is: %c\n", *char_ptr);
            break;
        default:
            fprintf(stderr, "Error: Invalid value type specified.\n");
            return 1;
    }

    return 0;
}

