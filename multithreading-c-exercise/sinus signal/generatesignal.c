#include "generatesignal.h"

void *Generate_Signal(void *s)
{
    int i;
    struct timespec tw = {0, 2133333};
    int t = 0;
    while (1)
    {
        // pthread_mutex_lock(&m);
        // printf("%s mutex lock %d\n", __func__, sem);
        for (i = 0; i < S_SIZE; i++, t++)
        {
            signal[i] = A * sin((2 * 3.14 * FREQ / FREQ_D) * t);
            // printf("generated signal (%d; %f)\n", t, signal[i]);
        }
        // pthread_mutex_unlock(&m);
        sem_post(&sem);
        // sleep(1);
        nanosleep(&tw, NULL);
    }
}
