#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define Max 50
void insert();
void dele();
void display();


void bsearch();
void lsearch();

void ssort();
void bsort();
void isort();
void qsort();

int a[Max],count=0;
int choice,c,d,first=-1,last=-1;
int main(){
clrscr();
 printf("\nWelcome To our Program\n");
 printf("\nMenu\n");
 printf("\n1.Insert\n2.Delete\n3.Display\n4.Searching\n5.Sorting\n6.Exit\n");
 printf("\nEnter Choice:");
 scanf("%d",&choice);
 switch(choice){
 case 1:
    insert();
    break;
 case 2:
    dele();
    break;
 case 3:
    display();
    break;
 case 4:
 do{
    printf("\n1.Linear Searching\n2.Binary Search\n3.Return\nEnter Choice:");
    scanf("%d",&c);
    switch(c){
     case 1:
       lsearch();
       break;
     case 2:
       bsearch();
       break;
     case 3:
       break;
     default:
       printf("\nInvalid Choice\n");
    }
   } while(c!=3);
    break;
 case 5:
 do{
    printf("\n1.Selection sort\n2.Insertion Sort\n3.Bubble sort\n4.Quicksort\n5.Return\nEnter choice:\n");
    scanf("%d",&d);
    switch(d){
     case 1:
       ssort();
       break;
     case 2:
       isort();
       break;
     case 3:
       bsort();
       break;
     case 4:
       qsort();
       break;
     case 5:
       break;
     default:
       printf("\nInvalid Choice\n");
       }
       }while(d!=5);
       break;
 case 6:
 exit(0);
 default:
   printf("\nInvalid Choice\n");

 }


 return 0;
}


void insert(){
 if(last==Max-1){
 printf("\nArray is Full\n");
 }
 else{
   if(first==-1 && last==-1)
   {
     first++;
     last++;

   }


 }

}
void dele(){
}
void display(){
}
void ssort(){
}
void isort(){
}
void qsort(){
}
void bsort()
{
}

void bsearch(){
}
void lsearch(){
}