//HangMan game


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIFFERENCE 32
#define A 97
#define Z 122
#define START 1
#define EXIT 2
#define ZERO 48
#define WORD0 5
#define WORD123 13
#define WORD4 9
#define SPACES0 2
#define SPACES123 6
#define SPACES4 4
#define MAXLIVES 6

main()
{
    int i, count, charcount, menu, random, Lives, ascii, length, total, spaces, typed;
    char letter, yesorno;
    char word0[WORD0]={'C',' ','A',' ','T'};
    char word1[WORD123]={'P',' ','R',' ','O',' ','G',' ','R',' ','A',' ','M'};
    char word2[WORD123]={'B',' ','I',' ','C',' ','Y',' ','C',' ','L',' ','E'};
    char word3[WORD123]={'E',' ','L',' ','E',' ','M',' ','E',' ','N',' ','T'};
    char word4[WORD4]={'V',' ','A',' ','L',' ','U',' ','E'};
    char word0d[WORD0]={'_',' ','_',' ','_'};
    char word1d[WORD123]={'_',' ','_',' ','_',' ','_',' ','_',' ','_',' ','_'};
    char word2d[WORD123]={'_',' ','_',' ','_',' ','_',' ','_',' ','_',' ','_'};
    char word3d[WORD123]={'_',' ','_',' ','_',' ','_',' ','_',' ','_',' ','_'};
    char word4d[WORD4]={'_',' ','_',' ','_',' ','_',' ','_'};
    char word[WORD123]={' '};
    char wordd[WORD123]={' '};
    char guessed[WORD123]={' '};
//****************** START GAME *********************************************************
    printf("\n\n\n\n");
    printf("************ ");
    printf("HANGMAN GAME");
    printf(" ************\n\n");
    printf("1) Start game\n");
    printf("2) Exit game\n\n\n");
    printf("Press 1 or 2 to pick up the option: ");
    scanf("%d",&menu);

    while(menu!=START && menu!=EXIT || menu>'a' && menu<'z')
    { //INVALID INPUT MENU
        printf("\nInvalid input, press 1 or 2: ");
        getchar();
        scanf("%d",&menu);
    }

    switch(menu)
    { //MENU CASES 1 START AND 2 EXIT
//****************** CASE START MENU ****************************************************
        case START:
        do
        { //PLAY AGAIN
//(1)************** GENERATE RANDOM NO **************************************************
            srand(time(NULL));
            random = rand()%5;
//(2)************** READ IN WORD TO COMMON ARRAYS ***************************************
            switch(random)
            { //CASES FOR EACH WORD
                case 0:
                length=WORD0;
                spaces=SPACES0;
                for(i=0;i<length;i++)
                {
                    wordd[i]=word0d[i];
                }
                for(i=0;i<length;i++)
                {
                    word[i]=word0[i];
                }
                break;

                case 1:
                length=WORD123;
                spaces=SPACES123;
                for(i=0;i<length;i++)
                {
                    wordd[i]=word1d[i];
                }
                for(i=0;i<length;i++)
                {
                    word[i]=word1[i];
                }
                break;

                case 2:
                length=WORD123;
                spaces=SPACES123;
                for(i=0;i<length;i++)
                {
                    wordd[i]=word2d[i];
                }
                for(i=0;i<length;i++)
                {
                    word[i]=word2[i];
                }
                break;

                case 3:
                length=WORD123;
                spaces=SPACES123;
                for(i=0;i<length;i++)
                {
                    wordd[i]=word3d[i];
                }
                for(i=0;i<length;i++)
                {
                    word[i]=word3[i];
                }
                break;

                case 4:
                length=WORD4;
                spaces=SPACES4;
                for(i=0;i<length;i++)
                {
                    wordd[i]=word4d[i];
                }
                for(i=0;i<length;i++)
                {
                    word[i]=word4[i];
                }
                break;
            } //END CASES FOR EACH WORD
//(3)************** PRINTING THE WORD AND GUESSED LETTERS *******************************
            Lives=MAXLIVES;
            count=0;
            total=0;
            do
            {
                printf("\n\n\nLives: %d\n\n",Lives);
                printf("Word: ");
                for(i=0;i<length;i++)
                {
                    printf("%c",wordd[i]);
                }
                printf("\n\nLetters guessed so far: ");
                for(i=0;i<count ;i++)
                {
                    printf("%c,",guessed[i]);
                }
//(4)************** CHECKING LETTER *****************************************************
                do
                { //GUESS THE LETTER REPEATING
                    typed=0;
                    printf("\n\n\nGuess the letter or press '0' to exit:\n");
                    getchar();
                    scanf("%c",&letter);
//(5)************** CONVERTING SMALL LETTERS TO CAPITALS ********************************
                    ascii=letter;
                    if(ascii>=A && ascii<=Z)
                    {
                        ascii = ascii-DIFFERENCE;
                        letter = ascii;
                        for(i = 0;i<count;i++)
                        {
                            if(guessed[i]==letter)
                            {
                                printf("\n\n\n----------------------------------\n");
                                printf(" YOU ALREADY TYPED THAT LETTER!!!\n");
                                printf("----------------------------------");
                                typed=START;
                            }
                            else{}
                        }
                    }
                    else{}
                } //DO END GUESS THE LETTER
                while(typed==START);
                guessed[count]=letter;    //READ IN GUESSED LETTERS
                count++;
//(6)************** SEARCH LETTER AND DISPLAY *******************************************
                charcount=0;
                for(i=0;i<length;i++)
                {
                    if(word[i]==letter)
                    {
                        charcount++;
                        wordd[i]=letter;
                        total++;
                    }
                    else{}
                }
                if(charcount!=0)
                {
                    printf("\n\n\n----------------\n");
                    printf(" LETTER MATCH:)\n");
                    printf("----------------");
                }
//(7)*************************** LIVES  *************************************************
                if(charcount==0)
                {
                    Lives--;
                    printf("\n\n\n--------------------\n");
                    printf(" LETTER DONT MATCH:(\n");
                    printf("--------------------");
                }
                if(Lives==0)
                {
                    printf("\n\n\n************\n");
                    printf(" YOU LOST:(\n");
                    printf("************\n\n");
                    printf("WORD WAS: ");
                    for(i=0;i<length;i++)
                    {
                        printf("%c",word[i]);
                    }
                }
                if(total==length-spaces)
                {
                    printf("\n\n\n****************************************\n");
                    printf(" CONGRATULATION YOU GUESSED WHOLE WORD:)\n");
                    printf("****************************************\n\n");
                }
            } //DO END - PLAY AGAIN
            while(Lives!=0 && ascii!=ZERO && total!=length-spaces);
//****************** END PROGRAM ********************************************************
            printf("\n\n\n-------------------------------\n");
            printf(" DO YOU WANT TO PLAY AGAIN Y/N\n");
            printf("-------------------------------\n\n");
            printf("\n\n\n");
            getchar();
            scanf("%c",&yesorno);
            while(yesorno!='y' && yesorno!='Y' && yesorno!='n' && yesorno!='N')
            {
                printf("\nInvalid input, press Y or N: ");
                getchar();
                scanf("%c",&yesorno);
            } //WHILE END
        } //END PLAY AGAIN
        while(yesorno!='n' && yesorno!='N');
        break;
//****************** CASE EXIT MENU *****************************************************
        case EXIT:
        system ("exit");
        break;

        default:
        printf("\nInvalid input, press 1 or 2: ");
        scanf("%d",&menu);
    } //END SWITCH MENU
} //END MAIN

