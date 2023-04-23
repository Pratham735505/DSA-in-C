
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct binary {
    struct binary *left;
    int num;
    struct binary *parent;
    struct binary *right;
}*root=NULL;
struct binary *front=NULL;
 struct binary *node;
int count=0;
int level=0;

struct binary* insert(struct binary *front);
void inorder(struct binary *front);
void preorder(struct binary *front);
void postorder(struct binary *front);
int main() {
    int choice;
    clrscr();
    printf("\n----------Welcome to my Binary Tree code--------\n");
    while (1) {
        printf("\n1.Insert\n2.Inorder Traversal\n3.Preorder Traversal\n4.Postorder Traversal\n5.Exit\nEnter Choice:");
        scanf("%d",&choice);
        switch(choice) {
        case 1:
      insert(front);
	    count++;
	    break;
	case 2:
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


/*void insert(struct binary *front) {
    struct binary *node;
    int choice;
    node=(struct binary*)malloc(sizeof(struct binary));
    node->left=NULL;
    node->right=NULL;
    printf("\nEnter a number:");
    scanf("%d",&node->num);
    if(front==NULL) {
	root=node;
	front=node;
	count++;
	level++;
    }
    else if(front->left!=NULL && front->right!=NULL) {
	if(front!=NULL) {
	    printf("\nEnter which side do you want to enter ?\n1.Left\n2.Right\nEnter Choice:");
	    scanf("%d",&choice);
	    switch(choice) {
	    case 1:
		front=front->left;
		break;
	    case 2:
		front=front->right;
		break;
	    default:
		printf("\nInvalid Choice\n");

	    }
	}
    }

    else {
	printf("\nEnter which side do you want to enter ?\n1.Left\n2.Right\nEnter Choice:");
	scanf("%d",&choice);
	switch(choice) {
	case 1:
	    front->left=node;
	    root=front;
	    break;
	case 2:
	    front->right=node;
	    root=front;
	    break;
	default:
	    printf("\nInvalid Choice\n");
	}
    }
}*/

struct binary* insert(struct binary *front) {

      if(front==NULL) {
       //	root=node;
	node=(struct binary*)malloc(sizeof(struct binary));
       node->left=NULL;
       node->right=NULL;
    printf("\nEnter a number:");
    scanf("%d",&node->num);

	front=node;
//	return front;
       //	level++;
    }
   else {
   /* if(front==NULL){
       front=node;
   }
    else if(front->left ==NULL){
	insert(front->left);
    }
    else if(front->right==NULL){
	insert(front->right);
    }*/

    front->left= insert(front->left);
    front->right= insert(front->right);
     }

}

void inorder(struct binary* front) {
     if(front==NULL){
	 printf("\nEmpty Binary Tree\n");
     }
     else{
     if(front->left!=NULL)
     inorder(front->left);
     printf("\n%d\n",front->num);
	if(front->right!=NULL)
     inorder(front->right);
     }
}


void preorder(struct binary* root) {
      if(root==NULL){
         printf("\nEmpty Binary Tree\n");
     }
     else{
      printf("\n%d\n",root->num);
     if(root->left!=NULL)
     preorder(root->left);
        if(root->right!=NULL)
     preorder(root->right);
     }
}

void postorder(struct binary* root) {
     if(root==NULL){
         printf("\nEmpty Binary Tree\n");
     }
     else{
         if(root->left!=NULL)
           postorder(root->left);
         if(root->right!=NULL)
           postorder(root->right);
         printf("\n%d\n",root->num);
     }
}