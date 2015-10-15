/* FIXME: Implement! */
#include <stdio.h>
#include <time.h>

int *getCards();

int main()
{
    int *cards = getCards();

    for(int i=0; i<52; ++i)
        printf("%d ", cards[i]);
    printf("\n");
    return 0;
}

int *getCards()
{
    srand(time(NULL));
    int *cards = malloc(sizeof(int)*52);
    int decks[52];
    int decksize = 52;

    for(int i=0; i<52; ++i)
        decks[i] = i+1;

    for(int i=0, j; i<52; ++i) {
        j = rand()%52;
        cards[i] = decks[j];
        decks[j] = decks[decksize-1];
        decksize--;
    }

    return cards;
}
