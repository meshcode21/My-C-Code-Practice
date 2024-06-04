#include <stdio.h>
#include <math.h>  // For sqrt() function

int is_prime(int num) {
	int i;
    if (num <= 1) {
        return 0;  // Not prime
    }

    for (i = 2; i <num; i++) {
        if (num % i == 0) {
            return 0;  // Not prime
        }
    }

    return 1;  // Prime
}

int main() {
    FILE *nfile = fopen("number.txt", "r");
    FILE *pfile = fopen("prime.txt", "w");

    if (nfile == NULL || pfile == NULL) {
        printf("Error opening files!\n");
        return 1;
    }

    int num;
    while (fscanf(nfile, "%d", &num) != EOF) {
        if (is_prime(num)) {
            fprintf(pfile, "%d\n", num);
            printf("%d\n",num);
        }
    }

    fclose(nfile);
    fclose(pfile);

    printf("Prime numbers extracted successfully!\n");
    return 0;
}

