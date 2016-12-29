int n,m;
#include"W&L.h"
#include "After_W.h"


//Getting the number of mines
int NofMines(int n,int m)
{
    return 1+(n*m)/10;
}
//initializing the Array with 'X'
void initalizeArraychar(char A[][m],int n)
{
    int i,j;
    for ( i = 0; i < n; i++)

        for ( j = 0; j < m; j++)
        {
            A[i][j] = 'X';
        }
    }





void printArray(char A[][m],int n)
{
    int i,j;
SetColor(10);
    printf("\n\t\t\t\tMINE SWEEPER\n\n");
    SetColor(15);
    printf("\t");
    for(i=1; i<=m; i++)
    {
        SetColor(11);
        //printing a row of coordinates

        printf("\t%i",i);
    }
    SetColor(15);

    printf("\n\n");
    for(i=0; i<n; i++)
    {
        //printing the coordinates before printing every row
        SetColor(11);
        printf("\t%i",i+1);
        SetColor(15);
        //because we used 32 as visited in the DFS
        for(j=0; j<m; j++)
        {
            if(A[i][j]=='P')
            {
                A[i][j]=' ';
            }

                      if(A[i][j]=='F'){
                        SetColor(12);
                    }else if(A[i][j]=='?'){
                        SetColor(14);
                    }else if(A[i][j]>='1'&&A[i][j]<='8'){
                        SetColor(9);
                    }else if(A[i][j]=='X'){
                        SetColor(7);
                    }else if(A[i][j]=='M'){
                        SetColor(4);
                    }else if(A[i][j]=='!'){
                        SetColor(12);
                    }else if(A[i][j]=='-'){
                        SetColor(13);
                    }else if(A[i][j]=='*'){
                        SetColor(13);
                    }
                       printf("\t%c",A[i][j]);
                        SetColor(15);


        }

        printf("\n\n");
         printf("\t");
        for(j=0; j<m; j++)
        {
            SetColor(3);
            printf("\t-");


        }
        SetColor(15);
        printf("\n\n");


    }
    printf("\n");


}



// a function to add 1 to all the cells around a mine
void fn_num(int B[][m],int n,int temp1,int temp2)
{

    int i,j;
    for(i=(-1); i<=1; i++)
    {
        for(j=(-1); j<=1; j++)

        {
            //checking that this cell isn't the mine cell
            if((i!=0)||(j!=0))
            {
//checking that this cell isn't another mine

                if(B[temp1+i][temp2+j]!=(-1))
                {
                    //checking if the cells around are in the range of the grid
                    if((temp1+i>=0)&&(temp1+i<n)&&(temp2+j>=0)&&(temp2+j<m))
                    {

                        B[temp1+i][temp2+j]++;
                    }
                }
            }

        }
    }



}




