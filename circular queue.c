 

			
	
# include <stdio.h>
# define MAX  4
int queue[MAX],front=0,rear=-1;

void enqueue(int ele)
{
if((rear==MAX-1 && front==0) || (front-rear==1 && rear!=-1))
printf("\nOverflow");
else
{
rear=(rear+1)%MAX;
queue[rear]=ele;
printf("\nSuccessfully inserted:%d",ele);
}
}
void dequeue()
{
int i;


if(rear==-1)
{
printf("\nUnderflow");
}

else if(front!=rear)
{
printf("\ndeleted=%d",queue[front]);
front=(front+1)%MAX;
}
else
{
printf("\ndeleted=%d",queue[front]);
front=-1;
rear=-1;
}
}
void display()
{
int i=front;
if(rear==-1)
printf("\nEMPTY");
else
{

while(i!=rear)
{
printf("\t%d",queue[i]);
i=(i+1)%MAX;
}
printf("\t%d",queue[i]);
}
}
void main()
{
int ch,status=1,E;
while(status==1)
{
printf("\nEnter ur choice-1.Enqueue,2.Dequeue,3.Display,4.EXIT");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
printf("\nEnter ele:");
scanf("%d",&E);
enqueue(E);
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
}}


	
		
 
 

 
 

