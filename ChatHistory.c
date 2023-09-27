#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char string[100];
  struct Node* next;
  struct Node* prev;
} Node;

typedef struct DoublyLinkedList {
  Node* head;
} DoublyLinkedList;

void push(DoublyLinkedList* list, char* string) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  strcpy(new_node->string, string);
  new_node->next = list->head;
  if (list->head != NULL) {
    list->head->prev = new_node;
  }
  list->head = new_node;
}

void displayList(DoublyLinkedList* list) {
  Node* temp = list->head;
  while (temp != NULL) {
    printf("%s\n", temp->string);
    temp = temp->next;
  }
}

int main() {
  DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
  list->head = NULL;

  char string[100];
  printf("Enter a string: ");
  scanf("%s", string);
  while (string[0] != '\0') {
    push(list, string);
    printf("Enter another string (or press Enter to finish): ");
    scanf("%s", string);
  }

  
  printf("The linked list contains the following strings:\n");
  displayList(list);

  return 0;
}
