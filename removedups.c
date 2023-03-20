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

//removing dups in sorted linked list
void remove_dups(Node *head)
{
    Node *current =head;
    if(current)
    {
        Node *new=current->next;
        while(new)
        {
            if(current->data==new->data)
            {
                current->next=new->next;
                free(new);
                new=current->next;
            }
            else
            {
                current=current->next;
                new=current->next;
            }
        }
    }
}

//removing dups from unsorted list by itterative approach
void remove_dups_unsorted(Node **head)
{
    Node *curr=*head;
    if(curr)
    {
        
        while(curr)
        {
            Node *new=curr->next;
            Node *q=curr;
            while(new)
            {
                if(curr->data==new->data)
                {
                    q->next=new->next;
                    free(new);
                    new=q->next;
                }
                else
                new=new->next;
                q=q->next;
            }
            curr=curr->next;
        }
    }
}

int main()
{
    Node *head=NULL;
    insert(&head,11);
    insert(&head,11);
    insert(&head,21);
    insert(&head,43);
    insert(&head,43);
    insert(&head,60);
    traverse(head);
    remove_dups(head);
    traverse(head);
    Node *head2=NULL;
    insert(&head2,10);
    insert(&head2,6);
    insert(&head2,10);
    insert(&head2,11);
    insert(&head2,11);
    insert(&head2,100);
    insert(&head2,5);
    insert(&head2,200);
    insert(&head2,300);
    traverse(head2);
    remove_dups_unsorted(&head2);
    traverse(head2);
}