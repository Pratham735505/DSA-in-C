#include <stdio.h>
#include <stdlib.h>
#define max 10

char tree[max];

/*void rootcbt();
void leftcbt();
void rightcbt();
void printcbt();*/

void printcbt()
{
	int i;
	for(i=0; i<max; i++)
	{
		if(tree[i]=='\0')
			printf("*");
		else
		{
			printf("%c", tree[i]);
		}
	}
}

void rightcbt()
{
	char c;
	int parent;
	printf("Enter Character: ");
	scanf("%c", &c);
	printf("Enter Parent: ");
	scanf("%d", &parent);
	
	if(tree[parent]=='\0')
		printf("Can't insert %c. Parent of %c doesn't exit.\n", c, c);
	else
	{
		tree[(2*parent) + 2] = c; 
	}
}

void leftcbt()
{
	char c;
	int parent;
	printf("Enter Character: ");
	scanf("%c", &c);
	printf("Enter Parent: ");
	scanf("%d", &parent);
	
	if(tree[parent]=='\0')
		printf("Can't insert %c. Parent of %c doesn't exit.\n", c, c);
	else
	{
		tree[(2*parent) + 1] = c; 
	}
}

void rootcbt()
{
	char c;
	printf("Enter Character: ");
	scanf("%c", &c);
	printf("\n");
	if(tree[0]!='\0')
	{
		printf("Root already exists.\n");
	}
	else
	{
		tree[0] = c;
	}
}

void insertcbt()
{
	int ch;
	while(1)
	{
		printf("1.Insert root\n2.Insert left\n3.Insert right\n4.Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				rootcbt();
				break;
			case 2:
				leftcbt();
				break;
			case 3:
				rightcbt();
				break;
			case 4:
				return;
				break;
			default:
				printf("Invalid Choice.\n");
		}
	}
}

void complete_binary_tree()
{
	int ch;
	while(1)
	{
		printf("1.Insert\n2.Print\n3.Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				insertcbt();
				break;
			case 2:
				printcbt();
				break;
			case 3:
				return;
				break;
			default:
				printf("Invalid Choice.\n");
		}
	}
}

int main()
{
	int ch;
	while(1)
	{
		printf("1.Complete Binary Tree\n2.Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				complete_binary_tree();
				break;
			case 2:
				exit(0);
				break;
			default:
				printf("Invalid Choice\n");
		}
	}
	return 0;
}