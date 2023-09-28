#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[100];
    struct Node* next;
};

struct Node* top = NULL;

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

void display() {
    struct Node* current = top;
    printf("Stack contents:\n");
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

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
