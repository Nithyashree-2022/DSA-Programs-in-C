# include <stdio.h>
# include <stdlib.h>

struct block
{
    int data;
    struct block *left,*right;
}*root=NULL;

void insert(int ele);
void find(int ele,struct block **par,struct block **loc);
void delete_node(int ele);
void delete_leaf_node(struct block *par,struct block *loc);
void delete_child_node_ltorrt(struct block *par,struct block *loc);
void delete_child_node(struct block *par,struct block *loc);
void inorder(struct block*);
void preorder(struct block*);
void postorder(struct block*);

void main()
{
    int ch,status=1,ele;
    while(status==1)
    {
        printf("\n1.Insert,2.Delete,3.Inorder,4.Preorder,5.Postorder,6.EXIT");
        scanf("\n%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("\nEnter ele:");
                scanf("%d",&ele);
                insert(ele);
                break;
                
            }
            case 2:
            {
                printf("\nEnter ele:");
                scanf("%d",&ele);
                delete_node(ele);
                break;
            }
            case 3:
            {
                if(root==NULL)
                {
                    printf("\nTree is empty");
                }
                else
                {
                    printf("\nInorder traversal:");
                    inorder(root);
                }
                break;
            }
            case 4:
            {
                if(root==NULL)
                {
                    printf("\nTree is empty");
                }
                else
                {
                    printf("\nPreorder traversal:");
                    preorder(root);
                }
                break;
                
            }
            case 5:
            {
                if(root==NULL)
                {
                    printf("\nTree is empty");
                }
                else
                {
                    printf("\nPostorder traversal:");
                    postorder(root);
                }
                break;
            }
            case 6:
            {
                status=0;
                break;
            }
            default:
            printf("\nSry,invalid choice!");
        }
    }
}

void insert(int ele)
{
    struct block *par,*loc;
    find(ele,&par,&loc);
    if(loc!=NULL)
    {
        printf("\n%d already present",ele);
        return;
    }
    struct block *temp=(struct block*)malloc(sizeof(struct block*));
    temp->data=ele;
    temp->left=NULL;
    temp->right=NULL;
    if(par==NULL)
    {
        root=temp;
        printf("\n%d successfully inserted to BST",root->data);
        return;
    }
    else
    {
        if(ele<par->data)
            par->left=temp;
        else
            par->right=temp;
    }
    printf("\n%d successfully inserted to BST",ele);
}

void find(int ele,struct block **par,struct block **loc)
{
    struct block *i,*i_s_par;
    if(root==NULL)
    {
        *par=NULL;
        *loc=NULL;
        return;
    }
    if(root->data==ele)
    {
        *loc=root;
        *par=NULL;
        return;
    }
    if(ele<root->data)
        i=root->left;
    else
        i=root->right;
    i_s_par=root;
    while(i!=NULL)
    {
        if(i->data==ele)
        {
            *loc=i;
            *par=i_s_par;
            return;
        }
        i_s_par=i;
        if(ele>i->data)
            i=i->right;
        else
            i=i->left;
    }
    *loc=NULL;
    *par=i_s_par;
}

void delete_node(int ele)
{
    struct block *par,*loc;
    struct block *temp=(struct block*)malloc(sizeof(struct block*));
    if(root==NULL)
    {
        printf("\nEmpty tree:");
        return;
    }
    find(ele,&par,&loc);
    if(loc==NULL)
    {
        printf("\n%d not in bst",ele);
        return;
    }
    if(loc->left==NULL && loc->right==NULL)
    {
        delete_leaf_node(par,loc);
    }
    else if((loc->left!=NULL && loc->right==NULL)|| (loc->left==NULL && loc->right!=NULL))
    {
        delete_child_node_ltorrt(par,loc);
    }
    else
    {
        delete_child_node(par,loc);
    }
    temp->data=loc->data;
    free(loc);
    printf("\n%d deleted from BST",temp->data);
}

void delete_leaf_node(struct block *par,struct block *loc)
{
    if(par==NULL)
    {
        root=NULL;
        return;
    }
    else
    {
        if(par->left==loc)
            par->left=NULL;
        else
            par->right=NULL;
    }
}

void delete_child_node_ltorrt(struct block *par,struct block *loc)
{
    struct block *temp;
    if(loc->left!=NULL)
        temp=loc->left;
    else
        temp=loc->right;
    if(par==NULL)
        root=temp;
    else
    {
        if(par->left==loc)
            par->left=temp;
        else
            par->right=temp;
    }
}

void delete_child_node(struct block *par,struct block *loc)
{
    struct block *i,*i_s_par,*parsuc,*suc;
    i=loc->right;
    i_s_par=loc;
    while(i->left!=NULL)
    {
        i_s_par=i;
        i=i->left;
    }
    suc=i;
    parsuc=i_s_par;
    if(suc->left==NULL && suc->right==NULL)
        delete_leaf_node(parsuc,suc);
    else
        delete_child_node_ltorrt(parsuc,suc);
    if(par==NULL)
        root=suc;
    else
    {
        if(par->left==loc)
            par->left=suc;
        else
            par->right=suc;
        
    }
    suc->left=loc->left;
    suc->right=loc->right;
}

void inorder(struct block *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("\n%d",root->data);
    inorder(root->right);
}

void preorder(struct block *root)
{
    if(root==NULL)
        return;
    printf("\n%d",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct block *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("\n%d",root->data);
}
