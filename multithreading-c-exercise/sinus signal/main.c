#include "sinus_includes.h"

int main()
{
    pthread_t gen_thr, t_thr;
    pthread_mutex_init(&m, NULL);
    sem_init(&sem, 0, 0);
    pthread_create(&gen_thr, NULL, Generate_Signal, 0);
    pthread_create(&t_thr, NULL, Transform_Signal, 0);
    pthread_join(gen_thr, NULL);
    pthread_join(t_thr, NULL);
    pthread_mutex_destroy(&m);
    sem_destroy(&sem);
}
// gcc main.c generatesignal.c transformsignal.c global.c -o main -lm -lfftw3 -lpthread
