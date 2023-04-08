
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

int count=0;
int level=0;
int b=0;
struct binary* createnode(int val);
struct binary *insert(struct binary *root,int val);
void inorder(struct binary *root);
void preorder(struct binary *root);
void postorder(struct binary *root);
void search(struct binary *root,int num);
void deletion(struct binary *root,int num);
int main() {
    int choice,val,num;
    clrscr();
    printf("\n----------Welcome to my Binary Tree code--------\n");
    while (1) {
        printf("\n1.Insert\n2.Inorder Traversal\n3.Preorder Traversal\n4.Postorder Traversal\n5.Deletion\n6.Searching\n7.Exit\nEnter Choice:");
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
            printf("\nEnter number to be deleted:\n");
            scanf("%d",&num);
            deletion(root,num);
            if(b==0) {
                printf("\nElement not in Binary linked list\n");
            }
            break;
        case 6:
            printf("\nEnter which number to be searched:\n");
            scanf("%d",&num);
            search(root,num);
            break;

        case 7:
            exit(0);
        default:
            printf("\nInvalid Choice\n");

        }
    }
//  return 0;
}

void search(struct binary *root,int num) {
    if(root==NULL) {
        printf("\nRoot does not exist\n");
    }
    else if(root->num > num) {
        search(root->left,num);
    }
    else if(root->num<num) {
        search(root->right,num);
    }
    else if(root->num==num) {
        printf("%d found in Binary search tree\n");
    }
}

void deletion(struct binary *root,int num) {
    if(root==NULL) {
        printf("\nEmpty binary tree\n");
    }
    else if(root->num==num) {
        if(root->left==NULL && root->right==NULL) {
            free(root);
        }
        else if(root->left==NULL && root->right!=NULL) {
            if(temp->left==root) {
                temp->left=root->right;
            }
            else {
                temp->right=root->right;
            }
            free(root);
        }
        else if (root->right==NULL && root->left!=NULL) {
            if(temp->left==root)
                temp->left=root->left;
            else
                temp->right=root->left;
            free(root);
        }
        else if(root->left !=NULL && root->right!=NULL) {
            if(temp->left==root) {
                if(root->left!=NULL) {
                    if(root->left->right==NULL) {
                        temp->left=root->left;
                        free(root);
                    }
                    else {
                        temp->left=root->left->right;
                        free(root);
                    }
                }
                else if(root->right!=NULL) {
                    if(root->left!=NULL) {
                        if(root->right->left==NULL) {
                            temp->left=root->right;
                            free(root);
                        }
                        else {
                            temp->left=root->right->left;
                            free(root);
                        }
                    }
                    else {

                    }
                }
                b=1;
            }

            else {
                if(root->left!=NULL) {
                    temp=root;
                    deletion(root->left,num);
                }
                if(root->right!=NULL) {
                    temp=root;
                    deletion(root->right,num);
                }
            }
        }
    }
}
struct binary*createnode(int val)
{
    struct binary*newNode = (struct binary *)malloc(sizeof(struct binary));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->num = val;
    return newNode;
}

// inserting the node at appropriate place
struct binary* insert(struct binary *root, int val)
{
    if (root== NULL)
    {
        root= createnode(val);
    }
    else if (root->num > val)
    {
        root->left = insert(root->left, val);
    }
    else if (root->num< val)
    {
        root->right = insert(root->right, val);
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