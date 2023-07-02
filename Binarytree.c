#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct binary {
    struct binary *left;
    int num;
//    struct binary *parent;
    struct binary *right;
}*root=NULL;
struct binary *front=NULL;
struct binary *temp=NULL;
struct binary *temp2=NULL;
int count=0;
int level=0;
int b=0;
struct binary* createnode(int val);
struct binary *insert(struct binary *root,int val);
void inorder(struct binary *root);
void preorder(struct binary *root);
void postorder(struct binary *root);


int main() {
    int choice,val,num;
    clrscr();
    fflush(stdin);
    printf("\n----------Welcome to my Binary Tree code--------\n");
    while (1) {
        printf("\n1.Insert\n2.Inorder Traversal\n3.Preorder Traversal\n4.Postorder Traversal\n5.Exit\nEnter Choice:");
        scanf("%d",&choice);
        switch(choice) {
        case 1:
            printf("\nEnter value:");
            scanf("%d",&val);
            if (root == NULL)
            {
                root =createnode(val);
            }
            else
            {
                root = insert(root, val);
            }
            count++;
            break;
        case 2:
//      printf("%d",front->num);
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid Choice\n");

        }
    }
//  return 0;
}


struct binary*createnode(int val)
{
    struct binary*newNode = (struct binary *)malloc(sizeof(struct binary));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->num = val;
    return newNode;
}


struct binary* insert(struct binary* root,int val) {
    int e;
    if(root==NULL) {
        return createnode(val);
    }
    else {
       // do {
            printf("\nEnter which side\n1.Left\n2.Right\nEnter choice:");
            scanf("%d",&e);
            switch(e) {
            case 1:
                root->left=insert(root->left,val);
                break;
            case 2:
                root->right=insert(root->right,val);
                break;
            default:
                printf("\nWrong choice\n");
            }
       // }while(e>2);
    }
    return root;
}


void inorder(struct binary* root) {
    if(root==NULL) {
        printf("\nEmpty Binary Tree\n");
    }
    else {
        if(root->left!=NULL)
            inorder(root->left);
        printf("\n%d\n",root->num);
        if(root->right!=NULL)
            inorder(root->right);
    }
}


void preorder(struct binary* root) {
    if(root==NULL) {
        printf("\nEmpty Binary Tree\n");
    }
    else {
        printf("\n%d\n",root->num);
        if(root->left!=NULL)
            preorder(root->left);
        if(root->right!=NULL)
            preorder(root->right);
    }
}

void postorder(struct binary* root) {
    if(root==NULL) {
        printf("\nEmpty Binary Tree\n");
    }
    else {
        if(root->left!=NULL)
            postorder(root->left);
        if(root->right!=NULL)
            postorder(root->right);
        printf("\n%d\n",root->num);
    }
}
