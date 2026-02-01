#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student data
typedef struct {
    int roll_no;
    char name[50];
    float *marks;     // Array to store marks for each subject
    float average;
    char grade;
} Student;

// Function to calculate grade based on average marks
char calculate_grade(float average) {
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else return 'F';
}

// Function to display details of a student
void display_student(Student student, char **subject_names, int num_subjects) {
    printf("%-10d%-15s", student.roll_no, student.name);
    for (int i = 0; i < num_subjects; i++) {
        printf("%-15.2f", student.marks[i]);
    }
    printf("%-15.2f%-5c\n", student.average, student.grade);
}

int main() {
    int num_students, num_subjects;

    // Read the number of students
    printf("Enter no.of students: ");
    scanf("%d", &num_students);

    // Read the number of subjects
    printf("Enter no.of subjects: ");
    scanf("%d", &num_subjects);

    // Allocate memory for subject names
    char **subject_names = (char **)malloc(num_subjects * sizeof(char *));
    for (int i = 0; i < num_subjects; i++) {
        subject_names[i] = (char *)malloc(50 * sizeof(char));
        printf("Enter the name of subject %d: ", i + 1);
        scanf("%s", subject_names[i]);
    }

    // Allocate memory for students
    Student *students = (Student *)malloc(num_students * sizeof(Student));

    // Read details for each student
    for (int i = 0; i < num_students; i++) {
        printf("----------Enter the student details-------------\n");
        printf("Enter the student Roll no.: ");
        scanf("%d", &students[i].roll_no);

        printf("Enter the student %d name: ", i + 1);
        scanf("%s", students[i].name);

        // Allocate memory for marks
        students[i].marks = (float *)malloc(num_subjects * sizeof(float));

        // Read marks for each subject
        float total = 0;
        for (int j = 0; j < num_subjects; j++) {
            printf("Enter %s mark: ", subject_names[j]);
            scanf("%f", &students[i].marks[j]);
            total += students[i].marks[j];
        }

        // Calculate average and grade
        students[i].average = total / num_subjects;
        students[i].grade = calculate_grade(students[i].average);
    }

    // Display menu
    char choice;
    do {
        printf("----Display Menu----\n");
        printf("1. All student details\n");
        printf("2. Particular student details\n");
        printf("Enter your choice: ");
        int menu_choice;
        scanf("%d", &menu_choice);

        if (menu_choice == 1) {
            // Display all student details
            printf("Roll No.   Name           ");
            for (int i = 0; i < num_subjects; i++) {
                printf("%-15s", subject_names[i]);
            }
            printf("Average       Grade\n");

            for (int i = 0; i < num_students; i++) {
                display_student(students[i], subject_names, num_subjects);
            }
        } else if (menu_choice == 2) {
            // Display particular student details
            printf("----Menu for Particular student----\n");
            printf("1. Name.\n");
            printf("2. Roll no.\n");
            printf("Enter your choice: ");
            int sub_choice;
            scanf("%d", &sub_choice);

            if (sub_choice == 1) {
                char search_name[50];
                printf("Enter the name of the student: ");
                scanf("%s", search_name);

                printf("Roll No.   Name           ");
                for (int i = 0; i < num_subjects; i++) {
                    printf("%-15s", subject_names[i]);
                }
                printf("Average       Grade\n");

                for (int i = 0; i < num_students; i++) {
                    if (strcmp(students[i].name, search_name) == 0) {
                        display_student(students[i], subject_names, num_subjects);
                        break;
                    }
                }
            } else if (sub_choice == 2) {
                int search_roll;
                printf("Enter the Roll no. of the student: ");
                scanf("%d", &search_roll);

                printf("Roll No.   Name           ");
                for (int i = 0; i < num_subjects; i++) {
                    printf("%-15s", subject_names[i]);
                }
                printf("Average       Grade\n");

                for (int i = 0; i < num_students; i++) {
                    if (students[i].roll_no == search_roll) {
                        display_student(students[i], subject_names, num_subjects);
                        break;
                    }
                }
            }
        }

        printf("Do you want to continue to display (Y/y)? ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');

    // Free allocated memory
    for (int i = 0; i < num_students; i++) {
        free(students[i].marks);
    }
    free(students);

    for (int i = 0; i < num_subjects; i++) {
        free(subject_names[i]);
    }
    free(subject_names);

    return 0;
}
