#include<stdio.h>
#include<stdlib.h>
#define max 5
//program to implement static queue
void insertion();
void deletion();
void display();
int q[max],front=-1,rear=-1;
void main(){

int i,p,r,s,t,u,v,w,x;
do{
printf("---------------Menu------------\n");
printf("1.Simple queue\n2.Circular Queue \n3.Double Ended queue\n4.Priority queue\n5.Exit\n");
scanf("%d",&p);
switch(p){
case 1:
     printf("1.Static queue\n2.Dyanamic queue\n3.Exit\n ");
     scanf("%d",&r);
     
     switch(r){
     do{
       case 1:
      
         printf("1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
         scanf("%d",&w);      
         switch(w){
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
            }while(w!=4);
        case 2:
           break;
        case 3:
           break;    
        default:
           printf("\n Invalid choice\n");
         }
        
       break;
  
       
case 2:
printf("1.Static queue\n2 .Dyanamic queue\n3 .Exit\n ");
scanf("%d",&t);
     switch(t){
     case 1:
       break;
     case 2:
       break;
     case 3:
       exit(0);
     default:
       printf(" Enter a right number ");
      }
    break;
case 3:
printf("1.Static queue\n2 .Dyanamic queue\n3 .Exit\n ");
scanf("%d",&u);
    switch(u){
    case 1:
      break;
    case 2:
      break;
    case 3:
      exit(0);
    default:
      printf(" Enter a right number ");
    }
   break;
case 4:
  break;
case 5:
    exit(0);
default:
    printf(" Enter a right number=");}
    }while(p!=5);
    
getchar();
}

void insertion(){
int g;
if(rear==max-1){
printf("\nQueue Overflow\n");
}
else{
printf("\nEnter number to be pushed=");
scanf("%d",&g);
if(front==-1){
   front=0;}
   rear++;
   q[rear]=g;
}
}

void deletion(){
if(rear==-1 && front==-1){
printf("\nUnderflow\n");
}
else
{
   if(rear==front){
     printf("\nThe deleted element is=%d\n",q[front]);
     rear=-1;
     front=-1;
    }
   else{
      printf("\nThe deleted element is=%d\n",q[front]);
      front=front+1;
   }
}
}
void display(){
  int i;
   if(rear==-1 && front==-1){
   printf("\nQueue is empty\n");
    }
    else{
    for(i=front;i<=rear;i++){
    printf("%d\n",q[i]);
    }
    }
}