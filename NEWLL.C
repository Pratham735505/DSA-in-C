#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//Nodes and functions for simple linked list
struct node {
    struct node *prev;
    int num;
    struct node *next;
}*start=NULL;
struct node *front=NULL;
struct node *temp;
struct node *q;
 struct node *e;
struct node *d;
struct node *j;
struct node *k;
void insertion();
void deletion();
void display();
int count=0;


void bsort();
void isort();
void ssort();

void Lsearch();
void bisearch();


int main() {
    int i,j,k,l;
    clrscr();
    do{

    printf("\n\n\n\n\t\tLinked List Program\n\t\t-->©Pratham 722008\n\n\n");
    printf("\n1.Simple linked list\n2.Sorting\n3.Searching\n4.Exit\n");
    scanf("%d",&i);
   // fflush(stdin);
	switch(i) {
//Simple Linked List
	case 1:
	    do {
		printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
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
	      //      exit(0);
		    break;
		default:
		    printf("\nWrong entry\n");
		}
	    } while(j!=4);
	    break;
	case 2:
	do{
	    printf("\n1.Bubble Sort \n2.Insertion Sort\n3.Selection Sort\n4.Exit\nEnter Choice:");
	    scanf("%d",&k);
	    switch(k){
		case 1:
		bsort();
		break;
		case 2:
		isort();
		break;
		case 3:
	       ssort();
		break;
		case 4:
	   //     exit(0);
		default:
		printf("\nInvalid Choice\n");
	    }
	}while(k!=4);
	    break;
	case 3:
	do{
	printf("\n1.Linear Search\n2.Binary Search\n3.Exit\nEnter Choice:");
	scanf("%d",&l);
	switch(l)
	  {
	      case 1:
	      Lsearch();
	      break;
	      case 2:
	      bisearch();
	      break;
	      case 3:
	      exit(0);
	      default:
	      printf("\nInvalid Choice\n");
	  }
	}while(l!=3);
	  break;
	case 4:
	    exit(0);
	default:
	    printf("\nEnter right choice\n");
	}
    } while(i!=5);
    return 0;

}



void insertion () {
  struct node *f;
    int z,k,i;
  /* printf("\n1.Insertion at the end\n2.Insertion at the start\n3.Insertion at a specific place\n");
    scanf("%d",&z);*/

  /*  switch(z) {
    case 1: //Insertion from end*/

	if(start==NULL) {
	  f=(struct node*)malloc(sizeof(struct node));
	  printf ("\nFirst element\n");
	printf("\nEnter the value\n");
	scanf("%d",&f->num);
	    start=f;
	    q=start;
	    q->next=NULL;
	    count++;
	}
	else
	{
	  f=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the value\n");
	scanf("%d",&f->num);
	    q->next=f;
	    f->prev=q;
	    q=f;
	    q->next=NULL;
	    count++;
	}

}







void deletion() {
    int z,n,i,k;
    if(start==NULL){
      printf ("\nLinked list in empty");
    }
    else{
    /*printf("\n1.Deletion at the end\n2.Deletion at the start\n3.Deletion at a specific place\n");
    scanf("%d",&z);
    switch(z) {
    case 1: */ //Deletion from end


	n=q->num;
	printf("\nThe deleted element is %d\n",n);
	 free(q);
	  if(count==1){
	  start=NULL;
	}

      count--;





	/*break;
    case 2: //Deletion from start
	 temp=start->next;
	 n=start->num;
	 printf("The deleted element is %d",n);
	 free(start);
	 start=temp;
	 if(count==1){
	  start=NULL;
	}
count--;


	break;
    case 3: //Deletion in between
	  printf("\nEnter at which position you want to insert\n");
      scanf("%d",&k);





	break;
    default:
	printf("\nInvalid choice\nNow enter again\n");
    }*/
    }
}


void display(){
   front=start;
    if(start==NULL)
{
	printf("\nEmpty Linked List\n");
	}
    else
    {
      printf ("\nThe elements of Linked list are\n");
	 do{
	    printf("\t%d\t",start->num);
	    start=start->next;
	}while(start!=NULL);
    }
    start=front;
}


void ssort(){
    int e;

	for(j=start;j!=NULL;j=j->next){
	    for(k=j;k!=NULL;k=k->next){
		if(j->num > k->num){
		    e=j->num;
		    j->num=k->num;
		    k->num=e;
		}

	    }

	}
	display();
    }




void bsort(){
    int l,n=0,i,j;
   struct node *t;
 for(i=0;i<count;i++){
     t=start;
     e=start->next;
     for(j=0;j<count-1-i;j++){
	  if(t->num > e->num){
		l=t->num;
		t->num=e->num;
		e->num=l;
     }
     e=e->next;
     t=t->next;

 }
 }
  /*  for(e=start;e!=NULL;e=e->next){
	for(temp=start;temp!=NULL;temp=temp->next){
	    t=temp->next;
	    if(temp->num > t->num){
		l=temp->num;
		temp->num=t->num;
		t->num=l;
	    }
	}
    }*/
    front=start;
    display();
    }


void isort(){
      //insertionsorting----------------------------->>>>>> 
 struct node *i;
 int key;
 for(i=front->next;i!=NULL;i=i->next)
 {
 key=i->num;
 j=i->prev;
 while(j!=NULL&&j->num>key)
 {
 j->next->num=j->num;
 j=j->prev;
}

if(j==NULL)
{
 front->num=key;
 }

 else
{
 j->next->num=key;
}
 }
 display();

}
void Lsearch() {
    int pos=0,sea;
    if (start==NULL) {
	printf("\nLinked list is empty\n");
    }
    else
    {
	printf("\nEnter the element\n");
	scanf("%d",&sea);

	while (start->next!=NULL) {
	    pos++;
	    if(start->num==sea) {
		printf("\n%d is found at %d position\n Its address is %u\n",sea,pos,start);
		break;
	    }
	    start=start->next;
	}
	if (start->next==NULL) {
	    printf("\n%d not found in linked list\n",sea);
	}
    }
    start=front;
}
//------------------------------------------------------------------------------------------------
void bisearch(){
    struct node *n;
    int low,up,l,g=0,mid,s=0,c=0,e;
    n=start;
    up=count-1;
    low=0;
    l=(count)/2;
//    bsort();
    printf("\nEnter the element to be found\n");
    scanf("%d",&e);
    while(g!=l){
	mid=(low+up)/2;
	while(s!=mid+1){
	    n=n->next;
	    s++;
	}
	s=0;
	if(n->num==e){
	    printf("%d is found at %d",e,mid);
	    c=1;
	    break;
	}
	else if(n->num  > e){
	    up=mid;
	    n=start;
	}
	else{
	    low=mid;
	}
	g++;
    }
    if(c==0){
	printf("\nElement not found\n");
    }
}