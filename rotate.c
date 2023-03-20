#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}Node;

void insert(Node **head,int i)
{
    Node *new=(Node *)(malloc(sizeof(Node)));
    new->data=i;
    new->next=*head;
    *head=new;
}

void traverse(Node *head)
{
    Node *new=(Node *)(malloc(sizeof(Node)));
    new=head;
    while(new)
    {
        printf("%d ",new->data);
        new=new->next;
    }
    printf("\n");
}

void rotate(Node **head) //brings the last element to the front of the list
{
    Node *p=*head;
    Node *q=*head;
    if((*head)!=NULL && (*head)->next!=NULL)
    {
        while(p->next->next!=NULL)
            p=p->next;
        Node *m=p->next;
        p->next->next=q;
        p->next=NULL;
        *head=m;
    }
}

int main()
{
    Node *head=NULL;
    insert(&head,3);
    insert(&head,8);
    insert(&head,1);
    insert(&head,5);
    insert(&head,7);
    insert(&head,12);
    traverse(head);
    rotate(&head);
    traverse(head);
}