#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void setupGame (int *ptr , int *ptrStart , int *ptrEnd , int *ptrMultiplayerRangeOPT , int *ptrplayerNumber) ; // this sets up the full game

void randomNumber (int *targetNumber , int rangeStart , int rangeEnd) ; // it decides the target number

int hint (int *guessNumber , int *targetNumber , int *c) ; // this give hint & warning msg

int main () {

    int mode ; // This saves the mode user wants to play ther game 

    // Same range variables are reused for single-player and multiplayer
    // because only one mode runs at a time, reducing unnecessary variables

    int rangeStart , rangeEnd ; // This saves the rage if user selects too 

    int multiplayerRangeOPT ; // This saves the multiplayer range option if user selected custom multiplayer mode

    int playerNumber ; // saves number of player for multiplayer mode

    int targetNumber ; // this stores the number which user have to guess

    srand(time(0)) ; // setting the seed for selecting random number 

    setupGame (&mode , &rangeStart , &rangeEnd , &multiplayerRangeOPT , &playerNumber) ;

    if (mode == 0) { // this is Classic Mode (Single Player) code ...

        char playerName1[50] ;

        printf("\n========================================\n");
        printf("        SINGLE PLAYER - CLASSIC MODE\n");
        printf("========================================\n\n");

        printf("The computer has selected a random number\n");
        printf("between 1 and 100.\n\n");

        printf("Your goal is simple:\n");
        printf("=> Guess the correct number\n");
        printf("=> Get hints after every wrong attempt\n");
        printf("=> Solve it in the LEAST number of attempts\n\n");

        printf("Fewer attempts means a higher score!\n");
        printf("Your best score will be saved automatically.\n\n");

        printf("Good luck - play smart!\n");

        printf("\n----------------------------------------\n");
        printf("PLAYER SETUP\n");
        printf("----------------------------------------\n\n");

        printf("Enter your player name to begin:\n");
        printf(">> ");
        getchar() ; // To clear the buffer
        fgets(playerName1 , 50 , stdin) ;

        playerName1[strcspn(playerName1 , "\n")] = '\0' ; // fget c always saved \n{Enter} too , it replaces it with \0

        randomNumber (&targetNumber , 1 , 100) ; // this would pick a random number between the range

        printf("The Number Game Begains\n") ;
        printf("Guess the number selected randomly 1 to 100\nDont Worry you will get hint after every wrong attempt\n") ;
        printf("Let The Game Begain\n") ;

        int guessNumber ; // this saves the users guess
        int c = 1 ; // Number of attempts
        int x ; // this a variable which will store values temperorly in the code , when ever needed

        do { // This takes input , checks if its correct guess & tracks the no of attemps too

            printf("Enter Your Guess %d\n" , c) ;
            printf(">> ");
            scanf("%d" , &guessNumber) ;

            x = hint (&guessNumber , &targetNumber , &c) ;

            if (x == 1) {
                continue ; // if user enters invalid then he got the penelty so ne future exesution in this itteration
            }else if (x == 100) {
                break ; // if user enters correct the the loop needs to end
            }

        }while (guessNumber != targetNumber) ;

        printf("\n\n##-- You guessed in %d attemps --##\n\n" , c) ;

        FILE *fptr ;

        fptr = fopen("HighScore.txt" , "r") ;

        int a ;

        fscanf(fptr , "%d" , &a) ;

        fclose(fptr);

        if (c < a) { // if user sets a new high score , update the high score

            FILE *fptr1 ;

            fptr1 = fopen("HighScore.txt" , "w") ;

            fprintf(fptr1 , "%d" , c) ;

            fclose(fptr1) ;

            printf("\n##-- Incredible! New Best Score! --##\n");
            printf("You guessed the number in just %d attempts!\n", c);
            printf("%s This is your new record! Keep up the amazing work!\n" , playerName1) ;

            exit(0) ; // this ends the game 

        }

        // if user do not set a high score

        printf("\n##-- Good try! --##\n");
        printf("You guessed the number in %d attempts.\n", c);
        printf("%s Your Best Score remains at %d attempts. Can you beat it next time?\n", playerName1 , a) ;

        exit(0) ;

    }

    return 0 ;

}

void setupGame (int *ptr , int *ptrStart , int *ptrEnd , int *ptrMultiplayerRangeOPT , int *ptrplayerNumber) {

    printf("========================================\n");
    printf("      WELCOME TO THE NUMBER GAME\n");
    printf("========================================\n\n");

    printf("Choose a mode to play:\n\n");

    printf("[ 0 ] Classic Mode  (Single Player)\n");
    printf("[ 1 ] Custom Mode   (Single Player)\n");
    printf("[ 2 ] Multiplayer Mode\n");
    printf("[ 3 ] Exit Game\n\n");

    printf("----------------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d" , ptr) ;

    switch (*ptr) {

        case 0 :printf("\n----------------------------------------\n");
                printf("CLASSIC MODE - SINGLE PLAYER\n");
                printf("----------------------------------------\n\n");

                printf("=> Computer selects a random number\n");
                printf("=> Fixed range: 1 to 100\n");
                printf("=> Only ONE player can play\n");
                printf("=> High Score WILL be saved\n\n");

                printf("Get ready to test your luck!\n");
                break ;

        case 1 :printf("\n----------------------------------------\n");
                printf("CUSTOM MODE - SINGLE PLAYER\n");
                printf("----------------------------------------\n\n");

                printf("=> You choose your own number range\n");
                printf("=> Computer selects a random number\n");
                printf("=> Only ONE player can play\n");
                printf("=> High Score will NOT be saved\n\n");

                printf("Enter your custom range to continue...\n");
                printf("Range start from :- ") ;
                scanf("%d" , ptrStart) ;
                printf("Range till :- ") ;
                scanf("%d" , ptrEnd) ;

                break ;

        case 2 :printf("\n----------------------------------------\n");
                printf("MULTIPLAYER MODE\n");
                printf("----------------------------------------\n\n");

                printf("Play with friends and take turns!\n");
                printf("No High Scores are saved in this mode.\n\n");

                printf("Choose number range:\n\n");
                printf("[ 0 ] Standard Range (1 to 100)\n");
                printf("[ 1 ] Custom Range\n\n");

                printf("----------------------------------------\n");
                printf("Enter your choice: ");
                scanf("%d" , ptrMultiplayerRangeOPT) ;

                if (*ptrMultiplayerRangeOPT == 0) {

                    printf("\n----------------------------------------\n");
                    printf("PLAYER SETUP\n");
                    printf("----------------------------------------\n\n");

                    printf("Enter number of players (minimum 2): ");
                    scanf("%d" , ptrplayerNumber) ;

                    if (*ptrplayerNumber < 2) {

                        printf("\n----------------------------------------\n");
                        printf("OOPS! THAT DIDN'T WORK\n");
                        printf("----------------------------------------\n\n");

                        printf("Multiplayer mode needs at least 2 players.\n");
                        printf("Playing alone is not multiplayer!\n\n");

                        printf("Please restart the game and try again.\n");
                        printf("Exiting now...\n");

                        exit(1) ;

                    }

                }else if (*ptrMultiplayerRangeOPT == 1) {

                    printf("\n----------------------------------------\n");
                    printf("CUSTOM MODE - MULTI PLAYER\n");
                    printf("----------------------------------------\n\n");

                    printf("=> You choose your own number range\n");
                    printf("=> Computer selects a random number\n");
                    printf("=> MULTIPLE player can play\n");
                    printf("=> High Score will NOT be saved\n\n");

                    printf("Enter your custom range to continue...\n");
                    printf("Range start from :- ") ;
                    scanf("%d" , ptrStart) ;
                    printf("Range till :- ") ;
                    scanf("%d" , ptrEnd) ;
                    printf("\n") ;

                    printf("\n----------------------------------------\n");
                    printf("PLAYER SETUP\n");
                    printf("----------------------------------------\n\n");

                    printf("Enter number of players (minimum 2): ");
                    scanf("%d" , ptrplayerNumber) ;

                    if (*ptrplayerNumber < 2) {

                        printf("\n----------------------------------------\n");
                        printf("OOPS! THAT DIDN'T WORK\n");
                        printf("----------------------------------------\n\n");

                        printf("Multiplayer mode needs at least 2 players.\n");
                        printf("Playing alone is not multiplayer!\n\n");

                        printf("Please restart the game and try again.\n");
                        printf("Exiting now...\n");

                        exit(1) ;

                    }

                }else {

                    printf("\n----------------------------------------\n");
                    printf("WRONG MOVE!\n");
                    printf("----------------------------------------\n\n");

                    printf("That option does not exist.\n");
                    printf("Rules were broken or input was invalid.\n\n");

                    printf("Restart the game to try again.\n");
                    printf("Exiting...\n");

                    exit(1) ;

                }

                break ;

        default :printf("\n----------------------------------------\n");
                printf("EXITING GAME\n");
                printf("----------------------------------------\n\n");

                printf("Thanks for playing!\n");
                printf("Hope to see you again soon.\n");
                printf("Goodbye 👋\n");

                exit(0) ;

                break ;

    }
    
}

void randomNumber (int *targetNumber , int rangeStart , int rangeEnd) {

    // it generates a random number between a range

    *targetNumber = (rand() % (rangeEnd - rangeStart + 1)) + rangeStart ; 

}

int hint (int *guessNumber , int *targetNumber , int *c) {

    if (*guessNumber < 0 || *guessNumber > 100) {

        printf("\nInvalid move!\n");
        printf("The number you entered is outside the allowed range.\n");
        printf("Penalty applied: This mistake counts as TWO attempts!\n");
        printf("Choose wisely - fewer attempts means a better score!\n");
        *c += 2; // penelty for invalid move added
        return 1 ; // its a signle that user entered an invalid move

    }

    if (*guessNumber > *targetNumber) {

        printf("\nToo high!\n");
        printf("The number is smaller than your guess. Try a lower number.\n");
        printf("Keep going! Fewer attempts = better score.\n");
        (*c)++ ; // keeping track of attemps
        return 0 ; // its a signle that user entered a valid move

    }else if (*guessNumber < *targetNumber) {

        printf("\nToo low!\n");
        printf("The number is higher than your guess. Try a higher number.\n");
        printf("You're getting closer! Fewer attempts = better score.\n");
        (*c)++ ; // keeping track of attemps
        return 0 ; // its a signle that user entered a valid move

    }else if (*guessNumber == *targetNumber) {

        printf("\n##-- Congratulations! --##\n");
        printf("You guessed the number correctly!\n");
        printf("It took you %d attempts.\n", *c);
        printf("Well done, champion!\n");
        return 100 ; // its a signle that user entered the correct number

    }

}
