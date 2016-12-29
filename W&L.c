#include "After_W.h"
#include"Array_fun.h"
#include <ctype.h>
#include <stdio.h>

void win_function(long long score,char A[][m])
{
    int i,j;
    system("cls");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
                //changing every cell left with 'F'
            if(A[i][j]=='X' || A[i][j]=='?'){
                A[i][j]='F';
            }
        }
    }
printArray(A,n);

    Print_win();

    char Name_str[20+1];
    char dummy[129];

    printf("\nyour Score : %lli\n\n ",score);
    //Asking for the player name
    printf("Enter your name :");

        getchar();
//only taking 20 char
    fgets(Name_str, 20, stdin);
    fgets(dummy, 108, stdin);
    //changing every Capital letter with small ones
for(i=0;Name_str[i]!='\0';i++){
    if(Name_str[i]>='A' && Name_str[i]<='Z'){
        Name_str[i]+=(int)'a'-(int)'A';
    }
 }

    FILE *ranks;
    //opening the ranks file
    ranks=fopen("Ranks.txt","r");
    // there no such file
    if (ranks==NULL)
    {
        ranks=fopen("Ranks.txt","w");
        //print 0 in the file after opening for the first time
        fprintf(ranks,"%i",0);
        fclose(ranks);
    }
    fclose(ranks);
    Read_Ranks(Name_str,score);


    Print_Ranks();
}



void loseFun(int X[],int Y[],int n,char A[][m],int nom)

{
    SetColor(12);
    system("cls");
        printf("\n\n\t\t\t\tGame Over \n\n");

SetColor(15);

    int i,j;
    int l,k;
// getting the mine locations for the Arrays X ,Y
    for (i=0; i<nom; i++)
    {
        l=X[i];
        k=Y[i];
        //changing every flaged mine with *

        if (A[l][k]=='F')
        {
            A[l][k]='*';
        }
        //any missed mine with M
        else if(A[l][k]!='!')
        {
            A[l][k]='M';
        }
    }
    //n rows
    //m columns
    //'-' wrong flag
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(A[i][j]=='F')
            {
                A[i][j]='-';
            }
        }
    }
    printArray(A,n);
    printf("Press Enter to return to the main menu .");
    getchar();
    getchar();

}







int win_condition(char A[][m],int n,int nom)
{
    int i,j;
    int counter=0;
    //checking the number of the remaining cells
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(A[i][j]=='X' || A[i][j]=='F' || A[i][j]=='?')
            {
                counter++;
            }
        }
    }
    if(counter==nom)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
