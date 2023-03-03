#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int isCyclic(struct Node* head) {
    struct Node *tortoise = head, *hare = head;

    while (hare && hare->next) {
        tortoise = tortoise->next;
        hare = hare->next->next;
        if (tortoise == hare) {
            return 1;
        }
    }

    return 0;
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int main() {
  
    struct Node* head = newNode(0);
     head->next = newNode(1);
    head->next->next = newNode(2);
    head->next->next->next = newNode(3);
    head->next->next->next->next = head->next;
   
    if (isCyclic(head)) {
        printf("The linked list is cyclic.\n");
    } else {
        printf("The linked list is not cyclic.\n");
    }

    return 0;
}