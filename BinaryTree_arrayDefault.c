#include <stdio.h>
#include <stdlib.h>
#define max 10

char tree[max];

void root(char);
void left(char, int);
void right(char, int);
void print();

void print()
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

void right(char c, int parent)
{
	if(tree[parent] == '\0')
	{
		printf("Can't insert %c. Parent of %c doesn't exist.\n", c, c);
	}
	else
	{
		tree[(2*parent)+2] = c;
	}
}

void left(char c, int parent)
{
	if(tree[parent] == '\0')
	{
		printf("Can't insert %c. Parent of %c doesn't exist.\n", c, c);
	}
	else
	{
		tree[(2*parent)+1] = c;
	}
}

void root(char c)
{
	if(tree[0] != '\0')
	{
		printf("Root already exists.\n");
	}
	else
	{
		tree[0] = c;
	}
}

int main()
{
    root('A');
    left('B',0);
    right('C',0);
    left('D',1);
    right('E',1);
    print();
	return 0;
}