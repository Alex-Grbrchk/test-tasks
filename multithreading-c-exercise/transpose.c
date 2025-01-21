#include "transpose.h"

void *Transpose(void *v)
{
    int i.j;
    void *_addr;
    int _shmid;
    float a[LINE][COL];
    float b[COL][LINE];

    if ((_shmid = shmget((key_t)SHM_KEY, sizeof(a), 066)) == -1)
    {
        perror("shmget receive");
        exit(-1);
    }
    if ((_addr = shmat(_shmid, NULL, 0)) == (void *)-1)
    {
        perror("shmat receive");
        exit(-1);
    }
    while (1)
    {
        sem_wait(&sem);
        memcpy(a, _addr, sizeof(a));
        for (i = 0; i < COL; i++)
        {
            for (j = 0; j < LINE; j++)
            {
                *(*(b + i) + j) = *(*(a + j) + i);
            }
        }
        pthread_mutex_lock(&m);
        printf("\n");
        for (i = 0; i < COL; i++)
        {
            for (j = 0; j < LINE; j++)
            {
                printf("%.4f", *(*(b + i) + j));
            }
            printf("\n");
        }
        printf("\n");
        pthread_mutex_unlock(&m);
    }
    shmdt(_addr);
    return NULL;
}