//PIVOT IS LAST ELEMENT:

# include <stdio.h>

void quicksort(int[],int,int);
int partition(int[],int,int);
void display(int[],int);

void quicksort(int a[50],int starti,int endi)
{
    int pin;
    if(starti<endi)
    {
        pin=partition(a,starti,endi);
        quicksort(a,starti,pin-1);
        quicksort(a,pin+1,endi);
    }
   
}

int partition(int a[50],int starti,int endi)
{
    int i=starti,pivot,pin,temp;
    pin=starti;
    pivot=a[endi];
    while(i<endi)
    {
        if(a[i]<=pivot)
        {
            temp=a[i];
            a[i]=a[pin];
            a[pin]=temp;
            pin++;
        }
        i++;
    }
    temp=a[endi];
    a[endi]=a[pin];
    a[pin]=temp;
    return pin;
}

void display(int a[50],int n)
{
    printf("\nSorted order:\n");
    for(int i=0;i<n;i++)
    {
        printf("\n%d",a[i]);
    }
}

void main()
{
    int i,len,a[50];
    printf("\nHow many elements?");
    scanf("%d",&len);
    printf("\nEnter them:\n");
    for(i=0;i<len;i++)
    {
        scanf("\n%d",&a[i]);
    }
    quicksort(a,0,len-1);
    display(a,len);
}
