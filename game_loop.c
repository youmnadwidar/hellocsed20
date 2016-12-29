#include<time.h>
#include <math.h>
#include <stdio.h>
#include "After_W.h"
#include "Players_ranks.h"
#include "W&L.h"
#include <pthread.h>
#include "thread.h"

int n,m;
int flag_thread;

void Game_loop(char A[][m],int B[][m],int nom,int countf,int countQ,int counter,time_t start,int X[],int Y[])
{

    time_t finish,diff_t;
    //two variables to know if he won or he lost or neither
    int win=0,lose=0;
    char operation;
    int row,col;
    long long score;
//the player didn't win or lose
    while (!win&&!lose)
    {


        int flag_operation;
        do
        {
//the valid operations
            SetColor(4);
            printf("[f] for flag\t\t\t");
            SetColor(5);
            printf("[o]for opening\n\n");
            SetColor(2);
            printf("[?]for uncertainty\t\t");
            SetColor(6);
            printf("[s]for saving the game \n\n");
            SetColor(15);
            printf("please enter the operation you want:\n");
//creating a timer thread
            pthread_t thread_1;
            int flag_thread=1;
            pthread_create(&thread_1, NULL,thread,&flag_thread);

            scanf(" %c",&operation);

            flag_thread=0;
            pthread_join(thread_1, NULL);
//changing every small with capital
            if(operation=='f'||operation=='o' || operation=='s')
            {
                operation=operation-'a'+'A';

            }
//s means save the game
            if (operation=='S')
            {
                save_fun(countf,countQ,counter,nom,diff_t,A,B,X,Y);

//jump to the printing of the display
                goto top2;

            }

            scan_coordinates(&row,&col,A,&flag_thread);

            flag_operation=0;


            switch(operation)
            {
            case 'F':
                Mark_cell(row-1,col-1,A,n,operation,&countf);
                //a flag to make it loop if the operation is not valid
                flag_operation=1;
                break;
            case '?':
                Mark_cell(row-1,col-1,A,n,operation,&countQ);
                flag_operation=1;
                break;
            case 'O':
                Get_cell_value(row-1,col-1,A,B,n,&lose);
                flag_operation=1;
                 counter++;

                break;
            default :
                system("cls");
                printArray(A,n);
                printf("please enter a valid operation(f , ? or o) :\n\n ");


            }
        }

        while(!flag_operation);

  top2 :

        diff_t=time(&finish)-start;
        SetColor(7);
        //printing time
        printf(" time passed %d :%d\n\n",diff_t/60,diff_t%60);
        SetColor(27);
//printing counters
        printf("Number of flags : %i\t\tNumber of ? : %i\t\tNumber of moves : %i\t\tNmber of mines left:%i\n\n",countf,countQ,counter,nom-countf);
        SetColor(15);

        win=win_condition(A,n,nom);
        score = ((int)pow(n,4)*(int)(pow(m,4))/(diff_t*counter));
//check if he won or lose
        if (lose)
        {

            loseFun(X,Y,n,A,nom);
        }
        if (win)
        {
            win_function(score,A);




        }


    }
}
