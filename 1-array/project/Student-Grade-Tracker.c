// program to track and manage student grades using an array. 
// Allow the user to input grades for multiple students 
// and perform operations such as calculating the average grade, 
// finding the highest and lowest grades, 
// and displaying a grade report
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5
#define MAX_NAME_LENGTH 50
#define MAX_GRADES 5

void addStudent(char names[][MAX_NAME_LENGTH], int grades[][MAX_GRADES], int* studentCount) {
    char name[MAX_NAME_LENGTH];

    printf("Enter Student Name : ");
    scanf("%s", name);

    strcpy(names[*studentCount], name);

    printf("Enter student grades (separated by spaces): ");
    for (int i = 0; i < MAX_GRADES; i++) {
        scanf("%d", &grades[*studentCount][i]);
    }

    (*studentCount)++;

    printf("Student record added successfully\n");

}

typedef struct {
    double average;
    int highestGrade;
    int lowestGrade;
} studentData;

studentData calculatedStudent(char names[][MAX_NAME_LENGTH], int grades[][MAX_GRADES], int studentCount) {
    studentData studentData;

    for (int i = 0; i < studentCount; i++) {
        int gradeHL = grades[i][0]; // Highest and lowest 
        int maxGrade = gradeHL;
        int minGrade = gradeHL;

        int sum = 0;
        for (int j = 0; j < MAX_GRADES; j++) {
            sum += grades[i][j];

            if (grades[i][j] > gradeHL) {
                maxGrade = grades[i][j];
            }
            if (grades[i][j] < gradeHL) {
                minGrade = grades[i][j];
            }

        }
        double average = (double) sum / MAX_GRADES;
        
        studentData.average = average;
        studentData.highestGrade = maxGrade;
        studentData.lowestGrade = minGrade;
    }
    return studentData;
}

void displayData(char names[][MAX_NAME_LENGTH], int grades[][MAX_GRADES], int studentCount ,studentData data) {
    for (int i = 0; i < studentCount; i++) {
        printf("Student :%d\n", i + 1);
        printf("Name: %s\n", names[i]);
        printf("Grades: ");

        for (int j = 0; j < MAX_GRADES; j++) {
            printf("%d ", grades[i][j]);
        }

        printf("\nAverage : %.2f\n", data.average);
        printf("Highest Grade : %d\n", data.highestGrade);
        printf("Lowest Grade : %d\n\n", data.lowestGrade);
    }
}

int main () {
    char names[MAX_STUDENTS][MAX_NAME_LENGTH];
    int grades[MAX_STUDENTS][MAX_GRADES];
    int studentCount = 0;

    addStudent(names, grades, &studentCount);

    studentData data = calculatedStudent(names, grades, studentCount);
    displayData(names, grades, studentCount, data);

    return 0;
}
