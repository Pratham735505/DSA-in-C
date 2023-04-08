#include<stdio.h>
#include<conio.h>
//Write a C program to find factorial of any number using recursion.
int fact(int n);
void main(){
int n;
clrscr();
printf("Enter the number=");
scanf("%d",&n);
printf("The factorial of %d is=%d",n,fact(n));
getch();}
 
int fact(int n){
if(n==0)
return 1;
else if(n==1)
return n;
else if(n<0)
printf("wrong input");
else
return n*fact(n-1);

}