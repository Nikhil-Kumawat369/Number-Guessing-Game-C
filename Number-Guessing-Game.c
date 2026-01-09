#include <stdio.h>
#include <stdlib.h>

void setupGame (int *ptr , int *ptrStart , int *ptrEnd , int *ptrMultiplayerRangeOPT , int *ptrplayerNumber) ;

int main () {

    int mode ; // This saves the mode user wants to play ther game 

    // Same range variables are reused for single-player and multiplayer
    // because only one mode runs at a time, reducing unnecessary variables

    int rangeStart , rangeEnd ; // This saves the rage if user selects too 

    int multiplayerRangeOPT ; // This saves the multiplayer range option if user selected custom multiplayer mode

    int playerNumber ; // saves number of player for multiplayer mode

    setupGame (&mode , &rangeStart , &rangeEnd , &multiplayerRangeOPT , &playerNumber) ;

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


