
#include <stdio.h>


typedef struct
{

    char Name[20+1];
    long long Score ;

} Player;

void Read_Ranks(char Name_curr[],long long score_curr )
{
    int i, Num_players,flag_usedN=0,index=-1;
    int flag_min_score=0;

    FILE *ranks;
    ranks=fopen("Ranks.txt","r");
    //getting the num of players to make an array with this size
    fscanf(ranks,"%d\n",&Num_players);
    //Array of structures
    Player Arr_ranks[Num_players];
    for(i=0; i<Num_players; i++)
    {
        //scaning from the file the saved scores
        fscanf(ranks,"%s\n",&Arr_ranks[i].Name);
                fscanf(ranks,"%lli\n",&Arr_ranks[i].Score);
//checking if the current user name is already exist in the saved names
        if(strcmp(Arr_ranks[i].Name,Name_curr)==0)
        {
            //if yes save the index and get the higher score of the two
            flag_usedN=1;
            index=i;
            if (Arr_ranks[i].Score>score_curr)
            {
                score_curr=Arr_ranks[i].Score;
            }
        }
    }
    fclose(ranks);
    ranks=fopen("Ranks.txt","w");
        i=0;
//the name used before
    if (flag_usedN)
    {
        fprintf(ranks,"%d\n",Num_players);
    }
    //the name not used before
    else
    {


        fprintf(ranks,"%d\n",Num_players+1);


    }

//sorting the scores
    while(i<Num_players&&!flag_min_score)
    {
        //the i is not the index of the used before named
        if(i!=index)
        {
       if(Arr_ranks[i].Score<score_curr)
        {
            fprintf(ranks,"%s\n",Name_curr);
            fprintf(ranks,"%lli\n",score_curr);

            flag_min_score=1;
        }
        else
        {
            fprintf(ranks,"%s\n",Arr_ranks[i].Name);
            fprintf(ranks,"%lli\n",Arr_ranks[i].Score);
            i++;
        }
        }
        else {
            i++;
        }

    }
    //the current score is the min
    if(i==Num_players&&!flag_min_score)
    {
        fprintf(ranks,"%s\n",Name_curr);
        fprintf(ranks,"%lli\n",score_curr);
    }
    //he printed the current score but not yet the rest of the Array
    while(i<Num_players)
    {
        fprintf(ranks,"%s\n",Arr_ranks[i].Name);
        fprintf(ranks,"%lli\n",Arr_ranks[i].Score);
        i++;
    }


    fclose(ranks);
}



void Print_Ranks(){

int i;
FILE * ranks;
ranks=fopen("Ranks.txt","r");
int Num_players;
//reading the num of playes with scores
fscanf(ranks,"%i\n",&Num_players);

Player display_Arr[Num_players];

    for(i=0;i<Num_players;i++){
//reading all the scores

    fscanf(ranks,"%s\n",&display_Arr[i].Name);
    fscanf(ranks,"%lli\n",&display_Arr[i].Score);
 }
    fclose(ranks);
    SetColor(11);
    printf("     Name  ");

    printf("\t\t\tScore\n\n");
    SetColor(15);
//printing every name with his score sorted
    for (i=0;i<Num_players;i++){

printf("%i - ",i+1);
SetColor(9);
 printf("%s\n",display_Arr[i].Name);
 SetColor(13);

printf("\t\t\t\t%li\n\n",display_Arr[i].Score);
    SetColor(15);

    }

    printf("Press Enter to return to the main menu .");
    getchar();
    getchar();




}





