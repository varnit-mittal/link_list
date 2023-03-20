#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}Node ;
int count(struct node* head,int c)
{
    Node *p=head;
    if(!p)
    return c;
    else
    {
        p=p->next;
        c+=1;
        count(p,c);
    }
}
struct node *head=NULL;
struct node * insert(int d)
{
    struct node *p=(struct node *)(malloc(sizeof(struct node)));
    p->data=d;
    p->next=head;
    head=p;
    return head;
}
int count2(Node *head);
int main()
{
    head=insert(6);
    head=insert(7);
    head=insert(1);
    head=insert(2);
    printf("%d\n",count(head,0));
    printf("%d",count2(head));
}

//Method-2
int count2(Node *head)
{
    Node *p=head;
    if(!p)
    return 0;
    else
    return 1+count2(p->next);
}