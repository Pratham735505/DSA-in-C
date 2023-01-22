#include <stdio.h>
#include <stdlib.h>
#define M 5

int i, a[M];
int b, tops;

struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;

void pops();
void pushs();
void displays();

void displayd();
void pushd(int);
void popd();

int main()
{
    int n, ch;
    do
    {
        printf("-----------------------Menu-----------------------\n");
        printf("1. Dynamic Stack Implementation\n2. Static Stack Implementation\n3. ");
        scanf("%d", ch);
        if (ch == 1)
        {
            printf("\n\nStack Menu\n1. Push \n2. Pop\n3. Display\n0. Exit");
            printf("\nEnter Choice 0-3? : ");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                printf("\nEnter number ");
                scanf("%d", &n);
                pushd(n);
                break;
            case 2:
                popd();
                break;
            case 3:
                displayd();
                break;
            }
        }
        else if (ch == 2)
        {
            tops = -1;

            // do
            //{
            printf("Enter 1 for push\n");
            printf("Enter 2 for pop\n");
            printf("Enter 3 for display\n");
            printf("Enter 4 for exit=");
            scanf("%d", &i);
            switch (i)
            {
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
            //} while (i != 4);
        }
    } while (ch != 0);
}

void pushs()
{
    if (tops == M - 1)
        printf("Stack Overflow");
    else
    {
        printf("Enter value to be pushed=");
        scanf("%d", &b);
        tops = tops + 1;
        a[tops] = b;
    }
}

void pops()
{
    if (tops == -1)
        printf("Stack Underflow");
    else
    {
        printf("\nThe popped element is %d=", a[tops]);
        tops = tops - 1;
    }
}

void displays()
{
    if (tops == -1)
        printf("stack is empty");
    else
    {
        int i;
        for (i = tops; i >= 0; i--)
        {
            printf("%d\n", a[i]);
        }
    }
}

void pushd(int item)
{
    struct node *nptr = malloc(sizeof(struct node));
    nptr->data = item;
    nptr->next = top;
    top = nptr;
}

void displayd()
{
    struct node *temp;
    temp = top;
    while (temp != NULL)
    {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
}

void popd()
{
    if (top == NULL)
    {
        printf("\n\nStack is empty ");
    }
    else
    {
        struct node *temp;
        temp = top;
        top = top->next;
        printf("\n\n%d deleted", temp->data);
        free(temp);
    }
}