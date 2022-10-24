/*

    Program: guess.c

    This is interactive program which gets input from the user to geuss
    a number between 1-10. 

    Menu should look like this: 
        1. Press 1 to play game
            * promt the user to enter a number for guess
            * If correct, tell them they won and back to main menu
            * Else, tell them number is too low or high, and let them guess again
            * This should continue until they win
            * 
            * Input type: number, others are invaild and try again, q is quit
        2. Press 2 to change the max number
            * let the user set the max value (within 1-10)
        3. Press 3 to quit
            * Thank the user and end the game

*/
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

// global and static variables
int guess;
int max = 10;

// Function prototypes
void displayMenu();
void suggestGuess(int target);
int promptUser();
int checkGuess(int target); // 1 true, 0 false


int main()
{

    // variable declare here
    int target; 
    int menu;
    
    // var as boolean
    int keepProgram = 1;
    int keepGame = 1;
    int validInput = 0;
    int check = 0; 

    // seed the time in random, generate target
    time_t t;
    srand((unsigned) time(&t));
    target = (rand() % 10) + 1;

    // actual game with do-while loop
    do{
        // new game start
        // reset variables
        guess = 0;
        
        displayMenu();
        menu = promptUser();

        switch(menu)
        {

            case 1: 
                // actual game
                // loops until target found, or q pressed
                while(keepGame == 1)
                {
                    printf("Please enter a number to guess: ");
                    validInput = scanf("%d", &guess);
                    if(validInput == 1)
                    {
                        // enter here when valid integer was received
                        if((guess > 0) && (guess < max))
                        {
                            // when user inputs correct range of guess
                            check = checkGuess(target);
                            if(check == 1)
                            {
                                printf("Your guess is correct!!\n");
                                keepGame = 0;
                            }
                        }
                    }
                    else
                    {
                        keepGame = 0;
                    }

                }
                break;
            case 2: 
                // change max num
                printf("set new max, 1 - 10: ");
                scanf("%d", &max);
                keepProgram = 1;
                break;
            case 3: 
                printf("Thank you for playing this game! \n");
                keepProgram = 0;
                break; 
            default:
                printf("Invalid menu input, try again...\n");
                keepProgram = 1;
                break;
        }

        



    } while (keepProgram == 1);






}

void displayMenu()
{
    printf("Press 1 to play a game\n");
    printf("Press 2 tp change the max number\n");
    printf("Press 3 to quit\n");

}

void suggestGuess(int target)
{
    if(guess < target) 
    {
        printf("The guess is too low\n");
    }
    else
    {
        printf("The guess is too high\n"); 
    }
}

int promptUser()
{
    int choice; 
    printf("Please enter your choice: ");
    scanf("%d", &choice);
    return choice; 

}

int checkGuess(int target) 
{
    if (guess == target)
    { 
        return 1; 
    }
    else 
    {
        suggestGuess(target);
        return 0; 
    }
}