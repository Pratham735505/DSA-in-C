#include<stdio.h>
#include<stdlib.h>
#define max 5
//program to implement static queue
void insertion();
void deletion();
void display();
void ddisplay();
void ddeletion();
void dinsertion();
struct node {
    int no;
    struct node *next;
}
*start =NULL;
struct node *gfront=NULL;
struct node *grear=NULL;
struct node *next=NULL;
struct node *temp=NULL;
int q[max],front=-1,rear=-1,crear=-1,cfront=-1,c[max];
int de[max],dfront=-1,drear=-1;
void rdeletion();
void fdeletion();
void rinsertion();
void finsertion();
void deqdisplay();
void circdeletion();
void circdisplay();
void circinsertion();
// node and prototypes for priority queue
struct pnode{
int no;
int priority;
struct pnode *pnext;
}*pstart=NULL;
struct pnode *pfront=NULL;
struct pnode *prear=NULL;
struct pnode *h;
struct pnode *ptemp;
void pinsertion();
void pdeletion();
void pdisplay();
void main() {

    int i,p,r,s,t,u,v,w,x;
    do {
	printf("---------------Menu------------\n");
	printf("1.Simple queue\n2.Circular Queue \n3.Double Ended queue\n4.Priority queue\n5.Exit\n");
	scanf("%d",&p);
	switch(p) { // Simple queue
	case 1:
	    printf("1.Static queue\n2.Dyanamic queue\n3.Exit\n ");
	    scanf("%d",&r);

	    switch(r) { // Static simple queue
		do {
		case 1:
		    printf("\nStatic Simple queue\n");
		    printf("1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
		    scanf("%d",&w);
		    switch(w) {
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
			break;
		    default:
			printf("\nEnter valid choice:\n");
		    }
		} while(w!=4);
		break;

	    case 2:  //Simple Dynamic Queue
		do {
		    printf("\nStatic Dynamic queue\n");
		    printf("1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
		    scanf("%d",&x);
		    switch(x) {
		    case 1:
			dinsertion();
			break;
		    case 2:
			ddeletion();
			break;
		    case 3:
			ddisplay();
			break;
		    case 4:
			exit(0);
			break;
		    default:
			printf("\nEnter valid choice:\n");
		    }
		} while(x!=4);
		break;
	    case 3:
		exit(0);
	    default:
		printf("Enter valid choice");
	    }
	    break;


	case 2:
//Circular queue
	    do {
		printf("\nCircular queue\n");
		printf("1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
		scanf("%d",&t);
		switch(t) {
		case 1:
		    circinsertion();
		    break;
		case 2:
		    circdeletion();
		    break;
		case 3:
		    circdisplay();
		    break;
		case 4:
		    exit(0);
		default:
		    printf("\nEnter a right number\n");
		}
	    } while(t!=4);
	    break;
	case 3://Double ended queue
	    do {
		printf("1.Insertion from rear end\n2.Insertion from front end\n3.Deletion from front end\n4.Deletion from rear end\n5.Display\n6.Exit\n");
		scanf("%d",&u);
		switch(u) {
		case 1:
		    rinsertion();
		    break;
		case 2:
		    finsertion();
		    break;
		case 3:
		    fdeletion();
		    break;
		case 4:
		    rdeletion();
		    break;
		case 5:
		    deqdisplay();
		    break;
		case 6:
		    exit(0);
		default:
		    printf("\nEnter a right number\n");
		}
	    } while(u!=6);
	    break;
	case 4://Priority Queue
	do{
	printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
	scanf("%d",&v);
	    switch(v){
	    case 1:
	    pinsertion();
	    break;
	    case 2:
	    pdeletion();
	    break;
	    case 3:
	    pdisplay();
	    break;
	    case 4:
	    exit(0);
	    default:
	    printf("\nEnter valid choice\n");
	    }
	    }while(v!=4);
	    break;
	case 5:
	    exit(0);
	default:
	    printf("\nEnter a right number=");
	}
    } while(p!=5);


}

void insertion() {
    int g;
    if(rear==max-1) {
	printf("\nQueue Overflow\n");
    }
    else {
	printf("\nEnter number to be pushed=");
	scanf("%d",&g);
	if(front==-1) {
	    front=0;
	}
	rear++;
	q[rear]=g;
    }
}

void deletion() {
    if(rear==-1 && front==-1) {
	printf("\nUnderflow\n");
    }
    else
    {
	if(rear==front) {
	    printf("\nThe deleted element is=%d\n",q[front]);
	    rear=-1;
	    front=-1;
	}
	else {
	    printf("\nThe deleted element is=%d\n",q[front]);
	    front=front+1;
	}
    }
}
void display() {
    int i;
    if(rear==-1 && front==-1) {
	printf("\nQueue is empty\n");
    }
    else {
	for(i=front; i<=rear; i++) {
	    printf("%d\n",q[i]);
	}
    }
}
void dinsertion() {
    struct node *p,*temp;
    temp=start;
    p=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data=\n");
    scanf("%d",&p->no);
    if(start==NULL) {
	start=p;
    } else {
	while(temp->next!=NULL) {
	    temp=temp->next;

	}
	temp->next=p;
    }
}
void ddeletion() {
    int value;
    if(start==NULL) {
	printf("\nQueue Is empty\n");

    }
    else {
	temp=start;
	value=temp->no;
	start=start->next;
	gfront=start;
	free(temp);
    }
    printf("\n%d\n",value);
}
void ddisplay() {
    if(start==NULL) {
	printf("\nQueue is Empty\n");
    }
    else {


	struct node *temp;
	temp = start;
	while (temp != NULL)
	{
	    printf("\n%d", temp->no);
	    temp = temp->next;
	}
    }

}
void circinsertion() {
    int g;
    if(cfront==((crear+1)%max)) {
	printf("\nQueue Overflow\n");
    }
    else {
	printf("\nEnter number to be pushed=");
	scanf("%d",&g);
	if(cfront==-1) {
	    cfront=0;
	}
	crear=(crear+1)%max;
	c[crear]=g;
    }
}
void circdeletion() {
    if(crear==-1 && cfront==-1) {
	printf("\nQueue Underflow\n");
    }
    else {
	if (crear==cfront) {
	    printf("\nThe deleted element is=%d\n",c[cfront]);
	    crear=-1;
	    cfront=-1;
	}
	else {
	    printf("\nThe deleted element is=%d\n",c[cfront]);
	    cfront=(cfront+1)%max;
	}
    }
}
void circdisplay() {
    int i;
    if(crear==-1 && cfront==-1) {
	printf("\nQueue is empty\n");
    }
    else {
	printf("The elements of queue are:");
	for(i=cfront; i<=crear; i++) {
	    printf("\n%d\n",c[i]);
	}
    }
}

void rinsertion() {
    int g;
    if(drear==max-1) {
	printf("\nQueue Overflow\n");
    }
    else {
	printf("\nEnter number to be pushed=");
	scanf("%d",&g);
	if(dfront==-1) {
	    dfront=0;
	    drear=0;
	    drear++;
	de[drear]=g;
	}
	else{
	drear++;
	de[drear]=g;
	}
    }
}

void finsertion() {
    int g;
    if(dfront==0 || dfront==-1) {
	printf("\nQueue Overflow\n");
    }
    else {
	if(dfront==-1 && drear==-1) {
	    dfront=max;
	    drear=0;
	}
	printf("\nEnter the number to be inserted=");
	scanf("%d",&g);
	dfront=dfront-1;
	de[dfront]=g;
    }
}
void deqdisplay() {
    int i;
    if(drear==-1 && dfront==-1) {
	printf("\nQueue is empty\n");
    }
    else {
	for(i=dfront; i<=drear; i++) {
	    printf("%d\n",de[i]);
	}
    }
}

void fdeletion() {
    if(dfront==-1) {
	printf("\nUnderflow\n");
    }
    else
    {
	if(drear==dfront && dfront!=-1) {
	    printf("\nThe deleted element is=%d\n",q[front]);
	    drear=-1;
	    dfront=-1;
	}
	else {
	    printf("\nThe deleted element is=%d\n",q[front]);
	    dfront=dfront+1;
	}
    }
}
void rdeletion() {
    if(dfront==-1) {
	printf("\nUnderflow\n");
    }
    else {
	if (dfront==drear &&dfront!=-1) {
	    printf("\nThe element to be deleted is=%d\n",de[drear]);
	    dfront=-1;
	    drear=-1;
	}
	else {
	    printf("\nThe element to be deleted is=%d\n",de[drear]);
	    drear=drear-1;
	}
    }
}
void pinsertion(){
int i,g;
printf("\n1.Insertion at Beginning\n2.Insertion at the end\n3.Insertion in between\n");
printf("\nEnter your choice=");
scanf("%d",&i);
switch(i){
case 2:

    h=(struct pnode*)malloc(sizeof(struct pnode));
    printf("\nEnter the data=\n");
    scanf("%d",&h->no);
    printf("\nEnter the priority=\n");
    scanf("%d",&h->priority);

    if(pstart==NULL) {
	pstart=h;
    }
     else {
	while(ptemp->pnext!=NULL) {
	    ptemp=ptemp->pnext;

	}
	ptemp->pnext=h;
    }




break;
case 1:
  h=(struct pnode*)malloc(sizeof(struct pnode));
    printf("\nEnter the data=\n");
    scanf("%d",&h->no);
    printf("\nEnter the priority=\n");
    scanf("%d",&h->priority);

pstart=h;
h->pnext=pfront;
pfront=pstart;


break;
case 3:




break;
default:
printf("\nEnter valid choice\n");
}
}




void pdeletion(){
int i,g;
}


void pdisplay(){
int i,g;
if(pstart==NULL){
printf("Queue is Empty");
}
while(pstart!=NULL){
printf("\nValue=%d\n",pstart->no);
printf("\nPriority=%d\n",pstart->priority);
pstart=pstart->pnext;
}

}