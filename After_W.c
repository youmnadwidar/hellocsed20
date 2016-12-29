
int n,m;

void save_fun(int countf,int countQ,int counter,int nom,int diff_t,char A[][m],int B[][m],int X[],int Y[])
{
    int i,j;
    FILE *fload;
    fload=fopen("savedgame.txt","w");

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




