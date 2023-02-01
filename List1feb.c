#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//Nodes and functions for simple linked list
struct node {
    int num;
    struct node *next;
}*start=NULL;
struct node *temp;
struct node *q;
struct node *prev;
struct node *d;
void insertion();
void deletion();
void display();
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
    printf("\n1.Insertion at the end\n2.Insertion at the start\n3.Insertion at a specific place\n");
    scanf("%d",&z);
    
    switch(z) {
    case 1: //Insertion from end
        
        if(start==NULL) {
          f=(struct node*)malloc(sizeof(struct node));
          printf ("\nFirst element\n");
        printf("\nEnter the value\n");
        scanf("%d",&f->num);
            start=f;
            q=start;
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
    if(start==NULL) {
          f=(struct node*)malloc(sizeof(struct node));
          printf ("\nFirst element\n");
        printf("\nEnter the value\n");
        scanf("%d",&f->num);
            start=f;
            q=start;
            count++;
        }
        else
        {
          f=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the value\n");
        scanf("%d",&f->num);
        f->next=start;
        start=f;
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
            count++;
            }
        else{
        f=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the value\n");
        scanf("%d",&f->num);
        f->next=start;
        start=f;
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
         for(i=1;i<k;i++){
           start=start->next;
           if(i=k-1){
             d=start;
             break;
           }
         }
        f=(struct node*)malloc(sizeof(struct node));
             printf("\nEnter the value\n");
             scanf("%d",&f->num);
             f->next=d->next;
             d->next=f;
        count++;
      }




        break;
    default:
        printf("\nInvalid choice\nNow enter again\n");
    }
}







void deletion() {
    int z,n,i,k;
    if(start==NULL){
      printf ("\nLinked list in empty");
    }
    else{
    printf("\n1.Deletion at the end\n2.Deletion at the start\n3.Deletion at a specific place\n");
    scanf("%d",&z);
    switch(z) {
    case 1: //Deletion from end
       
         
        n=q->num;
        printf("\nThe deleted element is %d\n",n);
         free(q);
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
    }
    }
}


void display(){
    //struct node *temp,*a;
   // temp=start;
    if(start==NULL)
{
        printf("\nEmpty Linked List\n");
        }
    else
    {
      printf ("\nThe elements of Linked list are\n");
         do{
            printf("\n%d\n",start->num);
            start=start->next;
        }while(start!=NULL);
    }
}
