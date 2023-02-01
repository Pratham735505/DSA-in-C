//a cool no. guessing game -->
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int i;
    int number, guess, nguess=1;
    srand(time(0));
    number=rand()%100 + 1; //generates a random no. between 1 and 100
    // printf("The number generated is %d\n",number);
    //the loop will run untill the no. is guessed
    
    for(i=1;i<=1;i++)
    {
         printf("----------WELCOME TO TIME PASS GAMES----------\n");
    }

    do{

      
        
        printf("Guess the number between 1 and 100\n");
        scanf("%d",&guess);
        if(guess>number)
        {
            printf("Lower Number Please!!!\n");
        }
        else if(guess<number)
        {
            printf("Higher Number Please!!!\n");

        }
        else
        {
            printf("You guessed it in %d attempts\n", nguess);
        }
        nguess++;
    }
        
        while(guess!=number);
        return 0;
        
    }