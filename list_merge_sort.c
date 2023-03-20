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

Node *merge(Node *a,Node *b)
{
    Node *n=NULL;
    if(a==NULL)
    return b;
    if(b==NULL)
    return a;
    if(a->data < b->data)
    {
        n=a;
        n->next=merge(a->next,b);
    }
    if(b->data < a->data)
    {
        n=b;
        n->next=merge(a,b->next);
    }
    return(n);
}

void break_in_2(Node *source, Node **left, Node **right)
{
    Node *fast;
    Node *slow;
    slow=source;
    fast=source->next;
    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
    }   
    *left=source;
    *right=slow->next;
    slow->next=NULL;
}

void MergeSort(Node **head)
{
    Node *p=*head;
    Node *a,*b;
    if((p)==NULL || (p)->next==NULL)
    return;
    break_in_2(p,&a,&b);
    MergeSort(&a);
    MergeSort(&b);
    *head=merge(a,b);
}

int main()
{
    Node *head=NULL;
    insert(&head,5);
    insert(&head,11);
    insert(&head,25);
    insert(&head,10);
    insert(&head,17);
    insert(&head,100);
    insert(&head,1);
    traverse(head);
    MergeSort(&head);
    traverse(head);
}