#include <pthread.h>
#include <stdio.h>
#include <time.h>

/* this function is run by the second thread */
void *thread(int *flag)
{
    int D=0,i=0;
    time_t start,R;
        i=0;
    while(*flag){
    time(&start);
    //counting to 60 seconds
    while((D)<60 && *flag){
        time(&R);

        D=R-start;
    };
    i++;
    if(D==60){printf(" %d minute passed\n",i);}
    D=0;
    }
return NULL;

}
