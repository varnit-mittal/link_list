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

Node * intersection(Node *l1,Node *l2)
{
    Node *p=NULL;
    while(l1!=NULL && l2!=NULL)
    {
        if(l1->data==l2->data)
        {
            insert(&p,l1->data);
            l1=l1->next;
            l2=l2->next;
        }
        else if(l1->data<l2->data)
        l1=l1->next;
        else
        l2=l2->next;
    }
    return (p);
}

int main()
{
    Node *a=NULL;
    insert(&a, 6);
    insert(&a, 5);
    insert(&a, 4);
    insert(&a, 3);
    insert(&a, 2);
    insert(&a, 1);
    Node *b=NULL;
    insert(&b, 8);
    insert(&b, 6);
    insert(&b, 4);
    insert(&b, 2);
    Node *intersect=NULL;
    intersect=intersection(a,b);
    traverse(intersect);
}