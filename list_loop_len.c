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

int loop_len(Node *head)
{
    Node *fast=head;
    Node *slow=head;
    int len =0;
    if(head!=NULL && head->next!=NULL)
    {
        int j=0;
        Node *common=(Node *)(malloc(sizeof(Node)));
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            if(fast==slow)
            {
                j++;
                printf("%d\n",fast->data);
                common=slow;
                break;
            }
            slow=slow->next;
        }
        if(j==1)
        {
            len=1;
            while(common->next!=slow)
            {
                len++;
                common=common->next;
            }
        }
    }
    return len;
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
    cycle(&head,3);
    printf("%d\n",loop_len(head));
}