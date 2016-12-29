int n,m;//necessary
#include <ctype.h>
#include "W&L.h"
#include "Array_fun.h"
#include "INCell_operations.h"
#include <pthread.h>
#include "thread.h"

int flag_thread;
//getting the value of the f and the ? cells
void Mark_cell(int x,int y,char A[][m],int n,char Themove,int *c)
{
    //only cells with those value are ok to Mark them or Unmark(not allowed for numbers or empty cells)
    if(A[x][y]=='F' || A[x][y]=='X' || A[x][y]=='?')
    {
        //means if it's already marked
        if (A[x][y]==Themove)
        {
            //unmark the cell
            A[x][y]='X';
            *c-=1;
        }
        else
        {
            A[x][y]=Themove;
            *c+=1;
        }
    }
    system ("cls");
    printArray(A,n);


}










void Get_cell_value(int x,int y,char A[][m],int B[][m],int n,int *l)
{
    int number;
    int i,j;
    number=B[x][y];
    //can't open a flaged cell
    if (A[x][y]!='F')
    {
        // -1 means a mine
        if (number==(-1))
        {
            A[x][y]='!';
            //the lose variable
            *l=1;
        }
        //means empty cell
         else if (number==0)
        {
            open_DFS(x,y,A,n,B);

        }
//Already opened
        else if(A[x][y]==number+'0')
        {

            open_open(x,y,A,n,B,&*l);

        }

//not opened and have a num value
        else if (A[x][y]=='X')
        {
            A[x][y]=number+'0';
        }

    }

    system("cls");
    printArray(A,n);

}


void scan_coordinates(int *x, int *y,char A[][m])
{

    int flag=1;
    int f1;
    int f2;
    pthread_t thread_2;
    int flag_thread=0;
    while (flag)
    {
        getchar();
        printf("enter the row number :");

//creating a thread to run time while scaning
        flag_thread=1;
        pthread_create(&thread_2, NULL, thread,&flag_thread);

        f1=scanf("%d",&*x);

        flag_thread=0;
        //close thread
        pthread_join(thread_2, NULL);


        printf("enter the column number ");
//create another thread with the same function
        flag_thread=1;
        pthread_create(&thread_2, NULL, thread,&flag_thread);

        f2=scanf("%d",&*y);

        flag_thread=0;
        pthread_join(thread_2, NULL);
//checking if the coordinates are valid integers

        if(f1==1&&f2==1)
        {
            //if the row , col are between the grid size
            if(*x>0&&*x<n+1&&*y>0&&*y<m+1)
            {
                flag=0;
            }
            else
            {
                system("cls");
                printArray(A,n);
                //means valid integers but not int the range of the array size
                printf("enter a valid coordinates (row between 1,%d)and (col between 1,%d) :\n",n,m);

            }

        }

        else
        {
            system("cls");
            printArray(A,n);
            //row , col are not integers
            printf("invalid input ,please enter a number.\n");
            getchar();
        }


    }
}





