#ifndef MINE_FUN_H_INCLUDED
#define MINE_FUN_H_INCLUDED



#endif // MINE_FUN_H_INCLUDED
int n,m;//necessary

//delete
void printB(int B[ ][m],int n)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }
    printf("\n");
} //checking

//fn of numbers around the mines
void fn_num(int B[][m],int n,int temp1,int temp2)
{
    int i,j;
    for(i=(-1); i<=1; i++)
    {
        for(j=(-1); j<=1; j++)
        {
            if((i!=0)||(j!=0))
            {
                if(B[temp1+i][temp2+j]!=(-1))
                {
                    if((temp1+i>=0)&&(temp1+i<n)&&(temp2+j>=0)&&(temp2+j<m))
                    {

                        B[temp1+i][temp2+j]++;
                    }
                }
            }
            printB(B,n);
        }
    }
}
