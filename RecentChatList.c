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
    // Check if the positions are valid.
    if (fromPosition < 0 || toPosition < 0 || fromPosition >= toPosition) {
    return;
    }

    // Find the nodes to be swapped.
    struct Node* node1 = *head;
    struct Node* node2 = *head;
    struct Node* prev1 = NULL;
    struct Node* prev2 = NULL;
    for (int i = 0; i < fromPosition; i++) {
    prev1 = node1;
    node1 = node1->next;
    }
    for (int i = 0; i < toPosition; i++) {
    prev2 = node2;
    node2 = node2->next;
    }

    // Swap the nodes.
    if (prev1 != NULL) {
    prev1->next = node2;
    } else {
    *head = node2;
    }
    if (prev2 != NULL) {
    prev2->next = node1;
    } else {
    *head = node1;
    }
    struct Node* temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
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
