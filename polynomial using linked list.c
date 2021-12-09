#include <stdio.h>
#include <stdlib.h>
struct polynomial
{
	int coeff;
	int exp;
	struct polynomial *next;
};
typedef struct polynomial node;
node* addterm(node *first,node *new)                                                                                         {
	node *temp,*temp1;
	if (first==NULL)                                                                                                                            {
		first=new;
		temp=new;
	}
	else if(first->exp<new->exp)                                                                                                        {                                                                                                                                             		new->next=first;
		first=new;
	}
	else if(first->exp==new->exp)
	{
		first->coeff=first->coeff+new->coeff;
	}
	else
	{
		temp=first->next;
		temp1=first;
		while(temp!=NULL && temp->exp>new->exp)
		{
			temp1=temp;
			temp=temp->next;
		}
		if(temp==NULL)
		{
			temp1->next=new;
		}                                                                                                                                     	else if (temp->exp==new->exp)
		{
			temp->coeff=temp->coeff+new->coeff;
		}
		else
		{
			temp1->next=new;
			new->next=temp;
		}
	}
	return first;                                                                                                                  }
node* create()
{
	node *new,*first=NULL;
	char c;
	do
	{
		new=(node*)malloc(sizeof(node));
		new->next=NULL;
		printf("Enter coeff\n");
		scanf("%d",&new->coeff);
		printf("Enter the exponent\n");
		scanf("%d",&new->exp);
		first=addterm(first,new);
		printf("Enter any term other than 'n' to stop\n");
		scanf(" %c",&c);
	}while(c!='n');
	return first;                                                                                                                 
}                        
void display(node *first)
{
	node *temp=first;
	if (temp==NULL)
	{
	printf("No polynomial to display\n");                                                                              	}
	else                                                                                                                                  	{
		while(temp->next!=NULL)
		{
			printf("%dX^%d+",temp->coeff,temp->exp);
			temp=temp->next;
		}
		printf("%dX^%d\n",temp->coeff,temp->exp);
	}
}                                                                                                                                     
int main()
{
	node *head=NULL;
	head=create();
	display(head);
	return 0;
}      

              
