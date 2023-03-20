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

void cycle(Node **head, int m) //code which creates a cycle as demanded by the user
{
    Node *p=*head;
    Node *q=*head;
    if(*head)
    {
        while(p->next) // traverses tll the end
        {
            p=p->next;
        }
        int n;
        for(n=1;n<m;n++) //traverses till needed by the user to create a cycle
        q=q->next;
        p->next=q;
    }
}

int loop_len(Node *l1, Node *common)
{
    int len=1;
    while(common->next!=l1)
    {
        len++;
        common=common->next;
    }
    return len;
}
void loop_remove(Node *head)
{
    Node *common=NULL;
    Node *slow=head;
    Node *fast =head;
    if(head)
    {
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            if(fast==slow)
                break;
            slow=slow->next;
        }
        if(fast==slow)
        {
            int k=loop_len(slow,fast);
            slow=head;
            fast=head;
            int i;
            for(i=0;i<k;i++)
            fast=fast->next;
            while(fast->next!=slow->next)
            {
                fast=fast->next;
                slow=slow->next;
            }
            fast->next=NULL;
        }
    }
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
    cycle(&head,5);
    loop_remove(head);
    traverse(head);
}