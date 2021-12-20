#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct slist
{
        int data;
        struct slist *next;
};
typedef struct slist node;
node* create (node* first)
{
        node *new,*prev;
        int x;
        printf("Enter data,enter -1 to stop\n");
        scanf("%d",&x);
        while(x!=-1)
        {
                new=(node*)malloc(sizeof(node));
                new->data=x;
                new->next=NULL;
                if (first==NULL)
                {
                        first=new;
                        prev=new;
                }
                else
                {
                        prev->next=new;
                        prev=new;
                }
                printf("Enter data,enter -1 to stop\n");
                scanf("%d",&x);
        }
        return first;
}
void display(node *first)
{
        node *temp=first;
        if (first==NULL)
        {
                printf("No list to print\n");
        }
        while(temp!=NULL)
        {
                printf("|%d|-->",temp->data);
                temp=temp->next;
        }
        if (temp==NULL)
        {
                printf("NULL\n");
        }
}
node *delete(node *first,int x)
{
    node *temp=first,*temp1;
    while((first->data)>x)
    {
        temp=first;
        first=first->next;
        free(temp);
    }
    temp1=first;
    temp=first->next;
    while(temp!=NULL)
    {
        if ((temp->data)>x)
        {
            temp1->next=temp->next;
            free(temp);
        }
        else
        {
            temp1=temp;
            temp=temp->next;
        }
    }
    return first;
}
int main()
{
    node *head=NULL;
    int x;
    head=create(head);
    display(head);
    printf("Enter element to delete all elements greater than entered\n");
    scanf("%d",&x);
    head=delete(head,x);
    display(head);
}
