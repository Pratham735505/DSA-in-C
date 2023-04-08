#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>
#define M 20
void staticreversal();
void dynamicreversal();
void staticpalindrome();
//void dynamicpalindrome();
void pushi(char c);
void pop();
void push();
void display();
void sdisplay();
int i;
char rev[M];
struct node
{
    int data;
        struct node *next;
};

struct node *dtop = NULL;
void dcpush(char);
void dcdisplay();
void ddisplay();
void dpush(int);
void dpop();
int i,a[M];
int b,top;
int main()
{
 int n,g,ch,j,o,p;
printf("1.Static Implementation\n2.Dynamic Implementation\n3.Application\n4.Exit");
scanf("%d",&j);
  switch(j){
case 1:
 top=-1;
    clrscr();
    do{
    printf("Enter 1 for push\n");
    printf("Enter 2 for pop\n");
    printf("Enter 3 for display\n");
    printf("Enter 4 for exit=");
    scanf("%d",&i);
    switch(i){
    case 1:
    push();
    break;
    case 2:
    pop();
    break;
    case 3:
    display();
    break;
    case 4:
    exit(0);
    break;
    default:
    printf("Invalid choice");
    }
    }while(i!=4);
    break;
    /* dynamic stack */
    case 2:
    do
    {
        printf("\n\nStack Menu\n1. Push \n2. Pop\n3. Display\n0. Exit");
        printf("\nEnter Choice 0-3? : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("\nEnter number ");
                scanf("%d", &n);
                dpush(n);
                break;
            case 2:
                dpop();
                break;
            case 3:
                ddisplay();
                break;
        }
    }while (ch != 0);
    break;
    case 3:
    printf("\n1.Reversal\n2.Palidrome\n3.Exit\n");
    scanf("%d",&g);
    switch(g){
    case 1:
    printf("\n1.Static Reversal\n2.Dynamic Reversal\n");
    scanf("%d",&o);
    switch(o){
    case 1:
    staticreversal();
    break;
    case 2:
    dynamicreversal();
    break;
    default:
    printf("\nWrong choice");
    }
    break;
    case 2:
    printf("\n1.Static Palindrome\n2.Dynamic Palindrome\n");
    scanf("%d",&p);
    switch(p){
    case 1:
    staticpalindrome();
    break;
    // case 2:
    // dynamicpalindrome();
    // break;
    default:
    printf("\nWrong choice");
    }
    break;
    case 3:
    exit(0);
    break;
   default:
   printf("Wrong entry");
}
break;
    case 4:
    exit(0);
    break;
    default:
    printf("invalid Choice");
    }
    getch();
    return 0;
}

void push(){
  
  if(top==M-1)
  printf("Stack Overflow");
  else{ 
  printf("Enter value to be pushed=");
  scanf("%d",&b);
  top=top+1;
  a[top]=b;
}
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
int i;
for(i=top;i>=0;i--){
printf("%d\n",a[i]);
}
}
}

void dpush(int item)
{
    struct node *nptr = malloc(sizeof(struct node));
    nptr->data = item;
    nptr->next = dtop;
    dtop = nptr;
}

void ddisplay()
{
    struct node *temp;
    temp = dtop;
    while (temp != NULL)
    {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
}
void dpop()
{
    if (dtop == NULL)
    {
        printf("\n\nStack is empty ");
    }
    else
    {
        struct node *temp;
        temp = dtop;
        dtop = dtop->next;
        printf("\n\n%d deleted", temp->data);
        free(temp);
    }
}
void staticreversal(){
char c[20];
 top=-1;
printf("\nEnter a string=");
gets(c);
for(i=0;i<=strlen(c);i++){
pushi(c[i]);}
printf("\n The reverse of string is=");
display();
}


void pushi(char c){
top=top+1;
a[top]=c;
}

void dynamicreversal(){
int i;
char c[20];
printf("\nEnter a string=");
gets(c);
for(i=0;i<=strlen(c);i++){
dcpush(c[i]);}
printf("The reverse of string=");
dcdisplay();
}

void dcpush(char item)
{
    struct node *nptr = malloc(sizeof(struct node));
    nptr->data = item;
    nptr->next = dtop;
    dtop = nptr;
}

void dcdisplay()
{
    struct node *temp;
    temp = dtop;
    while (temp != NULL)
    {
        printf("%c", temp->data);
        temp = temp->next;
    }
}

void staticpalindrome(){
char c[20];
printf("\nEnter a string=");
gets(c);
for(i=0;i<=strlen(c);i++){
push(c[i]);
}
sdisplay();
}


void sdisplay()
{
    int j=0,flag=0;
    if (top == -1)
	printf("stack is empty");
    else
    {
	int i;
	for (i = top; i >= 0; i--)
	{
	    printf("%c", a[i]);
	    if(a[i]=='\0'){
		continue;
	    }
	    rev[j]=a[i];
	    j++;
	}
	printf("\n");
	for(i=0;i<=top;i++){
	    if(rev[i]!=a[i]){
		flag=1;
		break;
	    }
	}
	if(flag==0){
	    printf("\nIt is pallindrome");
	}
	else{
	    printf("\nIts not pallindrome");
	}

    }
}