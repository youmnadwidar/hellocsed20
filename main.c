#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "W&L.h"
#include "Array_fun.h"
#include "Players_ranks.h"
#include <ctype.h>
#include "Mine_sweeper.h"
#include "cell_operations.h"
#include "game_loop.h"
#include"INCell_operations.h"
#include <pthread.h>

extern int n,m,flag_thread;
int main()


{
    Mine_sweeper();
    printf("\t\t\t\tPress Enter to start the game");

    getchar();
    while (1)
    {

        system("COLOR F");
        system("cls");

        //the main menu to choose what u want to do

        printf("\n\t\t\tWELCOME TO MINESWEEPER \n\n\n");
        char  sequance_game;
        SetColor(6);
        printf("\tNew Game (n)\n\n");
        SetColor(13);

        printf ("\tLoad Game (l)\n\n");
        SetColor(14);

        printf("\tRanks (r)\n\n");
        SetColor(15);

        sequance_game=getchar();
        system("cls");

// turning any capital letter into small
        if (sequance_game=='N' ||sequance_game=='R' ||sequance_game =='L')
        {

            sequance_game+='a'-'A';
        }
        //r means Ranks
        if(sequance_game=='r')
        {

            Print_Ranks();
        }



// N means new game
        if (sequance_game=='n')
        {
            printf("enter the number of rows and columns (any input other than integer won't be taken) :\n");
            getchar();
            int flag_Array=0;
            int s1=0,s2=0;
            while (!flag_Array)
            {


//checking if the n and m are integer (valid)
                s1=scanf(" %d",&n);

                s2=scanf("%d",&m);


                if(s1==1&&s2==1)
                {
                    if (n>2&&n<=30&&m>2&&m<=30)
                    {
                        //flag=1 means the n , m valid integers
                        flag_Array=1;

                    }
                    else
                    {
                        // the n,m integers but not in the range
                        printf("Please enter a valid number (between 3 and 30 )");
                    }

                }
                else
                {
                    //the n , m are not integers

                    getchar();
                }
            }

            int B[n][m],j;
            char A[n][m];
            //initialize the Array with x
            initalizeArraychar(A,n);
            system("cls");

            int i,temp1,temp2,nom,s=0;


//initializing B with 0 (0 means empty cell)
            for ( i = 0; i < n; i++)
            {
                for ( j = 0; j < m; j++)
                {
                    B[i][j] =0 ;
                }
            }




            printArray(A,n);
            nom=NofMines(n,m); //number of mines
            int X[nom],Y[nom]; //storage of mines locations
             //declaring time
            time_t start,finish, diff_t;
            time(&start);
            int row,col;

            // counter for the moves , flag and ?

            int countf=0,countQ=0,counter=0;

            SetColor(7);
            //the first cell must be opened
            printf("Your first cell will be opened\n\n");

            //scan the row and col

            scan_coordinates(&row,&col,A);

            time_t t;
            srand((unsigned) time(&t));
            //random locations
            for(i=0; i<nom; i++)
            {

                temp1 = (int)floor(((rand() / 11) * 13 + rand())) % n;
                temp2 = (int)floor(((rand() / 11) * 13 + rand())) % m;
                //checking if these coordinates  not used before and are not the coordinates of the first cell
                if(B[temp1][temp2]!=(-1)&&temp1!=row-1&&temp2!=col-1)
                {
                    B[temp1][temp2]=(-1);// setting mines
                    X[s]=temp1;
                    Y[s]=temp2;// storing locations
                    s++;
                    fn_num(B,n,temp1,temp2);// adding 1 to the cells around mine
                }
                else
                {
                    i--;
                }


            }
            //printing Array B in a file for debugging
            FILE *Arr_B;
            Arr_B=fopen("Mine.Arr.txt","w");
            for(i=0; i<n; i++)
            {

                for(j=0; j<m; j++)
                {
                    fprintf(Arr_B,"%i\t",B[i][j]);

                }
                fprintf(Arr_B,"\n\n");
            }
            fclose(Arr_B);
            //a variable to send in the place of the lose variable
            int g=0;
            //opening the first cell
            Get_cell_value(row-1,col-1,A,B,n,&g);

            counter++;
            //getting the finish time to calculate the time
            diff_t=time(&finish)-start;
            // checking if the user won
            int win=win_condition(A,n,nom);
            //the player score
            long long score = (pow(n,4)*pow(m,4)/(diff_t*counter));
            if(win)
            {
                win_function(score,A);

            }

            else//he didn't won
            {
                Game_loop(A,B,nom,countf,countQ,counter,start,X,Y);
            }
        }

        else if(sequance_game=='l')//choosing l means load game
        {
            int i,j,num;
            char ch;
            int countf=0,countQ=0,counter=0,nom;
            time_t start,diff_t;
            time(&start);

            FILE *f_load;

             if(!(f_load=fopen("savedgame.txt","r")))//checking if there is any loaded game
            {
                printf("There's no saved game.\n");
                printf("Press Enter to return to the main menu .");
                getchar();
                getchar();
            }
            else
            {//read n m from the file , the two grids , counters and the time
            fscanf(f_load,"%d %d\n",&n,&m);
            fscanf(f_load,"%d\n%d\n%d\n%d\n",&counter,&countf,&countQ,&nom);
            fscanf(f_load,"%d\n",&diff_t);
            char A[n][m];
            int B[n][m];
            int X[nom],Y[nom];

            for (i=0; i<n; i++)
            {
                for (j=0; j<m; j++)
                {

                    fscanf(f_load,"%d ",&ch);
                    A[i][j]=ch;

                }
                fscanf(f_load,"\n");
            }


            for (i=0; i<n; i++)
            {
                for (j=0; j<m; j++)
                {
                    fscanf(f_load,"%d ",&num);
                    B[i][j]=num;

                }

                fscanf(f_load,"\n");
            }


            for (j=0; j<nom; j++)
            {//the Array of the x coordinates of the mines
                fscanf(f_load,"%d ",&num);
                X[j]=num;
            }
            fscanf(f_load,"\n");
            for (j=0; j<nom; j++)
            {//the Array of the y coordinates of the mines
                fscanf(f_load,"%d ",&num);
                Y[j]=num;
            }


            fscanf(f_load,"\n");



            fclose(f_load);
            //remove the file after loading the game in order not to return to it back after losing or wining
            remove("savedgame.txt");


            start-=diff_t;
            printArray(A,n);
            Game_loop(A,B,nom,countf,countQ,counter,start,X,Y);
        }
        }

    }

    return 0;

}

