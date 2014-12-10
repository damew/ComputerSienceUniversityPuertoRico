/*
 * Ricardo J Mojica Rivera
 * 841-07-5094
 * September 24, 2014
 * rock_paper_scissors.c
 * This program emulate a rock, paper & scissors
 * game again the computer.
 */

#include <stdio.h> //for printf, scanf
#include <stdlib.h> //for srand, rand
#include <ctype.h> //for tolower
#include <time.h> //for time

int compSelect();
int determWin(const int psel,const int csel, int *wgame,int *tgame);
void printResult(int csel, int winlost);
void clearBuffer();

int main(void){
    // Initializes random number generator with a time-derived seed.
    srand(time(NULL));

    char play;
    int pselect, cselect, twin = 0, tplay = 0;

    do{  // main cycle to determine  if want to continue

        do{  // will continue until 0,1 or 2 is chosen

            printf("Enter your selection (0=Rock, 1=Paper, 2=Scissors): ");
            scanf("%d", &pselect);

            if (pselect != 0 && pselect != 1 && pselect != 2)
                printf("Selection invalid.  Try again.\n\n");

        }while (pselect != 0 && pselect != 1 && pselect != 2);

            printResult(cselect = compSelect(), determWin(pselect, cselect, &twin, &tplay));

        do{  // validate that y,Y,n or N is written

            clearBuffer();

            printf("Do you want to play again (y/n)? ");
            scanf("%c", &play);
            printf("\n");

            if (tolower(play) != 'y' && tolower(play) != 'n')
                printf("Selection invalid.  Try again.\n");
        }while(tolower(play) != 'y' && tolower(play) != 'n');
    }while (play == 'y');
    // print the message with 1 decimal float and one %
    printf("Thanks for playing.  You won %.1f%% of the games.\n", (float)twin/tplay*100);
}

// return a aleatory number form 0-2
int compSelect(){
    return rand() % 3;
}

// compare player and computer selection
// return the 1 if win else return 0
// augment the total of game and the win of game
int determWin(const int psel, const int csel, int *wgame,int *tgame){
    *tgame += 1;
    if (psel == 2 && csel == 1){ // player scissor and computer paper
        *wgame += 1;
        return 1;
    }else if (psel == 1 && csel == 0){ // player paper and computer rock
        *wgame += 1;
        return 1;
    }else if (psel == 0 && csel == 2){ // player rock and computer scissor
        *wgame += 1;
        return 1;
    }else{
        return 0;
    }
}

// print the computer selection in words
// print if player won or lost
void printResult(int csel, int winlost){
    if (csel == 0)
        printf("My selection was 0=Rock.  ");
    else if (csel == 1)
        printf("My selection was 1=Paper.  ");
    else if (csel == 2)
        printf("My selection was 2=Scissors.  ");

    if (winlost == 1)
        printf("You won!\n");
    else
        printf("You lost!\n");
}

// clear the buffer
void clearBuffer(){
    while (getchar() != '\n');        // flush keyboard buffer
}
