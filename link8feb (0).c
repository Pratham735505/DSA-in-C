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
//void deletion();
void display();
void search();
void dele();
int count=0;

//functions and variables for circular deletion
struct cnode {
    int num;
    struct node *next;
}*cstart=NULL;
struct cnode *clast;
struct cnode *cfront=NULL;
struct cnode *cran;
struct cnode *ctemp;
struct cnode *cdel;

void cdeletion();
void cinsertion();
void cdisplay();
void csearch();
void cdele();
int ccount=0;


void main() {
    int i,j,k,l,m,n,o,p;
    clrscr();
    do {

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
                    dele();
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
                printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Search\n5.Exit\n");
                scanf("%d",&k);
                switch(k) {
                case 1:
                    cinsertion();
                    break;
                case 2:
                    cdeletion();
                    break;
                case 3:
                    cdisplay();
                    break;
                case 4:
                    csearch();
                    break;
                case 5:
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

//---------------------------------------------------------------------------------------------------------------------

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
            f->next=NULL;
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
        if(k==1) {
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
            else {
                f=(struct node*)malloc(sizeof(struct node));
                printf("\nEnter the value\n");
                scanf("%d",&f->num);
                f->next=start;
                start=f;
                front=start;
                count++;
            }
        }
        else if(k>count+1) {
            printf ("\nThere are not enough elements\n");
        }
        else if(k==count+1) {
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
            for(i=1; i<k; i++) {
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





//---------------------------------------------------------------------------------------------------------------------------

/*void deletion() {
    int z,n,o,k;
 del=start;
    start=front;
    if(start==NULL){
      printf ("\nLinked list in empty");
    }
    else{
    printf("\n1.Deletion at the end\n2.Deletion at the start\n3.Deletion at a specific place\n4.Deletion of a specific element\n");
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
    case 4:
    dele();
    break;
    default:
    printf("\nInvalid choice\nNow enter again\n");
    }
    }
}*/

//----------------------------------------------------------------------------------------
void display() {

    start=front;
    if(start==NULL)
    {
        printf("\nEmpty Linked List\n");
    }
    else
    {
        printf ("\nThe elements of Linked list are\n\n");
        for(start; start!=NULL; start=start->next) {
            printf("\t%d\t",start->num);
            // start=start->next;
        }
        printf("\n");
        start=front;
    }
}
//----------------------------------------------------------------------------------
void search() {
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
void dele() {
    struct node *v,*x;
    int w;
    if (start==NULL) {
        printf("\nLinked list is empty\n");
    }
    else {
        printf("\nEnter element to be deleted:\n");
        scanf("%d",&w);
        if (start->num==w) { //for first element
            v=start;
            start=start->next;
            free(v);

            if(count==1)
                start=NULL;
            count--;
            front=start;


        }

        else if(q->num==w) {
            while(start->next!=q) {
                start = start->next;
            }
            start->next = q->next;
            printf("\nThe deleted element is %d\n",q->num);
            free(q);
            q=start;
            start=front;
            if(count==1) {
                start=NULL;
            }

            count--;
        }
        else {
            x=start;
            while (x->next->next!=NULL) {    //for second element

                if(x->next->num==w)
                {
                    v=x->next;
                    x->next=v->next;
                    free(v);
                    v=NULL;
                    count--;
                    break;
                }
                x=x->next;
            }
            if (v!=NULL) {
                printf("\n%d element not found in the link list\n",w);
            }
            front=start;
        }
    }
}

//_-----------------------------------------------

//functions for circular linked list
void cinsertion () {
    struct cnode *f;
    int z,k,i;
    cran=cstart;
    printf("\n1.Insertion at the end\n2.Insertion at the start\n3.Insertion at a specific place\n");
    scanf("%d",&z);

    switch(z) {
    case 1: //Insertion from end

        if(cstart==NULL) {     //For first element
            f=(struct cnode*)malloc(sizeof(struct cnode));
            printf ("\nFirst element\n");
            printf("\nEnter the value\n");
            scanf("%d",&f->num);
            cstart=f;
            clast=cstart;
            cfront=cstart;
            clast->next=cstart;
            ccount++;
        }
        else
        {
            f=(struct cnode*)malloc(sizeof(struct cnode));
            printf("\nEnter the value\n");
            scanf("%d",&f->num);
            f->next=NULL;
            clast->next=f;
            clast=f;
            clast->next=cstart;
            ccount++;
        }



        break;
    case 2: //Insertion from start
        if(cstart==NULL) {   //FOR FIRST ELEMENT
            f=(struct cnode*)malloc(sizeof(struct cnode));
            printf ("\nFirst element\n");
            printf("\nEnter the value\n");
            scanf("%d",&f->num);
            cstart=f;
            clast=cstart;
            cfront=cstart;
            clast->next=cstart;
            ccount++;
        }
        else
        {
            f=(struct cnode*)malloc(sizeof(struct cnode));
            printf("\nEnter the value\n");
            scanf("%d",&f->num);
            f->next=cstart;
            cstart=f;
            cfront=cstart;
            clast->next=cstart;
            ccount++;
        }
        break;

    case 3: //Insertion in between
        printf("\nEnter at which position you want to insert\n");
        scanf("%d",&k);
        if(k==1) {
            if(cstart==NULL) {
                f=(struct cnode*)malloc(sizeof(struct cnode));
                printf ("\nFirst element\n");
                printf("\nEnter the value\n");
                scanf("%d",&f->num);
                cstart=f;
                clast=cstart;
                cfront=cstart;
                clast->next=cstart;
                ccount++;
            }
            else {
                f=(struct cnode*)malloc(sizeof(struct cnode));
                printf("\nEnter the value\n");
                scanf("%d",&f->num);
                f->next=cstart;
                cstart=f;
                cfront=cstart;
                clast->next=cstart;
                ccount++;
            }
        }
        else if(k>ccount+1) {
            printf ("\nThere are not enough elements\n");
        }
        else if(k==ccount+1) {
            f=(struct cnode*)malloc(sizeof(struct cnode));
            printf("\nEnter the value\n");
            scanf("%d",&f->num);
            clast->next=f;
            clast=f;
            clast->next=cstart;
            ccount++;
        }
        else {


            f=(struct cnode*)malloc(sizeof(struct cnode));
            printf("\nEnter the value\n");
            scanf("%d",&f->num);
            for(i=1; i<k; i++) {
                cran=cran->next;
            }

            f->next=cran->next;
            cran->next=f;
            cstart=cfront;
            ccount++;
        }




        break;
    default:
        printf("\nInvalid choice\nNow enter again\n");
    }
}





//---------------------------------------------------------------------------------------------------------------------------

void cdeletion() {
    int z,n,o,k;
    cdel=cstart;
    cstart=cfront;
    if(cstart==NULL) {
        printf ("\nLinked list in empty");
    }
    else {
        printf("\n1.Deletion at the end\n2.Deletion at the start\n3.Deletion at a specific place\n4.Deletion of a specific element\n");
        scanf("%d",&z);
        switch(z) {
        case 1: //Deletion from end


            n=clast->num;
            while(cstart->next!=clast) {
                cstart = cstart->next;
            }
            cstart->next = clast->next;
            printf("\nThe deleted element is %d\n",n);
            free(clast);
            clast=cstart;
            clast->next=cfront;
            cstart=cfront;
            if(ccount==1) {
                cstart=NULL;
            }

            ccount--;





            break;
        case 2: //Deletion from start
            ctemp=cstart->next;
            n=cstart->num;
            printf("The deleted element is %d",n);
            free(cstart);
            cstart=ctemp;
            cfront=cstart;
            clast->next=cstart;
            if(ccount==1) {
                cstart=NULL;
            }
            ccount--;


            break;
        case 3: //Deletion in between
            printf("\nEnter which element you want to delete\n");
            scanf("%d",&k);
            if(k==1) {
                ctemp=cstart->next;
                n=cstart->num;
                printf("The deleted element is %d",n);
                free(cstart);
                cstart=ctemp;
                cfront=cstart;
                if(ccount==1) {
                    cstart=NULL;
                }
                clast->next=cstart;
                ccount--;
            }
            else if(k==ccount) {
                n=clast->num;
                while(cstart->next!=q) {
                    cstart = cstart->next;
                }
                cstart->next = clast->next;
                printf("\nThe deleted element is %d\n",n);
                free(clast);
                clast=cstart;
                cstart=cfront;
                clast->next=cstart;
                if(ccount==1) {
                    cstart=NULL;
                }

                ccount--;


            }
            else if(k>ccount) {
                printf("\nThere is not any elements at %d position\n",k);
            }
            else {
                for(o=1; o<k; o++) {
                    cdel=cdel->next;

                }
                d=cdel->next;
                n=d->num;
                printf("\nThe deleted element is %d\n",n);
                cdel->next=d->next;

                free(d);
                ccount--;
            }
            break;
        case 4:
            cdele();
            break;
        default:
            printf("\nInvalid choice\nNow enter again\n");
        }
    }
}

//----------------------------------------------------------------------------------------
void cdisplay() {

    cstart=cfront;
    if(cstart==NULL)
    {
        printf("\nEmpty Linked List\n");
    }
    else
    {
        printf ("\nThe elements of Linked list are\n\n");
        for(cstart; cstart!=NULL; cstart=cstart->next) {
        
            printf("\t%d\t",cstart->num);
            if(cstart->next==cfront)
            break;
        
        }
        printf("\n");
        cstart=cfront;
    }
}
//----------------------------------------------------------------------------------
void csearch() {
    int pos=0,sea;
    if (cstart==NULL) {
        printf("\nLinked list is empty\n");
    }
    else
    {
        printf("\nEnter the element\n");
        scanf("%d",&sea);

        while (cstart->next!=cfront) {
            pos++;
            if(cstart->num==sea) {
                printf("\n%d is found at %d position\n Its address is %u\n",sea,pos,cstart);
                break;
            }
            cstart=cstart->next;
        }
        if (cstart->next==cfront) {
            printf("\n%d not found in linked list\n",sea);
        }
    }
    cstart=cfront;
}
//------------------------------------------------------------------------------------------------
void cdele() {
    struct cnode *v,*x;
    int w;
    if (cstart==NULL) {
        printf("\nLinked list is empty\n");
    }
    else {
        printf("\nEnter element to be deleted:\n");
        scanf("%d",&w);
        if (cstart->num==w) { //for first element
            v=cstart;
            cstart=cstart->next;
            free(v);
            

            if(ccount==1)
                cstart=NULL;
            ccount--;
            cfront=cstart;
            clast->next=cstart;


        }

        else if(clast->num==w) {
            while(cstart->next!=clast) {
                cstart = cstart->next;
            }
            cstart->next = clast->next;
            printf("\nThe deleted element is %d\n",q->num);
            free(clast);
            clast=cstart;
            cstart=cfront;
            if(ccount==1) {
                cstart=NULL;
            } 
            clast->next=cstart;
  
            ccount--;
        }
        else {
            x=cstart;
            while (x->next->next!=cfront) {    //for second element

                if(x->next->num==w)
                {
                    v=x->next;
                    x->next=v->next;
                    free(v);
                    v=NULL;
                    ccount--;
                    break;
                }
                x=x->next;
            }
            if (v!=NULL) {
                printf("\n%d element not found in the link list\n",w);
            }
            cfront=cstart;
        }
    }
}