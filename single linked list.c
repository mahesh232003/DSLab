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
int count(node *first)
{
        node *temp=first;
        int c=0;
        while(temp!=NULL)
                {
                        c++;
                        temp=temp->next;
                }
        return c;
}
void search(node *first,int ele)
{
        int x=ele;
        int c=0;
        node* temp=first;
        while(temp!=NULL)
        {
                if (temp->data==x)
                {
                        printf("Element found\n");
                        c=c+1;
                        break;
                }
                else
                {
                        temp=temp->next;
                }
        }
        if (c==0)
        {
                printf("Element not found\n");
        }
}
node* insert_at_beginning(node* first,int x)
{
        node* new=(node*)malloc(sizeof(node));
        new->data=x;
        new->next=NULL;
        if (first==NULL)
        {
                first=new;
        }
        else
        {
                new->next=first;
                first=new;
        }
        return first;
}
node* insert_at_ending(node* first,int x)
{
        node* new=(node*)malloc(sizeof(node));
        node* temp=first;
        new->data=x;
        new->next=NULL;
        if (first==NULL)
        {
                first=new;
        }
        else
        {
                while(temp->next!=NULL)
                {
                        temp=temp->next;
                }
                temp->next=new;
        }
        return first;
}
node* insert(node* first,int x,int pos)
{
        int i;
        node *temp=first;
        int n=count(first);
        if (pos>1&&pos<n)
        {
                node *new=(node*)malloc(sizeof(node));
                new->data=x;
                new->next=NULL;
                for (i=0;i<pos-1;i++)
                {
                        temp=temp->next;
                }
                new->next=temp->next;
                temp->next=new;
        }
        return first;
}
node* delete(node* first,int x)
{
        node* temp;
        node* temp1;
        int flag=0;
        temp=first;
        if(first->data==x)
        {
                first=first->next;
                free(temp);
        }
        else
        {
                temp1=first;
                temp=first->next;
                while(temp!=NULL)
                {
                        if (temp->data==x)
                        {
                                flag=1;
                                break;
                        }
                        else
                        {
                                temp1=temp;
                                temp=temp->next;
                        }
                }
                if (flag==1)
                {
                        temp1->next=temp->next;
                        free(temp);
                }
                else
                {
                        printf("Element not found to delete\n");
                }
}
node* sort(node* first)
{
        for(temp1=first;temp1->next!=NULL;temp1=temp1->next)
        {
                for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
                {
                        if (temp1->data>temp2->data)
                        {
                                x=temp1->data;
                                temp1->data=temp2->data;
                                temp2->data=x;
                        }
                }
        }
        return first;
}
node* reverse(node* first)
{
        node *pre=first,*prev=NULL,*save;
        while(pre!=NULL)
        {
                save=pre->next;
                pre->next=prev;
                prev=pre;
                pre=save;
        }
        return prev;
}
int main()
{
        int x,c,ele,xl,xi,pos,xd,ch;
        node *head=NULL;
        node *iob,*ioe,*in;
        scanf("%d",&ch);
        while(ch!=11)
        {
                switch(ch)
                {
                        case 1: head=create(head);
                                break;
                        case 2: display(head);
                                break;
                                break;
                        case 4: printf("Enter element to search:");
                                scanf("%d",&ele);
                        case 5: printf("Enter element to insert at beginning:");
                                scanf("%d",&x);
                                head=insert_at_beginning(head,x);
                                display(head);
                                break;
                        case 6: printf("Enter element to insert at ending:");
                                scanf("%d",&xl);
                                head=insert_at_ending(head,xl);
                                display(head);
                                break;
                        case 7: printf("Enter position to insert an element:");
                                scanf("%d",&pos);
                                printf("Enter element to insert at position:");
                                scanf("%d",&xi);
                                head=insert(head,xi,pos);
                                display(head);
                                break;
                        case 8: printf("Enter element to delete:");
                                scanf("%d",&xd);
                                delete(head,xd);
                                display(head);
                                break;
                        case 9: head=sort(head);
                                display(head);
                                break;
                        case 10:head=reverse(head);
                                display(head);
                                break;
                        default:printf("Enter a correct choice\n");
                                break;
                }
                printf("Enter your choice\n1:create\n2:display\n3:count\n4:search\n5:insert at beginning\n6:insert at ending\n7:insert at position\n8:delete\n9:sort\n10:reverse\n11:exit\n");
                scanf("%d",&ch);
        }
        if (ch==11)
        {
                printf("You entered 11 so exitting program\n");
        }
        return 0;
}
