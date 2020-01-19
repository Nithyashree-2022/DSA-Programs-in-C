# include <stdio.h>

# include <stdlib.h>

char stack[50];
int top=-1;


struct result
{
    char token;
    struct result *chain;
}*start=NULL,*last=NULL;


int isoperator(char);
int isoperand(char);
void pop2();
void appendtoresult(char);
void push(char);
char pop();
void answer();
void infixtopostfix();
void precedence(char);




int main()
{
    char expression[50];
    printf("\nEnter infix expression:");
    scanf("\n%s",expression);
    infixtopostfix(expression);
    return 0;
}
void pop2()
{
    
    top--;
    
}



void infixtopostfix(char e[50])
{
    
    int i=0;
    
    
    while(e[i]!='\0')
    {
        if(isoperand(e[i])==1)
        {
            appendtoresult(e[i]);
        }
        else if(isoperator(e[i])==1)
        {
            if(top==-1 || stack[top]=='(')
            {
                push(e[i]);
            }
            else
            {
                precedence(e[i]);
            }
        }
        else 
        {
           if(e[i]=='(')
           {
               //printf("\n1");
               push(e[i]);
           }
           else 
           {
                if(e[i]==')')
                {
                    //printf("\n2");
                    while(stack[top]!='(')
                    {
            
                        appendtoresult(pop());
                        
                    }
                    pop2();
                }
           }
           
        
        }
        i++;
    }
       
    i=top;
    while(i!=-1)
    {
        
        appendtoresult(pop());
        i--;
    }
    
    answer();
}

int isoperand(char ch)
{
    if((ch>='a'&& ch<='z')||(ch>='A'&& ch<='Z')||(ch>='0'&& ch<='9'))
        return 1;
    else
        return 0;
}
int isoperator(char ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
        return 1;
    else
        return 0;
}
void appendtoresult(char ch)
{
    struct result *temp=(struct result*)malloc(sizeof(struct result));
    temp->token=ch;
    temp->chain=NULL;
    if(start==NULL)
    {
        start=temp;
        last=temp;
        
    }
    else
    {
        last->chain=temp;
        last=temp;
    }
}

void push(char ch)
{
    top++;
    stack[top]=ch;
}
char pop()
{
    int i=top;
    if(top!=-1)
    {
        top--;
        return(stack[i]);
    }
}
void answer()
{
    printf("\nPostfix expression:");
    struct result *i=start;
    while(i!=NULL)
    {
        printf("%c",i->token);
        i=i->chain;
    }
}

void precedence(char ch)
{
    int i=top;
    char ele;
    switch(ch)
    {
        case '^':
        {
            push(ch);
            break;
        }
        case '*':
        case '/':
        {
            if(stack[top]=='+'||stack[top]=='-')
            {
                push(ch);
                
            }
            else
            {
                while(stack[i]=='^'||stack[i]=='/'||stack[i]=='*')
                {
                    
                    appendtoresult(pop());
                    i--;
                }
                push(ch);
            }
            break;
        }
        case '+':
        case '-':
        {
           
            while(stack[i]=='^'||stack[i]=='/'||stack[i]=='*'||stack[i]=='+'||stack[i]=='-')
            {
                
                appendtoresult(pop());
                i--;
                
            }
            push(ch);
            break;
        }
        default:printf("-------");
    }
}

