#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char phoneNumber[15];
    char name[50];
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(char phoneNumber[], char name[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->phoneNumber, phoneNumber);
    strcpy(newNode->name, name);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, char phoneNumber[], char name[]) {
    struct Node* newNode = createNode(phoneNumber, name);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void moveNode(struct Node** head, int fromPosition, int toPosition) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = *head;
    int currentPosition = 1;

    while (currentPosition < fromPosition && current != NULL) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Node not found at position %d.\n", fromPosition);
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    currentPosition = 1;
    current = *head;
    while (currentPosition < toPosition && current != NULL) {
        current = current->next;
        currentPosition++;
    }

    if (current != NULL) {
        current->prev->next = current;
        current->prev = current->prev;
        current->next = current;
    } else {
        struct Node* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = current;
        current->prev = last;
    }
}

void printList(struct Node* head) {
    struct Node* current = head;
    printf("Phone Number\tName\n");
    while (current != NULL) {
        printf("%s\t%s\n", current->phoneNumber, current->name);
        current = current->next;
    }
}

int main() {
    struct Node* head = NULL;
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char phoneNumber[15];
        char name[50];
        printf("Enter phone number: ");
        scanf("%s", phoneNumber);
        printf("Enter name: ");
        scanf("%s", name);
        insertEnd(&head, phoneNumber, name);
    }

    printf("Doubly Linked List:\n");
    printList(head);

    int fromPosition, toPosition;
    printf("Enter the position to move from: ");
    scanf("%d", &fromPosition);
    printf("Enter the position to move to: ");
    scanf("%d", &toPosition);

    moveNode(&head, fromPosition, toPosition);

    printf("Updated Doubly Linked List:\n");
    printList(head);

    return 0;
}
