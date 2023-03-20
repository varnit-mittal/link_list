#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
} ;
int count(struct node* head)
{
    struct node *p=head;
    int count =0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
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
int main()
{
    head=insert(6);
    head=insert(7);
    head=insert(1);
    head=insert(2);
    printf("%d",count(head));
}