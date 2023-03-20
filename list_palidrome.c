#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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

void itt_rev(Node **head)
{
    Node *curr=*head,*prev=NULL,*new=NULL;
    if((*head)!=NULL && (*head)->next!=NULL)
    {
        while(curr)
        {
            new=curr->next;
            curr->next=prev;
            prev=curr;
            curr=new;
        }
        *head=prev;
    }
}

int count2(Node *head)
{
    Node *p=head;
    if(!p)
    return 0;
    else
    return 1+count2(p->next);
}

//Method-1 to find if the list is a palindrome or not
int ispalin(Node *head)
{
    int k=count2(head)/2;
    Node *p=head;
    Node *q=head;
    int j,s=0;
    for(j=0;j<k;j++)
    q=q->next;
    itt_rev(&q);
    for(j=0;j<k;j++)
    {
        if(p->data==q->data)
        s++;
        p=p->next;
        q=q->next;
    }
    if(s==k)
    return 1;
    else
    return 0;
}

//Method2- This is the most optimal method to find if a list is a palindrome or not
//using tail recurssion

bool ispalinutil(Node **left, Node *right)
{
    if(right==NULL)
    return true;
    bool isp =ispalinutil(left,right->next);
    if(!isp)
    return false;
    bool isp1=(right->data==(*left)->data);
    (*left)=(*left)->next;
    return isp1;
}

bool ispalin2(struct node *head)
{
    return ispalinutil(&head,head);
}

int main()
{
    Node *head=NULL;
    insert(&head,23);
    insert(&head,34);
    insert(&head,35);
    insert(&head,26);
    insert(&head,26);
    insert(&head,35);
    insert(&head,34);
    insert(&head,23);
    printf("Result of most optimal method: ");
    if(ispalin2(head))
    printf("True\n");
    else
    printf("False\n");
    printf("Result of method1 (This alters the list): ");
    if(ispalin(head))
    printf("True\n");
    else
    printf("False\n");
}