# include <stdio.h>

void mergesort(int[],int,int);
void merge(int[],int,int,int);

void main()
{
    int a[50],n;
    printf("\nEnter array size:");
    scanf("%d",&n);
    printf("\nEnter array elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    printf("\nSorted array:");
    for(int j=0;j<n;j++)
        printf("\t%d",a[j]);
}

void mergesort(int a[50],int starti,int endi)
{
    int midi;
    if(starti<endi)
    {
        midi=(starti+endi)/2;
        mergesort(a,0,midi);
        mergesort(a,midi+1,endi);
        merge(a,starti,midi,endi);
    }
}

void merge(int a[50],int starti,int midi,int endi)
{
    int i,j,k,temp[50];
    i=starti;
    j=midi+1;
    k=0;
    
    while(i<=midi && j<=endi)
    {
        if(a[i]<=a[j])
        {
            temp[k]=a[i];
            i++;
        }
        else
        {
            temp[k]=a[j];
            j++;
        }
        k++;
    }
    
    while(i<=midi)
    {
        temp[k]=a[i];
        i++;
        k++;
    }
    while(j<=endi)
    {
        temp[k]=a[j];
        j++;
        k++;
    }
    
    k=0;
    for(i=starti;i<=endi;i++)
    {
        a[i]=temp[k];
        k++;
    }
}
