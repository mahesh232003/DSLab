#include<stdio.h>
#include<stdlib.h>
#define MAX 50
struct polynomial
{
    int highpower;
    int coeff[MAX];
};
int max(int a,int b)
{
    return(a>b?a:b);
}
typedef struct polynomial poly;
poly* create()
{
    poly *p;
    int i;
    p=(poly*)malloc(sizeof(poly));
    printf("enter the highpower of the polynomial\n");  
    scanf("%d",&p->highpower);
    for(i=p->highpower;i>=0;i--)
    {
        printf("enter coeffficient of %d exponent\n",i);
        scanf("%d",&p->coeff[i]);
    }
    return p;
}
poly* add(poly *p1,poly *p2)
{
    poly *p3;
    int i;
    p3=(poly*)malloc(sizeof(poly));
    p3->highpower=max(p1->highpower,p2->highpower);
    for(i=p3->highpower;i>=0;i--)
    {
        p3->coeff[i]=p1->coeff[i]+p2->coeff[i];
    }
    return p3;
}
poly *subtract(poly *p1,poly *p2)
{
    poly *p3;
    int i;
    p3=(poly*)malloc(sizeof(poly));
    p3->highpower=max(p1->highpower,p2->highpower);
    for(i=p3->highpower;i>=0;i--)
    {
        p3->coeff[i]=p1->coeff[i]-p2->coeff[i];
    }
    return p3;
}
poly* multiply(poly *p1,poly *p2)
{
    poly *p3;
    int i,j;
    p3=(poly*)malloc(sizeof(poly));
    p3->highpower=p1->highpower+p2->highpower;
    for(i=p1->highpower;i>=0;i--)
    {
        for(j=p2->highpower;j>=0;j--)
        {
            p3->coeff[i+j]=p3->coeff[i+j]+p1->coeff[i]*p2->coeff[j];
        }
    }
    return p3;
}
void display(poly *p)
{
    int i;
    for(i=p->highpower;i>=0;i--)
    {
        printf("%dX^%d+",p->coeff[i],i);
    }
}
int main()
{
    poly *p1,*p2,*p3;
    int ch;
    printf("enter first polynomial\n");
    p1=create();
    printf("enter second polynomial\n");
    p2=create();
    while(1)
    {
        printf("\n1:addition\n2:subtraction\n3:multiplication\n4:exit\n");
        printf("enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:p3=add(p1,p2);
                    printf("the result of addition is\n");
                    display(p3);
                    break;
            case 2:p3=subtract(p1,p2);
                    printf("the result of subtraction\n");
                    display(p3);
                    break;
            case 3:p3=multiply(p1,p2);
                    printf("the result of multiplication is\n");
                    display(p3);
                    break;
            case 4:exit(0);
            default:printf("check choice\n");
                    break;
        }
    }
}
