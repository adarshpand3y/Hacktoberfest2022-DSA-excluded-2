/*This is going to be fun!!  We will write a program that generates a random number and asks the player to guess it. If the player’s guess is higher than the actual number, the program displays “Lower number please.” Similarly, if the user’s guess is too low, the program prints “Higher number please.”

When the user guesses the correct number, the program displays the number of guesses the player used to arrive at the number.

Hints:

Use loops
Use a random number generator.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int number,guess,nguess=1,n=50,m=1;
    srand(time(0));
    number=rand()%50 + 1;// Generates a random number between 1 and 50
    // printf("The number is %d\n", number);
    // Keep running the loop until the number is guessed
    do
    {
        printf("Guess the number between 1 to 50\n");
        scanf("%d",&guess);
        if (guess>n)
        
        {
            printf("oops! choose within the range\n");
        }
        else if (guess<m){
            printf("oops! choose within the range\n");
        }
        else if (guess>number)
        {
            printf("close enough!\n");
        }
        else if (guess<number)
        {
            printf("a little higher!\n");
        }
        else{
            printf("You guessed it in %d attempts!\n",nguess);
            
        }
        nguess++;
        
    } while (guess!=number);
       
    return 0;
}
