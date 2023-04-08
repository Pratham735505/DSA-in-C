#include<stdio.h>
#include<conio.h>
//Nodes and functions for simple linked list
struct node{
int num;
struct node *next;
}*start=NULL;
void insertion();
void deletion();
void display();








void main(){
int i,j,k,l,m,n,o,p;
clrscr();
printf("\n1.Simple linked list\n2.Circular Linked List\n3.Doubly Linked list\n4.Circular doubly linked list\n5.Application\n6.Exit\n");
scanf("%d",&i);
do{
switch(i){
   case 1:
     printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
     scanf("%d",&j);
     switch(j){
	case 1:
	   insertion();
	   break;
	case 2:
	   deletion();
	   break;
	case 3:
	   display();
	   break;
	case 4:
	   exit(0);
	default:
     break;






















}while(i!=5);