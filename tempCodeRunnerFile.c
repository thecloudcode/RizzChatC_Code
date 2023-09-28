#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a node
struct Node {
    char data[100]; // Assume a maximum string length of 100 characters
    struct Node* next;
};

struct Node* top = NULL; // Initialize the top of the stack as NULL

// Function to push a string onto the stack
void push(char data[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newNode->data, data);
    newNode->next = top;
    top = newNode;
    printf("Pushed: %s\n", data);
}

// Function to pop a string from the stack
void pop() {
    if (top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    printf("Popped: %s\n", temp->data);
    free(temp);
}

// Function to display the contents of the stack
void display() {
    struct Node* current = top;
    printf("Stack contents:\n");
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

// Function to remove all items from the stack
void removeAll() {
    while (top != NULL) {
        pop();
    }
}

int main() {
    int choice;
    char data[100];

    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Remove All\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a string to push: ");
                scanf("%s", data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                removeAll();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
