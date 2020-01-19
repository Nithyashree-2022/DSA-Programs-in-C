# include <stdio.h>
# include <math.h>
float stack[50];
int integers[50],top=-1;
void push(float);
float pop();
int isoperator(char);
int isoperand(char);
void evaluate(char[]);
float sum(int[],int);
float chartofloat(char);
int chartoint(char);

void evaluate(char e[50])
{
    float n1,n2,ans;
    int i=0,k;
    while(e[i]!='\0')
    {
        if(isoperand(e[i])==1)
        {
            push(chartofloat(e[i]));
            
        }
        else if(isoperator(e[i])==1)
        {
            switch(e[i])
            {
                case '+':
                {
                    n1=pop();
                    n2=pop();
                    ans=n2+n1;
                    push(ans);
                    break;
                }
                case '-':
                {
                    n1=pop();
                    n2=pop();
                    ans=n2-n1;
                    push(ans);
                    break;
                }
                case '*':
                {
                    n1=pop();
                    n2=pop();
                    ans=n2*n1;
                    push(ans);
                    break;
                }
                case '/':
                {
                    n1=pop();
                    n2=pop();
                    ans=n2/n1;
                    push(ans);
                    break;
                }
                case '^':
                {
                    n1=pop();
                    n2=pop();
                    ans=pow(n2,n1);
                    push(ans);
                    break;
                }
                default:
                printf("\n");
                
            }
        }
        else
        {
            if(e[i]=='[')
            {
                i++;
                k=0;
                while(e[i]!=']')
                {
                    
                    integers[k]=chartoint(e[i]);
                    k++;
                    i++;
                }
                push(sum(integers,k));
            }
        }
        i++;
    }
    printf("\nAnswer=%f",pop());
}
void push(float ele)
{
    top++;
    stack[top]=ele;
    
}
float pop()
{
    int i=top;
    if(top!=-1)
    {
        top--;
        return(stack[i]);
    }
}
int isoperand(char ch)
{
    if(ch>='0' && ch<='9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isoperator(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':return 1;
        default: return 0;
        
    }
}
float sum(int numbers[10],int len)
{
    int j;
    float sum=0.0;
    for(j=0;j<len;j++)
    {
        sum=sum+(numbers[j]*pow(10,len-j-1));
        
    }
    return((float)sum);
}
float chartofloat(char ch)
{
    switch(ch)
    {
        case '0':
        {
            return 0.0;
            break;
        }
        case '1':
        {
            return 1.0;
            break;
        }
        case '2':
        {
            return 2.0;
            break;
        }
        case '3':
        {
            return 3.0;
            break;
        }
        case '4':
        {
            return 4.0;
            break;
        }
         case '5':
        {
            return 5.0;
            break;
        }
        case '6':
        {
            return 6.0;
            break;
        }
        case '7':
        {
            return 7.0;
            break;
        }
        case '8':
        {
            return 8.0;
            break;
        }
        case '9':
        {
            return 9.0;
            break;
        }
        default:
        printf("?");
        
    }
}
int chartoint(char ch)
{
    switch(ch)
    {
        case '0':
        {
            return 0;
            break;
        }
        case '1':
        {
            return 1;
            break;
        }
        case '2':
        {
            return 2;
            break;
        }
        case '3':
        {
            return 3;
            break;
        }
        case '4':
        {
            return 4;
            break;
        }
         case '5':
        {
            return 5;
            break;
        }
        case '6':
        {
            return 6;
            break;
        }
        case '7':
        {
            return 7;
            break;
        }
        case '8':
        {
            return 8;
            break;
        }
        case '9':
        {
            return 9;
            break;
        }
        default:
        printf("?");
        
    }
}
void main()
{
    char e[50];
    printf("\nEnter a postfix expression:");
    scanf("%s",e);
    evaluate(e);
}


