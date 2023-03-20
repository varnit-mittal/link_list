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

Node* rec_rev(Node *curr, Node *prev, Node* new)
{
    if(!curr)
    {
        return(prev);
    }
    if(curr)
    {      
        new=curr->next;
        curr->next=prev;
        prev=curr;
        curr=new;
        rec_rev(curr,prev,new);        
    }
}
Node *itt_rev(Node *head)
{
    if(head &&head->next)
    {
        Node *prev=NULL,*current=head,*new=NULL;
        while(current)
        {
            new=current->next;
            current->next=prev;
            prev=current;
            current=new;
        }
        head=prev;
    }
    return head;
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

int main()
{
    Node *head=NULL;
    insert(&head,87);
    insert(&head,97);
    insert(&head,7);
    insert(&head,56);
    insert(&head,8767);
    insert(&head,7638);
    insert(&head,97);
    traverse(head);
    head=rec_rev(head,NULL,NULL);
    traverse(head);
}