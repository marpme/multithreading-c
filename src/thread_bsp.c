#include <stdio.h> 
#include <pthread.h> /* POSIX-Thread-Funktionen */
#include <unistd.h>

int zeit=0; /* global Variable */

void *prog_a(void *arg)  /* Thread 1 */ 
{ 
    int i, t=1; 
    for(i=0; i<3; i++) 
    {  
        sleep(t);
        zeit=zeit+t;
        printf("%s%d: time elapsed = %d s \n",(char *)arg,i,zeit);
    } 
} 
 
void *prog_b(void *arg) /* Thread 2 */  
{ 
    int i, t=3; 
    for(i=0; i<3; i++) 
    {  
        sleep(t);
        zeit=zeit+t; 
        printf("%s%d: time elapsed = %d s \n",(char *)arg,i,zeit);
    } 
} 

int main()  {
    pthread_t id1, id2; 
    char *ch_id; 
    void *res;  

    ch_id="a_"; 
    pthread_create(&id1, NULL, prog_a, (void *)ch_id); 
    printf("Thread a: ID = %p, time-elapsed=%d s\n", (void *)id1,zeit);

    ch_id="b_"; 
    pthread_create(&id2, NULL, prog_b, (void *)ch_id); 
    printf("Thread b: ID = %p, time-elapsed=%d s\n", (void *)id2,zeit);

    pthread_join(id1, &res); /* warten auf Thread-Ende*/  
    pthread_join(id2, &res); 
 
    printf("Time = %d s \n", zeit);
} 