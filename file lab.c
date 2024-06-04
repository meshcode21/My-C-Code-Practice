#include <stdio.h>

int main() {
  FILE *fp;
  char name[50];
  int id;
  float marks;

  // Create data file
  fp = fopen("student.txt", "w");
  if (fp == NULL) {
    printf("Error opening file!\n");
    return 1;
  }

  // Get student information
  printf("Enter student name: ");
  gets(name);
  printf("Enter student ID: ");
  scanf("%d", &id);
  printf("Enter student marks: ");
  scanf("%f", &marks);

  // Write formatted data to file
  fprintf(fp, "Name: %s, ID: %d, Marks: %.2f\n", name, id, marks);
  printf("\nstudent data successfully recorded to the file.");

  // Close the file for writing
  fclose(fp);
  
  return 0;
}

