
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
struct binary* minValueNode(struct binary* node);
struct binary* createnode(int val);
struct binary *insert(struct binary *root,int val);
void inorder(struct binary *root);
void preorder(struct binary *root);
void postorder(struct binary *root);
void search(struct binary *root,int num);
struct binary* deletion(struct binary *root,int num);
int main() {
    int choice,val,num;
    clrscr();
    fflush(stdin);
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
            if(root!=NULL)
                root=deletion(root,num);
            else
                printf("\nEmpty Binary Tree\n");
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





// Function to find the minimum value node in a given BST
struct binary* minValueNode(struct binary* node) {
    struct binary* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete the node with the given key from the BST
struct binary* deletion(struct binary* root, int key) {
    // Base case
    if (root == NULL) {printf("\nElement not in Binary tree\n");
    return root;}
    
    // If the key to be deleted is smaller than the root's key,
    // then it lies in the left subtree
    if (key < root->num)
        root->left = deletion(root->left, key);
    
    // If the key to be deleted is greater than the root's key,
    // then it lies in the right subtree
    else if (key > root->num)
        root->right = deletion(root->right, key);
    
    // If the key is same as root's key, then this is the node
    // to be deleted
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }
        
        // Node with two children: Get the inorder successor (smallest
        // in the right subtree)
         temp = minValueNode(root->right);
        
        // Copy the inorder successor's content to this node
        root->num = temp->num;
        
        // Delete the inorder successor
        root->right = deletion(root->right, temp->num);
    }
    return root;
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