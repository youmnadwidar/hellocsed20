#include <time.h>
#include <stdio.h>
#include "W&L.h"
extern int n,m;

void open_open(int x,int y,char A[][m],int n,int B[][m],int *l)
{
    int i,j,counter=0;
    //check number of flags=B[x][y]
    for(i=-1; i<=1; i++)
    {
        for(j=-1; j<=1; j++)
        {

            if(A[x+i][y+j]=='F')
            {
                counter++;
            }

        }
    }
    //the number of flags == the number in the cell
    if(counter==B[x][y])
    {
        for(i=-1; i<=1; i++)
        {
            for(j=-1; j<=1; j++)
            {
                //checking if it's in the range of the grid size
                if((x+i>=0)&&(x+i<n)&&(y+j>=0)&&(y+j<m))
                {
                    //only open the X of ? cells
                    if ((A[x+i][y+j]=='X')||A[x+i][y+j]=='?')
                    {
//means B have a number
                        if(B[x+i][y+j]>0&&B[x+i][y+j]<=8)

                        {
                            A[x+i][y+j]=B[x+i][y+j]+'0';
                        }
                        //empty cell
                        else if (B[x+i][y+j]==0)
                        {
                            open_DFS(x+i,y+j,A,n,B);
                        }
                        //mine
                        else if(B[x+i][y+j]==(-1))
                        {
                            A[x+i][y+j]='!';
                            *l = 1;

                        }
                    }
                }
            }



        }
    }
}



int open_DFS(int x,int y,char A[][m],int n,int B[][m]){
//make the first cell space
    A[x][y]=' ';
    int i,j;
    for(i=-1;i<=1;i++){
        for(j=-1;j<=1;j++){
            if((x+i>=0)&&(x+i<n)&&(y+j>=0)&&(y+j<m)){
                    //making sure it isn't the mine first opened cell and not opened before
                    if(((i!=0)||(j!=0))&&(A[x+i][y+j]=='X')){
                if(B[x+i][y+j]==0)
                {
                    //32 means visited
                        B[x+i][y+j]=32;
                    open_DFS(x+i,y+j,A,n,B);
            //getting the value of the cell
                }else if (B[x+i][y+j]>0&& B[x+i][y+j]<=8){
                    A[x+i][y+j]=B[x+i][y+j]+'0';
                }
            }
            }
        }

    }

}


void save_fun(int countf,int countQ,int counter,int nom,int diff_t,char A[][m],int B[][m],int X[],int Y[])
{
    int i,j;
    FILE *fload;
    fload=fopen("savedgame.txt","w");
    //printing what we need to reload the gamed

    fprintf(fload,"%d %d\n",n,m);
    fprintf(fload,"%d\n%d\n%d\n%d\n",counter,countf,countQ,nom);
    fprintf(fload,"%d\n",diff_t);
    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            fprintf(fload,"%d ",A[i][j]);
        }
        fprintf(fload,"\n");
    }

    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            fprintf(fload,"%d ",B[i][j]);
        }
        fprintf(fload,"\n");
    }

    for (j=0; j<nom; j++)
    {
        fprintf(fload,"%d ",X[j]);
    }
    fprintf(fload,"\n");
    for (j=0; j<nom; j++)
    {
        fprintf(fload,"%d ",Y[j]);
    }

    fclose(fload);



}



