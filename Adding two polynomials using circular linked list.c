# include <stdio.h>
# include <stdlib.h>

struct term
{
    int coeff,power;
    struct term *chain;
}*start=NULL,*last=NULL,*start1=NULL,*last1=NULL,*start2=NULL,*last2=NULL;

void append1(int c,int p)
{
    struct term *temp=(struct term*)malloc(sizeof(struct term));
    temp->coeff=c;
    temp->power=p;
    
    
    if(start1==NULL)
    {
        
        last1=temp;
        start1=temp;
        temp->chain=start1;
        
    }
    else
    {
        last1->chain=temp;
        last1=temp;
        temp->chain=start1;
    }
}

void append2(int c,int p)
{
    struct term *temp=(struct term*)malloc(sizeof(struct term));
    temp->coeff=c;
    temp->power=p;
    
    
    if(start2==NULL)
    {
       
        last2=temp;
        start2=temp;
        temp->chain=start2;
        
    }
    else
    {
        last2->chain=temp;
        last2=temp;
        temp->chain=start2;
    }

}

void input()
{
    
    int ch,c,p;
    printf("\nEnter data of polynomial 1 or 2?");
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("\nEnter coeffecient and power of the term:");
        scanf("%d%d",&c,&p);
        append1(c,p);
    }
    else if(ch==2)
    {
        printf("\nEnter coeffecient and power of the term:");
        scanf("%d%d",&c,&p);
        append2(c,p);
    }
    else
    {
        printf("\nPlease enter a valid choice:");
    }
}

void appendresult(int c,int p)
{
    struct term *temp=(struct term*)malloc(sizeof(struct term));
    temp->coeff=c;
    temp->power=p;
    
    
    if(start==NULL)
    {
        
        last=temp;
        start=temp;
        temp->chain=start;
        
    }
    else
    {
        last->chain=temp;
        last=temp;
        temp->chain=start;
    }

}

void solve()
{
    int c,p,flag=0;
    struct term *i,*j;
    i=start1;
    j=start2;
    
    do
    {
        
        do
        {
            
            if(i->power==j->power)
            {
                flag=1;
                p=i->power;
                c=i->coeff+j->coeff;
                appendresult(c,p);
                break;
            
            }
            
            j=j->chain;
        }
        while(j!=start2);
        
        if(flag==0)
        {
            p=i->power;
            c=i->coeff;
            appendresult(c,p);
        }
        
        i=i->chain;
    }
    while(i!=start1);
    
    flag=0;
   
    j=start2;
    i=start1;
    
    do
    {
        do
        {
            if(i->power==j->power)
            {
                flag=1;
                break;
            
            }
            
            i=i->chain;
        }
        while(i!=start1);
        if(flag==0)
        {
            p=j->power;
            c=j->coeff;
            appendresult(c,p);
        }
        j=j->chain;
    }
    while(j!=start2);
    
}

void display()
{
    
    
    struct term *i;
    i=start;
   
    printf("\nResultant polynomial=\n");
    
    do
    {
        printf("\t%dx^%d+",i->coeff,i->power);
       
        i=i->chain;
    }
    while(i!=start);
   
    
}

void main()
{
    int ch,status=1;
    
    while(status==1)
    {
        printf("\n1.Polynomial,2.Add,3.Print answer,4.Exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                input();
                break;
            }
            case 2:
            {
                solve();
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
            printf("Invalid choice");
            
        }
        
    }
}
