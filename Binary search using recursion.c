# include <stdio.h>

void binsearch(int beg,int end,int arr[10],int searchele);

void main()
{
    int arr[5]={10,20,30,40,50},searchele;
    printf("\nEnter the search element:");
    scanf("\n%d",&searchele);
    binsearch(0,4,arr,searchele);
}

void binsearch(int beg,int end,int arr[10],int searchele)
{
    int mid;
    if(beg>end)
    {
        printf("\n%d not found",searchele);
        return;
    }
    if(beg<=end)
    {
        mid=(beg+end)/2;
        if(arr[mid]==searchele)
        {
            printf("\n%d found @ %d pos",searchele,mid+1);
            return;
        }
        else if(arr[mid]<searchele)
        {
            binsearch(mid+1,end,arr,searchele);
            
        }
        else
        {
             binsearch(beg,mid-1,arr,searchele);
        }
        
    }
}
