#include<stdio.h>
#include<conio.h>
struct rec{
char name[10];
int age;
float salary;
}rec1;

void main(){
printf("Size of member name=%d\n",sizeof(rec1.name));
printf("Size of member age=%d\n",sizeof(rec1.age));
printf("Size of member salary=%d\n",sizeof(rec1.salary));
printf("Size of structure=%d\n",sizeof(rec1));
  
  getch();
}