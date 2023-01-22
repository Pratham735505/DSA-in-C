
#include<stdio.h>
#include<conio.h>
#define M 20
void pop();
void push(char c);
void display();
int i,f=0;
char a[20],e[20];
int b,top;
int main()
{top=-1;
    clrscr();
 char c[20];
printf("Enter a string=");
 gets(c);
  for (i=0;i<=strlen(c);i++){
push(c[i]);
}
printf("The reverse of string is=");
display();
for(i=0;i<=strlen(c);i++){
if(c[i]==e[i])
f=1;}
if(f==1)
printf("\nString is palindrome");
else
printf("\n String is not palindrome");

    getch();
    return 0;
}

void push(char c){
  
  
  
  
  top=top+1;
  a[top]=c;

}
void pop(){
if(top==-1)
printf("Stack Underflow");
else{
printf("\nThe popped element is %d=",a[top]);
top=top-1;

}}
void display()
{ 

if(top==-1)
printf("stack is empty");
else{
int i,d=0;
for(i=top;i>=0;i--){
printf("%c",a[i]);
e[d]=a[i];
d++;
}
}
}

    