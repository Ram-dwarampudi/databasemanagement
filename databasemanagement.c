#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 5

// Global variables
char studentNames[MAX_STUDENTS][50];
int grades[MAX_STUDENTS][MAX_SUBJECTS];
int studentCount = 0;

// Function prototypes
void addStudent();
void calculateAverages();
void searchStudent();
void displayReport();

int main() {
    int choice;

    while (1) {
        printf("\nStudent Grade Management System\n");
        printf("1. Add Student\n");
        printf("2. Calculate Averages\n");
        printf("3. Search Student\n");
        printf("4. Display Report\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: calculateAverages(); break;
            case 3: searchStudent(); break;
            case 4: displayReport(); break;
            case 5: return 0;
            default: printf("Invalid choice! Please try again.\n");
        }
    }
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Student limit reached!\n");
        return;
    }

    printf("Enter student name: ");
    scanf(" %[^\n]", studentNames[studentCount]);

    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf("Enter grade for subject %d: ", i + 1);
        scanf("%d", &grades[studentCount][i]);
    }

    studentCount++;
    printf("Student added successfully!\n");
}

void calculateAverages() {
    for (int i = 0; i < studentCount; i++) {
        int total = 0;
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            total += grades[i][j];
        }
        printf("Average grade for %s: %.2f\n", studentNames[i], total / (float)MAX_SUBJECTS);
    }
}

void searchStudent() {
    char name[50];
    printf("Enter student name to search: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(studentNames[i], name) == 0) {
            printf("Student found: %s\nGrades: ", studentNames[i]);
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                printf("%d ", grades[i][j]);
            }
            printf("\n");
            return;
        }
    }

    printf("Student not found!\n");
}

void displayReport() {
    printf("\nStudent Report:\n");
    printf("Name\t\tGrades\n");
    printf("--------------------------------\n");

    for (int i = 0; i < studentCount; i++) {
        printf("%s\t", studentNames[i]);
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            printf("%d ", grades[i][j]);
        }
        printf("\n");
    }
}