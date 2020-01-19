# include <stdio.h>
# include <stdlib.h>

struct block
{
    int data;
    struct block *chain;
}*front=NULL,*rear=NULL;

void enqueue(int);
void dequeue();
int isempty();
void display();

void main()
{
    int ele,status=1,ch;
    while(status==1)
    {
        printf("\n1.Enqueue,2.Dequeue,3.Print,4.EXIT");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("\nEnter an ele:");
                scanf("%d",&ele);
                enqueue(ele);
                break;
            }
            case 2:
            {
                dequeue();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                status=0;
                break;
            }
            default:
            printf("\nInvalid choice");
            
        }
    }
}

void enqueue(int ele)
{
    struct block *temp=(struct block*)malloc(sizeof(struct block*));
    temp->data=ele;
    temp->chain=NULL;
    if(isempty()==1)
    {
        front=temp;
        rear=temp;
    }
    else
    {
        rear->chain=temp;
        rear=temp;
    }
    printf("\n%d inserted",rear->data);
}

void dequeue()
{
    struct block *i;
    if(isempty()==1)
    {
        printf("\nUnderflow");
    }
    else
    {
        if(front==rear)
        {
            printf("\nDeleted=%d",front->data);
            front=NULL;
            rear=NULL;
        }
        else
        {
            printf("\nDeleted=%d",front->data);
            i=front;
            free(i);
            front=front->chain;
        }
    }
}

void display()
{
    if(isempty()==0)
    {
        struct block *i=front;
        printf("\nQueue contains:");
        while(i!=NULL)
        {
            printf("\n%d",i->data);
            i=i->chain;
        }
    }
    else
    {
        printf("\nSorry,queue is empty");
    }
}

int isempty()
{
    if(rear==NULL)
        return 1;
    else
        return 0;
}
