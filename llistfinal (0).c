#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//Nodes and functions for simple linked list
struct node {
    int num;
    struct node *next;
}*start=NULL;
struct node *temp;
struct node *front=NULL;
struct node *rear;
struct node *q;
struct node *prev;
struct node *del;
struct node *d;
struct node *ran;
void insertion();
void deletion();
void display();
void search();
int count=0;





void main() {
    int i,j,k,l,m,n,o,p;
    clrscr();
    do{

    printf("\n\n\n\n\t\tLinked List Program\n\t\t-->©Pratham 722008\n\n\n");
    printf("\n1.Simple linked list\n2.Circular Linked List\n3.Doubly Linked list\n4.Circular doubly linked list\n5.Application\n6.Exit\n");
    scanf("%d",&i);
    fflush(stdin);
	switch(i) {
//Simple Linked List
	case 1:
	    do {
	    printf("\nEnter choice(1-5)\n");
		printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Search\n5.Exit\n");
		scanf("%d",&j);
		switch(j) {
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
		    search();
		    break;
		case 5:
		    exit(0);
		    break;
		default:
		    printf("\nWrong entry\n");
		}
	    } while(j!=4);
	    break;
	case 2:
	    //Circular linked list
	    do {
		printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
		scanf("%d",&k);
		switch(k) {
		case 1:
		    //  insertion();
		    break;
		case 2:
		    //  deletion();
		    break;
		case 3:
		    //  display();
		    break;
		case 4:
		    exit(0);
		default:
		    printf("\nWrong entry\n");
		}
	    } while(k!=4);
	    break;
	case 3:
	    //Doubly linked list
	    do {
		printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
		scanf("%d",&l);
		switch(l) {
		case 1:
		    //  insertion();
		    break;
		case 2:
		    //   deletion();
		    break;
		case 3:
		    // display();
		    break;
		case 4:
		    exit(0);
		    return;
		default:
		    printf("\nWrong entry\n");
		}
	    } while(l!=4);
	    break;

	case 4:
	    //Circular Doubly linked list
	    do {
		printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
		scanf("%d",&m);
		switch(m) {
		case 1:
		    // insertion();
		    break;
		case 2:
		    //  deletion();
		    break;
		case 3:
		    // display();
		    break;
		case 4:
		    exit(0);
		default:
		    printf("\nWrong entry\n");
		}
	    } while(m!=4);
	    break;
	case 5:
	    //Applications of linked list
	    break;
	case 6:
	    exit(0);
	default:
	    printf("\nEnter right choice\n");
	}
    } while(i!=5);

}



void insertion () {
  struct node *f;
    int z,k,i;
    ran=start;
    printf("\n1.Insertion at the end\n2.Insertion at the start\n3.Insertion at a specific place\n");
    scanf("%d",&z);

    switch(z) {
    case 1: //Insertion from end

	if(start==NULL) {     //For first element
	  f=(struct node*)malloc(sizeof(struct node));
	  printf ("\nFirst element\n");
	printf("\nEnter the value\n");
	scanf("%d",&f->num);
	    start=f;
	     q=start;
	    front=start;
	    count++;
	}
	else
	{
	  f=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the value\n");
	scanf("%d",&f->num);
	    q->next=f;
	    q=f;
	    count++;
	}



	break;
    case 2: //Insertion from start
    if(start==NULL) {   //FOR FIRST ELEMENT
	  f=(struct node*)malloc(sizeof(struct node));
	  printf ("\nFirst element\n");
	printf("\nEnter the value\n");
	scanf("%d",&f->num);
	    start=f;
	    q=start;
	    front=start;
	    count++;
	}
	else
	{
	  f=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the value\n");
	scanf("%d",&f->num);
	f->next=start;
	start=f;
	front=start;
	count++;
	}
	break;

    case 3: //Insertion in between
      printf("\nEnter at which position you want to insert\n");
      scanf("%d",&k);
      if(k==1){
	if(start==NULL) {
	  f=(struct node*)malloc(sizeof(struct node));
	  printf ("\nFirst element\n");
	printf("\nEnter the value\n");
	scanf("%d",&f->num);
	    start=f;
	    q=start;
	    front=start;
	    count++;
	    }
	else{
	f=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the value\n");
	scanf("%d",&f->num);
	f->next=start;
	start=f;
	front=start;
	count++;
	}
      }
      else if(k>count+1){
	printf ("\nThere are not enough elements\n");
      }
      else if(k==count+1){
	f=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the value\n");
	scanf("%d",&f->num);
	    q->next=f;
	    q=f;
	    count++;
      }
      else {


	f=(struct node*)malloc(sizeof(struct node));
	     printf("\nEnter the value\n");
	     scanf("%d",&f->num);
for(i=1;i<k;i++){
ran=ran->next;
}

f->next=ran->next;
ran->next=f;
start=front;
	count++;
      }




	break;
    default:
	printf("\nInvalid choice\nNow enter again\n");
    }
}







void deletion() {
    int z,n,o,k;
 del=start;
    start=front;
    if(start==NULL){
      printf ("\nLinked list in empty");
    }
    else{
    printf("\n1.Deletion at the end\n2.Deletion at the start\n3.Deletion at a specific place\n");
    scanf("%d",&z);
    switch(z) {
    case 1: //Deletion from end


	n=q->num;
	while(start->next!=q){
	  start = start->next;
	}
	start->next = q->next;
	printf("\nThe deleted element is %d\n",n);
	free(q);
	q=start;
	start=front;
	  if(count==1){
	  start=NULL;
	}

      count--;





	break;
    case 2: //Deletion from start
	 temp=start->next;
	 n=start->num;
	 printf("The deleted element is %d",n);
	 free(start);
	 start=temp;
      front=start;
	 if(count==1){
	  start=NULL;
	}
count--;


	break;
    case 3: //Deletion in between
	  printf("\nEnter which element you want to delete\n");
      scanf("%d",&k);
      if(k==1){
	temp=start->next;
	 n=start->num;
	 printf("The deleted element is %d",n);
	 free(start);
	 start=temp;
      front=start;
	 if(count==1){
	  start=NULL;
	}
count--;
      }
      else if(k==count){
	n=q->num;
	while(start->next!=q){
	  start = start->next;
	}
	start->next = q->next;
	printf("\nThe deleted element is %d\n",n);
	free(q);
	q=start;
	start=front;
	  if(count==1){
	  start=NULL;
	}

      count--;


      }
      else if(k>count){
	printf("\nThere is not any elements at %d position\n",k);
      }
      else{
	for(o=1;o<k;o++){
	  del=del->next;

	}
	d=del->next;
	n=d->num;
       printf("\nThe deleted element is %d\n",n);
      del->next=d->next;

	free(d);





    count--;
    }
	break;
    default:
	printf("\nInvalid choice\nNow enter again\n");
    }
    }
}


void display(){

   start=front;
    if(start==NULL)
       {
	printf("\nEmpty Linked List\n");
	}
    else
    {
      printf ("\nThe elements of Linked list are\n\n");
	 do{
	    printf("\t%d\t",start->num);
	    start=start->next;
	}while(start->next!=NULL);
	printf("\n");
	start=front;
    }
}
void search(){
int pos=0,sea;
if (start==NULL){
printf("\nLinked list is empty\n");
}
else
{
printf("\nEnter the element\n");
scanf("%d",&sea);

while (start->next!=NULL){
pos++;
if(start->num==sea){
printf("\n%d is found at %d position\n Its address is %u\n",sea,pos,start);
break;
}
start=start->next;
}
if (start->next==NULL){
printf("\n%d not found in linked list\n",sea);
}
}
start=front;
}