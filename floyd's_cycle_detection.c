/*
linked list elements are not stored at a contiguous location

elements are linked using pointers. They include a series of connected nodes.

each node stores the data and the address of the next node
*/

//floyd's cycle detection algorithm is also called tortoise and hare approach
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

bool hasCycle(Node *head) {
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next!=NULL) {
        fast=fast->next->next;
        if(fast==slow)
        return true;
        slow=slow->next;
    }

    return false;
}

int main() {
    Node *head = malloc(sizeof(Node));
    head->data = 1;

    Node *second = malloc(sizeof(Node));
    second->data = 2;

    Node *third = malloc(sizeof(Node));
    third->data = 3;

    head->next = second;
    second->next = third;
    
// Uncomment the line below to create a cycle
// third->next = second; 

// Comment the line below to create a cycle
third->next=NULL; 

if (hasCycle(head)) {
printf("The linked list has a cycle.\n");
} else {
printf("The linked list does not have a cycle.\n");
}

return 0;
}