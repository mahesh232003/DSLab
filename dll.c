
#include <stdio.h>
#include <stdlib.h>
struct dll 
{
    int data;
    struct dll *left,*right;
};
typedef struct dll node;
node* create(node *first)
{
    node *temp,*new;;
    int x;
    printf("Enter data\n");
    scanf("%d",&x);
    while(x!=-1)
    {
        new=(node*)malloc(sizeof(node));
        new->data=x;
        new->left=NULL;
        new->right=NULL;
        if (first==NULL)
        {
            first=new;
            temp=new;
        }
        else
        {
            temp->right=new;
            new->left=temp;
            temp=new;
        }
        printf("Enter data (Enter -1 to stop)\n");
        scanf("%d",&x);
    }
    return first;
}
void display(node *first)
{
    node *temp=first;
    if (first==NULL)
    {
        printf("No list to display\n");
    }
    else
    {
        printf("NULL");
        while(temp!=NULL)
        {
            printf("<--|%d|-->",temp->data);
            temp=temp->right;
        }
        printf("NULL\n");
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
        while(temp!=NULL)
        {
            c++;
            temp=temp->right;
        }
    }
    return c;
}
void search(node *first,int ele)
{
    node *temp=first;
    int flag=0;
    if (first==NULL)
    {
        printf("No list to search\n");
    }
    else
    {
        while(temp!=NULL)
        {
            if (temp->data==ele)
            {
                flag=1;
                break;
            }
            else
            {
                temp=temp->right;
            }
        }
        if (flag)
        {
            printf("Element found\n");
        }
        else
        {
            printf("Element not found\n");
        }
    }
}
node* sort(node *first)
{
    int x;
    node *temp=first,*temp1;
    if(first==NULL)
    {
        printf("No elements to sort\n");
    }
    else
    {
        for(temp=first;temp->right!=NULL;temp=temp->right)
        {
            for(temp1=temp->right;temp1!=NULL;temp1=temp1->right)
            {
                if(temp->data>temp1->data)
                {
                    x=temp1->data;
                    temp1->data=temp->data;
                    temp->data=x;
                }
            }
        }
    }
    return first;
}
node *delete(node *first,int x)
{
    node *temp=first,*temp1;
    int flag=0;
    if (first==NULL)
    {
        printf("NO elements to delete\n");
    }
    else
    {
        if (first->data==x)
        {
            first=first->right;
            free(temp);
        }
        else
        {
            temp1=first->right;
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
                    temp=temp->right;
                }
            }
            if(flag)
            {
                temp1->right=temp->right;
                free(temp);
            }
            else
            {
                printf("Element not found to delete\n");
            }
        }
    }
    return first;
}
node* insertatbegin(node *first,int x)
{
    node *new,*temp;
    new=(node*)malloc(sizeof(node));
    new->data=x;
    new->right=NULL;
    new->left=NULL;
    if (first==NULL)
    {
        first=new;
    }
    else
    {
        new->right=first;
        first->left=new;
        first=new;
    }
    return first;
}
node* insertatend(node *first,int x)
{
    node *new,*temp=first;
    new=(node*)malloc(sizeof(node));
    new->data=x;
    new->right=NULL;
    new->left=NULL;
    if(first==NULL)
    {
        first=new;
    }
    else
    {
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        temp->right=new;
        new->left=temp;
    }
    return first;
}
node* insertatpos(node *first,int x,int pos)
{
    int i;
    node *temp=first;
    int n=count(first);
    if (pos>1&&pos<n)
    {
        node *new=(node*)malloc(sizeof(node));
        new->data=x;
        new->right=NULL;
        new->left=NULL;
        for (i=1;i<pos-1;i++)
        {
            temp=temp->right;
        }
        new->right=temp->right;
        temp->right=new;
    }
    return first;
}
node* reverse(node *first)
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
    int c,ele,x,x1,x2,x3,pos;
    node *head=NULL;
    head=create(head);
    display(head);
    c=count(head);
    printf("Number of elements in double linked list are %d\n",c);
    printf("Enter element to search\n");
    scanf("%d",&ele);
    search(head,ele);
    display(head);
    printf("After sorting\n");
    head=sort(head);
    display(head);
    printf("Enter element to delete\n");
    scanf("%d",&x);
    head=delete(head,x);
    display(head);
    printf("Enter element to insert at beginning\n");
    scanf("%d",&x1);
    head=insertatbegin(head,x1);
    display(head);
    printf("Enter element to insert at ending\n");
    scanf("%d",&x2);
    head=insertatend(head,x2);
    display(head);
    printf("Enter element to insert at a postion\n");
    scanf("%d",&x3);
    printf("Enter position to insert\n");
    scanf("%d",&pos);
    head=insertatpos(head,x3,pos);
    display(head);
    return 0;
}


