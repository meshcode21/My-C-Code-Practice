#include <stdio.h>

int extendedEuclid(int a, int b, int *x, int *y) {
    // Initial values
    int x1 = 1, y1 = 0, x2 = 0, y2 = 1;
    int q, r, xn, yn;

    while (b != 0) {
        q = a / b;
        r = a % b;

        xn = x1 - q * x2;
        yn = y1 - q * y2;

        // Update values for next iteration
        a = b;
        b = r;
        x1 = x2;
        y1 = y2;
        x2 = xn;
        y2 = yn;
    }

    // Setting coefficients x and y
    *x = x1;
    *y = y1;

    return a; // Returns gcd(a, b)
}

// Main function
void main() {
    int a, b, x, y;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    int gcd = extendedEuclid(a, b, &x, &y);

    // Output results
    printf("\nExtended Euclidean Algorithm (iterative):\n");
    printf("gcd(%d, %d) = %d\n\n", a, b, gcd);
    printf("Coefficients (x, y) such that %d*x + %d*y = gcd(%d, %d):\n", a, b, a, b);
    printf("x = %d, y = %d\n", x, y);
}

