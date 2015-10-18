/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char smallest_character(char str[], char c);

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
    FILE *fp;
    fp = fopen("testFile.txt", "r");
    if(fp == NULL) {
        printf("cannot open the file");
        return -1;
    }
    double cpu_time;
    struct timespec start, end;

    char line[50];
    int i = 0;

    char str[48], c;
    clock_gettime(CLOCK_REALTIME, &start);
    while(fgets(line, 50, fp)) {
        while(line[i] != 32) {
            str[i] = line[i];
            i++;
        }
        str[i] = '\0';
        c = line[i+1];
        c = smallest_character(str, c);
        printf("%c\n", c);
        i=0;
    }
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_second(start, end);
    printf("execution time of smallest_character(): %lf sec\n", cpu_time);
    fclose(fp);

    return 0;
}

char smallest_character(char str[], char c)
{
    char nextChar;

    if(str[0] == '\0')	return 0;

    if(str[0] > c)
        return str[0];
    else {
        nextChar = smallest_character(str+1, c);
        if(nextChar <= c)
            return str[0];

        return nextChar;
    }
}
