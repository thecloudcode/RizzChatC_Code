#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[100];
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void addToEnd(char data[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    printf("Added \"%s\" to the end of the list.\n", data);
}

void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* current = head;
    int currentPosition = 1;

    while (current != NULL && currentPosition != position) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Position %d not found in the list.\n", position);
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    printf("Deleted \"%s\" from position %d.\n", current->data, position);
    free(current);
}

void display() {
    struct Node* current = head;
    printf("Doubly Linked List contents:\n");
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

int main() {
    int choice;
    char data[100];
    int position;

    while (1) {
        printf("\nDoubly Linked List Menu:\n");
        printf("1. Add to End\n");
        printf("2. Delete at Position\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a string to add to the end: ");
                scanf("%s", data);
                addToEnd(data);
                break;
            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
