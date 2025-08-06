#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Student {
    int id;
    char name[50];
    int age;
    float marks;
};

struct Student students[MAX];
int count = 0;

// Function Declarations
void addStudent();
void displayStudents();
void searchStudent();
void deleteStudent();
void updateStudent();

int main() {
    int choice;

    while (1) {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Update Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                updateStudent();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Try again!\n");
        }
    }

    return 0;
}

// Function Definitions

void addStudent() {
    if (count >= MAX) {
        printf("Student list full!\n");
        return;
    }

    struct Student s;
    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);  // allow space in name
    printf("Enter Age: ");
    scanf("%d", &s.age);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    students[count++] = s;
    printf("Student added successfully!\n");
}

void displayStudents() {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Age: %d | Marks: %.2f\n",
            students[i].id, students[i].name, students[i].age, students[i].marks);
    }
}

void searchStudent() {
    int id, found = 0;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Student Found: ID: %d | Name: %s | Age: %d | Marks: %.2f\n",
                students[i].id, students[i].name, students[i].age, students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student with ID %d not found.\n", id);
}

void deleteStudent() {
    int id, found = 0;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("Student with ID %d deleted successfully.\n", id);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student with ID %d not found.\n", id);
}

void updateStudent() {
    int id, found = 0;
    printf("Enter ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Enter new name: ");
            scanf(" %[^\n]", students[i].name);
            printf("Enter new age: ");
            scanf("%d", &students[i].age);
            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);
            printf("Student with ID %d updated successfully.\n", id);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student with ID %d not found.\n", id);
}
