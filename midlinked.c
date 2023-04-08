#include<stdio.h>
#include <conio.h>
struct c{
	int num;
	struct c *next;
}*start=NULL;
struct c *q;
struct c *p;
struct c *front;
int count=0;
void insert();
void search();


int main(){
	int a;
	do{
	printf("\n------------------------Menu-----------------------\n");
	printf("\n1.Insert\n2.Display\n3.Exit\n");
	printf("\nEnter Choice:");
	scanf("%d",&a);
	switch(a){
		case 1:
			insert();
			break;
		case 2:
			search();
			break;
		case 3:
			exit(0);
		default:
			printf("Invalid Choice");	
	}
	}while(a!=3);
	return 0;
}

void insert(){
	p=(struct c*)malloc(sizeof(struct c));
	printf("\nEnter the element\n");
	scanf("%d",&p->num);
	if (start==NULL){
		start=p;
		start->next=p;
        q=start;
		front=start;
		
		count++;
	}
	else{
		q->next=p;
		q=p;
		q->next=start;
		count++;
	}
}

void search(){
	int j,k=0;
	j=count/2;
	if(start==NULL){
		printf("\nEmpty linked list\n");
	}
	else{
		while(front->next!=NULL){
			if(j==k){
				printf("\nThe middle element is=%d\n",front->num);
				break;
			}
			k++;
			front=front->next;
		}
		front=start;
		}
	}


