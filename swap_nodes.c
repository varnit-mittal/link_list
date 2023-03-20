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

void swap(Node *head, int key1, int key2)
{
    Node *a=head;
    Node *t=(Node *)(malloc(sizeof(Node)));;
    Node *p=(Node *)(malloc(sizeof(Node)));;
    Node *q=NULL;
    Node *r=NULL;
    if(head && head->next!=NULL)
    {
        while(a->next)
        {
            if(a->next->data==key1)
                q=a;
            if(a->next->data==key2)
                r=a;
            a=a->next;
        }
        if(r->next->data==key2 && q->next->data==key1)
        {
            t=q->next;
            p=r->next;
            q->next=p;
            r->next=t;
            Node *m=t->next;
            t->next=p->next;
            p->next=m;
        }
    }
    else
    return;
}

int main()
{
    Node *head=NULL;
    insert(&head,10);
    insert(&head,15);
    insert(&head,12);
    insert(&head,13);
    insert(&head,20);
    insert(&head,14);
    traverse(head);
    swap(head,12,20);
    traverse(head);
}