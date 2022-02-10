#define max 20
int front=-1,rear=-1;
int a[max];
void enqueue(int x)
{
        if(rear==max-1)
        {
                printf("Queue overflow\n");
        }
        else
        {
                if (front==-1)
                {
                        front=rear=0;
                }
                else
                {
                        rear++;
                }
                a[rear]=x;
        }
}
int doqueue()
{
        int x;
        if (front==-1)
        {
                return -1;
        }
        else
        {
                x=a[front];
                if(front==rear)
                {
                        front=rear=-1;
                }
                else
                {
                        ++front;
                }
                return x;
        }
}
void display()
{
        int i;
        if (front==-1)
        {
                printf("No Queue to print\n");
        }
        else
        {
                for (i=front;i<=rear;i++)
                {
                        printf("%3d",a[i]);
                }
                printf("\n");
        }
}
int main()
{
        int ch,x,c;
        while(1)
        {
                printf("Enter your choice\n");
                printf("1:Insert\n2:Delete\n3:Display\n4:Exit\n");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1:printf("Enter any charecter(-1 to stop)\n");
                               scanf("%d",&c);
                               while(c!=-1)
                               {
                                       printf("Enter element to insert into queue\n");
                                       scanf("%d",&x);
                                       enqueue(x);
                                       printf("Enter -1 to stop\n");
                                       scanf("%d",&c);
                               }
                               break;
                        case 2:x=doqueue();
                               if (x==-1)
                               {
                                       printf("Queue underflow\n");
                               }
                               else
                               {
                                       printf("Element deleted is:%d",x);
                               }
                               break;
                        case 3:printf("Elements in Queue are\n");
                               display();
                               break;
                        case 4:exit(0);
                }
        }
        return 0;
}
