#include "search.h"

float Line_max(float *line)
{
    int k_max = 0;
    int j;
    for (j = 0; j < COL; j++)
    {
        if (*(line + j) > *(line + k_max))
        {
            k_max = j;
        }
    }
    return (*(line + k_max));
}

void Col_min(float (*arr)[COL])
{
    float arr_min;
    int i, j;
    for (i = 0; i < COL; i++)
    {
        arr_min = *((arr) + i);
        for (j = 0; j < LINE; j++)
        {
            if (*(*(arr + j) + i) < arr_min)
            {
                arr_min = *(*(arr + j) + i);
            }
        }
        printf("minimum in column %d: %f\n", i, arr_min);
    }
}

void *Search(void *v)
{
    int i;
    float arr[LINE][COL];
    mqd_t mq;
    struct mq_attr attr;

    // atributes
    attr.mq_flags = 0;
    attr.mq_maxmsg = LINE;
    attr.mq_msgsize = sizeof(float) * COL;
    attr.mq_curmsgs = 0;

    // create message queue
    mq = mq_open(MQ_NAME, O_CREATE | O_RDONLY, 0666, &attr);
    if (mq == (mqd_t)-1)
    {
        perror("mq_open consumer");
    }
    while (1)
    {
        for (i = 0; i < LINE; i++)
        {
            if (mq_receive(mq, (char *)(arr + i), sizeof(arr), NULL) == -1)
            {
                perror("mq_receive");
            }
            printf("maximum in line %d: %f\n", i, Line_max(*(arr + i)));
        }
        pthread_mutex_lock(&m);
        Col_min(arr);
        pthread_mutex_unlock(&m);
    }
    mq_close(mq);
    mq_unlink(MQ_NAME);
}