#include <stdio.h>
#include <stdlib.h>
struct AVL
{
    int data,ht;
    struct AVL *left,*right;
};
typedef struct AVL node;
int max(int a,int b)
{
    if (a>=b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int height(node*p)
{
    if(p==NULL)
    {
        return -1;
    }
    else
    {
        return (1+max(height(p->left),height(p->right)));
    }
}
node* single_ll(node *k2)
{
    node *k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;
    k2->ht=max(height(k2->left),height(k2->right))+1;
    k1->ht=max(height(k1->left),height(k1->right))+1;
    return k1;
}
node* single_rr(node *k1)
{
    node *k2=k1->right;
    k1->right=k2->left;
    k2->left=k1;
    k1->ht=max(height(k1->left),height(k1->right));
    k2->ht=max(height(k2->left),height(k2->right));
    return k2;
}
node* double_lr(node *k3)
{
    k3->left=single_rr(k3->left);
    return (single_ll(k3));
}
node* double_rl(node *k1)
{
    k1->right=single_ll(k1->right);
    return (single_rr(k1));
}
node* insert(node *p,int x)
{
    if (p==NULL)
    {
        p=(node*)malloc(sizeof(node));
        p->data=x;
        p->left=p->right=NULL;
        p->ht=0;
    }
    else if (x<p->data)
    {
        p->left=insert(p->left,x);
        if (abs(height(p->left)-height(p->right))==2)
        {
            if (x<p->left->data)
            {
                p=single_ll(p);
            }
            else
            {
                p=double_lr(p);
            }
        }
    }
    else if (x>p->data)
    {
        p->right=insert(p->right,x);
        if (abs(height(p->right)-height(p->left))==2)
        {
            if(x>p->right->data)
            {
                p=single_rr(p);
            }
            else
            {
                p=double_rl(p);
            }
        }
    }
    p->ht=max(height(p->left),height(p->right));
    return p;
}
void inorder(node *p)
{
    if (p!=NULL)
    {
        inorder(p->left);
        printf("%d\t",p->data);
        inorder(p->right);
    }
}
int main()
{
    node* root=NULL,temp;
    int x,ch;
    while(1)
    {
        printf("\nEnter your choice\n");
        printf("1:Insert\n2:Inorder\n3:Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter data\n");
                    scanf("%d",&x);
                    root=insert(root,x);
                    break;
            case 2: inorder(root);
                    break;
            case 3: exit(0);
            default:printf("Enter a valid choice\n");
                    break;
        }
    }
}


