/* FIXME: Implement! */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int *getCards();

static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}


int main()
{
    double cpu_time;
    struct timespec start, end;
    int *cards;

    clock_gettime(CLOCK_REALTIME, &start);
    int count = 10000;
    srand(time(NULL));
    while(count--) {
        cards = getCards();
        /*
        for(int i=0; i<52; ++i)
            printf("%d ", cards[i]);
        printf("\n");*/
    }
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_second(start, end);

    printf("execution time of getCard(): %lf sec\n", cpu_time);

    return 0;
}

int *getCards()
{
    int *cards = malloc(sizeof(int)*52);
    int decks[52];
    int decksize = 52;

    for(int i=0; i<52; ++i)
        decks[i] = i+1;

    for(int i=0, j; i<52; ++i) {
        j = rand()%decksize;
        cards[i] = decks[j];
        decks[j] = decks[decksize-1];
        decksize--;
    }

    return cards;
}
