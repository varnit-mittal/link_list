#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}Node;
Node* add_at_begin1(Node* head, int i)
{
    Node *new=(Node *)(malloc(sizeof(Node)));
    new->data=i;
    new->next=head;
    head=new;
    return head;
}
void add_at_begin2(Node **head,int i)
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

void append_node(Node **head,int i)
{ 
    Node *new=(Node *)(malloc(sizeof(Node)));
    new->data=i;
    new->next=NULL;
    Node *p=(Node *)(malloc(sizeof(Node)));
    p=*head;
    if(p==NULL)
    {
    *head=new;
    }
    else
    {
        while(p->next)
        p=p->next;
        p->next=new;
    }
    
}

void insert_after_k(Node **head,int i,int k)
{
    Node *new=(Node *)(malloc(sizeof(Node)));
    new->data=i;
    new->next=NULL;
    Node *p=(Node *)(malloc(sizeof(Node)));
    p=*head;
    if(!p)
    p=new;
    else
    {
        int j;
        for(j=1;j<k;j++)
        p=p->next;
        new->next=p->next;
        p->next=new;
    }
}

//del node at key
void delatkey(Node **head,int key)
{
    if((*head))
    {
        Node *p=*head;
        Node *q=p->next;
        if(q)
        {
            while(q && q->data!=key)
            {
                p=q;
                q=p->next;
            }
            if(q)
            {
            p->next=q->next;
            free(q);
            }
        }
        else
        {
            if(p->data == key)
            {
                *head=q;
                free(p);
            }
        }
    }
}
void delatbegin(Node **head)
{
    if((*head))
    {
        Node *p=*head;
        *head=(*head)->next;
        free(p);
    }
}
void delatend(Node **head)
{
    if((*head))
    {
        Node *p=*head;
        Node *q=p->next;
        if(q)
        {
            while(q->next)
            {
                p=q;
                q=p->next;
            }
            free(q);
            p->next=NULL;
        }
        else
        {
            *head=(*head)->next;
            free(p);
        }
    }
}

void rec_deldatatkey(Node **head,int key)
{
    Node *p=*head;
    Node *q=p->next;
    if(q)
    {
        if(q->data ==key)
        {
            p->next=q->next;
            free(q);
        }
        else
        {
            rec_deldatatkey(&(p->next),key);
        }
    }
}

int main()
{
    Node *head=NULL;
    delatkey(&head,8);
    delatbegin(&head);
    append_node(&head,7);
    // delatend(&head);
    add_at_begin2(&head,8);
    delatkey(&head,700);
    head=add_at_begin1(head,9);
    add_at_begin2(&head,10);
    add_at_begin2(&head,11);
    delatkey(&head,8);
    append_node(&head,6);
    append_node(&head,100);
    head=add_at_begin1(head,76739);
    add_at_begin2(&head,2000);
    add_at_begin2(&head,2010);
    add_at_begin2(&head,2030);
    delatbegin(&head);
    delatend(&head);
    insert_after_k(&head,1000,3);
    rec_deldatatkey(&head,76739);
    traverse(head);
}