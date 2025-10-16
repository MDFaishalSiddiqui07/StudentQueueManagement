#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ================= Node Structure =================
struct Student {
    int id;
    char name[50];
    struct Student* next;
};

// ================= Queue Pointers =================
struct Student* front = NULL;
struct Student* rear = NULL;

// ================= Function Declarations =================
void enqueue();
void dequeue();
void peek();
void display();
int totalStudents();

// ================= Main Function =================
int main() {
    int choice;

    do {
        printf("\n===== STUDENT QUEUE MANAGEMENT SYSTEM =====\n");
        printf("1. Enqueue Student\n");
        printf("2. Dequeue Student\n");
        printf("3. Peek Front Student\n");
        printf("4. Display Queue\n");
        printf("5. Total Students\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: printf("Total Students in Queue: %d\n", totalStudents()); break;
            case 6: printf("Exiting Program. Thank you!\n"); break;
            default: printf("Invalid Choice! Try Again.\n");
        }

    } while(choice != 6);

    return 0;
}

// ================= Enqueue Function =================
void enqueue() {
    struct Student* newStudent = (struct Student*) malloc(sizeof(struct Student));
    if(!newStudent) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter Student ID: ");
    scanf("%d", &newStudent->id);
    printf("Enter Student Name: ");
    scanf(" %[^\n]", newStudent->name);
    newStudent->next = NULL;

    if(rear == NULL) {
        front = rear = newStudent;
    } else {
        rear->next = newStudent;
        rear = newStudent;
    }

    printf("Student Enqueued Successfully!\n");
}

// ================= Dequeue Function =================
void dequeue() {
    if(front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct Student* temp = front;
    front = front->next;

    if(front == NULL) rear = NULL;

    printf("Dequeued Student: ID=%d, Name=%s\n", temp->id, temp->name);
    free(temp);
}

// ================= Peek Function =================
void peek() {
    if(front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Front Student: ID=%d, Name=%s\n", front->id, front->name);
}

// ================= Display Function =================
void display() {
    if(front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct Student* temp = front;
    printf("\n--- Students in Queue ---\n");
    while(temp != NULL) {
        printf("ID: %d, Name: %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

// ================= Total Students Function =================
int totalStudents() {
    int count = 0;
    struct Student* temp = front;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
