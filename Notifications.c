#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[100];
    struct Node* next;
};

void push(struct Node** top, char str[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newNode->data, str);
    newNode->next = *top;
    *top = newNode;
    printf("Pushed: %s\n", str);
}

void pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }
    struct Node* temp = *top;
    *top = (*top)->next;
    printf("Popped: %s\n", temp->data);
    free(temp);
}

void printStack(struct Node* top) {
    printf("Stack contents:\n");
    struct Node* current = top;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

int main() {
    struct Node* top = NULL;
    int choice;
    char str[100];

    // push(&top, str);
    // pop(&top);
    // printStack(top);
    do {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%s", str);
                push(&top, str);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                printStack(top);
                break;
            case 4:
                break;
            default:
                printf("END\n");
        }
    } while (choice != 4);

    while (top != NULL) {
        pop(&top);
    }

    return 0;
}
