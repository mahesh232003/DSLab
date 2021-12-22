
#include <stdio.h>
#include <stdlib.h>
struct circularlist
{
    int data;
    struct circularlist *next;
};
typedef struct circularlist node;
node* create(node *first)
{
    node *new,*temp;
    int x;
    printf("Enter the data\n");
    scanf("%d",&x);
    while(x!=-1)
    {
        new=(node*)malloc(sizeof(node));
        new->data=x;
        new->next=NULL;
        if (first==NULL)
        {
            first=new;
            temp=new;
        }
        else
        {
            temp->next=new;
            temp=new;
        }
        printf("Enter data,Enter -1 to stop\n");
        scanf("%d",&x);
    }
    temp->next=first;
    return first;
}
void display(node *first)
{
    node *temp;
    if (first==NULL)
    {
        printf("No list to print");
    }
    else
    {
        temp=first;
        do
        {
            printf("|%d|-->",temp->data);
            temp=temp->next;
        }while(temp!=first);
        printf("|%d|\n",temp->data);
    }
}
int count(node *first)
{
    node *temp=first;
    int c=0;
    if (first==NULL)
    {
        return c;
    }
    else
    {
        do
        {
            c++;
            temp=temp->next;
        }while(temp!=first);
        return c;
    }
}
void search(node *first,int ele)
{
    node *temp=first;
    int flag=0;
    do
    {
        if (temp->data==ele)
        {
            flag=1;
            break;
        }
        temp=temp->next;
    }while(temp!=first);
    if (flag)
    {
        printf("Element found\n");
    }
    else
    {
        printf("Element not found\n");
    }
}
node* insertatbegin(node *first,int ele)
{
    node *temp=first,*new;
    new=(node*)malloc(sizeof(node));
    new->data=ele;
    new->next=new;
    if (first==NULL)
    {
        first=new;
        new->next=first;
    }
    else
    {
        while(temp->next!=first)
        {
            temp=temp->next;
        }
        temp->next=new;
        new->next=first;
    }
    return new;
}
node *insertatend(node *first,int ele)
{
    node *temp=first,*new;
    new=(node*)malloc(sizeof(node));
    new->data=ele;
    new->next=NULL;
    if(first==NULL)
    {
        first=new;
        new->next=first;
    }
    else
    {
        while(temp->next!=first)
        {
            temp=temp->next;
        }
        temp->next=new;
        new->next=first;
    }
    return first;
}
node* insertatpos(node *first,int pos,int ele)
{
    node *temp=first,*new;
    int n=count(first);
    new=(node*)malloc(sizeof(node));
    new->data=ele;
    new->next=NULL;
    if(pos>1 && pos<n)
    {
        for (int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        new->next=temp->next;
        temp->next=new;
    }
    return first;
}
node* delete(node *first,int ele)
{
    node *temp=first,*temp1;
    int flag=0;
    if (first==NULL)
    {
        printf("No list to delete\n");
        return first;
    }
    else
    {
        while(temp->next!=first)
        {
            temp1=temp;
            if (temp->data==ele)
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
        if (flag)
        {
            temp1->next=temp->next;
            free(temp);
            return first;
        }
        else
        {
            printf("Element not present to delete\n");
            return first;
        }
    }
}
node *sort(node *first)
{
    node *temp=first,*temp1;
    int x;
    for(temp;temp!=NULL;temp=temp->next)
    {
        for(temp1=temp->next;temp1!=NULL;temp1=temp1->next)
        {
            if(temp->data>temp1->data)
            {
                x=temp->data;
                temp->data=temp1->data;
                temp1->data=x;
            }
        }
    }
    return first;
}
int main()
{
    int c,ele,ele1,ele2,ele3,pos,ele4;
    node *head=NULL;
    head=create(head);
    display(head);
    c=count(head);
    printf("%d elements in list\n",c);
    printf("Enter the element to search\n");
    scanf("%d",&ele);
    search(head,ele);
    printf("Enter element to insert at first\n");
    scanf("%d",&ele1);
    head=insertatbegin(head,ele1);
    display(head);
    printf("Enter element to insert at end\n");
    scanf("%d",&ele2);
    head=insertatend(head,ele2);
    display(head);
    printf("Enter position to insert\n");
    scanf("%d",&pos);
    printf("Enter element to insert\n");
    scanf("%d",&ele3);
    head=insertatpos(head,pos,ele3);
    display(head);
    printf("Enter element to delete\n");
    scanf("%d",&ele4);
    head=delete(head,ele4);
    display(head);
    head=sort(head);
    display(head);
    return 0;
}





