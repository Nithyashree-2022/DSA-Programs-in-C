# include <stdio.h>
# include <stdlib.h>

int v,stack[10],top=-1,arrayBFS[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},arrayDFS[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

void push(int E);
int pop();
int findDFS(int);
int findBFS(int);
void displayDFS();
void displayBFS();
void DFS(int adjmat[10][10]);
void BFS(int adjmat[10][10]);
int find_s(int);

void main()
{
    int matrix[10][10];
    printf("\nGRAPH TRAVERSALS\n");
    printf("\nNo of vertices in graph?");
    scanf("%d",&v);
    printf("\nEnter adjacency matrix");
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    BFS(matrix);
    DFS(matrix);
    
}

void DFS(int adjmat[10][10])
{
    int counter,i,k=0,ele;
    push(0);
    counter=top;
    //printf("\ncalled");
    while(counter!=-1)
    {
        i=stack[top];
        ele=pop();
        counter--;
        if(findDFS(ele)==0)
        {
            arrayDFS[k]=ele;
            k++;
            //printf("\nvisited");
        }
        for(int j=0;j<v;j++)
        {
            if(adjmat[i][j]==1 && findDFS(j)==0 && find_s(j)==0)
            {
                push(j);
                counter++;
            }
        }
       
    }
    displayDFS();
}

void BFS(int adjmatrix[10][10])
{
    int i,j,k=0;
    arrayBFS[k]=0;
    k++;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            if(adjmatrix[i][j]==1)
            {
                if(findBFS(j)==0)
                {
                    arrayBFS[k]=j;
                    k++;
                
                }
            }
        }
    }
    displayBFS();
}

void displayBFS()
{
    printf("\nBFS Traversal:");
    for(int i=0;i<v;i++)
    {
        printf("\t%d",arrayBFS[i]);
    }
}

int findBFS(int j)
{
    int i=0;
    
    while(arrayBFS[i]!=-1)
    {    
        if(arrayBFS[i]==j)
        {
            return 1;
        }
        i++;
    }
    
    return 0;
}

int findDFS(int j)
{
    int i=0;
    
    while(arrayDFS[i]!=-1)
    {    
        if(arrayDFS[i]==j)
        {
            return 1;
        }
        i++;
    }
    
    return 0;
}

void displayDFS()
{
    printf("\nDFS Traversal:");
    for(int i=0;i<v;i++)
    {
        printf("\t%d",arrayDFS[i]);
    }
}

int pop()
{
    int i;
    if(top!=-1)
    {
        i=top;
        top--;
        //printf("\ndeleted");
        return(stack[i]);
    }
   
}

void push(int E)
{
    if(top==v-1)
    {
        printf("\noverflow");
    }
    if(top<v)
    {
        top++;
        stack[top]=E;
    }
    //printf("\ninserted");
    
}

int find_s(int item)
{
    int i=top;
    while(i!=-1)
    {
        if(stack[i]==item)
        {
            return 1;
        }
        i--;
    }
    return 0;
}





