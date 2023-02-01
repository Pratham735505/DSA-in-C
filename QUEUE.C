#include<stdio.h>
#include<stdlib.h>
//program to implement static queue
void insertion();
void deletion();
int q[10];
void main(){

int p,r,s,t,u,v;
do{
printf("---------------Menu------------\n");
printf("1. simple queue\n2 .circular queue\n3 .Double Ended queue\n4 .priority queue\n5 .Exit\n");
scanf("%d",&p);
switch(p){
case 1:
     printf("1.Static queue\n2 .Dyanamic queue\n3 .Exit\n ");
     scanf("%d",&r);
     switch(r){
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
printf("1.Static queue\n2 .Dyanamic queue\n3 .Exit\n ");
scanf("%d",&v);
    switch(v){
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
case 5:
    exit(0);
default:
    printf(" Enter a right number=");
}
}
while(p!=5);
getchar();
}



