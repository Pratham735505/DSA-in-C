#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct binary{
	 struct binary *left;
	 int num;
	 struct binary *parent;
	 struct binary *right;
}*root=NULL;
struct binary *front=NULL;
int count=0;
int level=0;

void insert();
void display();
int main(){
  int choice;
  clrscr();
  printf("\n----------Welcome to my Binary Tree code--------\n");
  while (1){
  printf("\n1.Insert\n2.Display\n3.Exit\nEnter Choice:");
  scanf("%d",&choice);
  switch(choice){
	case 1:
	  insert();
	  break;
	case 2:
	  display();
	  break;
	case 3:
	   exit(0);
	default:
	   printf("\nInvalid Choice\n");

  }
 }
//  return 0;
}


void insert(){
   struct binary *node;
   int choice;
   node=(struct binary*)malloc(sizeof(struct binary));
   node->left=NULL;
   node->right=NULL;
   printf("\nEnter a number:");
   scanf("%d",&node->num);
   if(front==NULL){
	 root=node;
	 front=node;
	 count++;
   }
   if(front->left!=NULL && front->right!=NULL){
	  if(front!=NULL){
		printf("\nEnter which side do you want to enter ?\n1.Left\n2.Right\nEnter Choice:");
		scanf("%d",&choice);
		switch(choice){
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

   else{
	   printf("\nEnter which side do you want to enter ?\n1.Left\n2.Right\nEnter Choice:");
	   scanf("%d",&choice);
	   switch(choice){
		  case 1:
			front->left=node;
			break;
		  case 2:
			front->right=node;
			break;
		  default:
			printf("\nInvalid Choice\n");
			break;
	   }
	   count++;
   }
}
void display(){
}