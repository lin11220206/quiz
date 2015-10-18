/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX(a,b) (a>b?a:b)

int maxSubArray(int A[], int n);

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

    char line[50];
    char number[4];
    int numArray[25];
    int length = 0;
    int pNum = 0, maxNum;
    double cpu_time;
    struct timespec start, end;

    clock_gettime(CLOCK_REALTIME, &start);
    while(fgets(line, 50, fp)) {
        for(int i=0; i<50; i++) {
            if(line[i] == '\0' || line[i] == 32) {
                number[pNum] = '\0';
                numArray[length++] = atoi(number);
                pNum = 0;

                if(line[i] == '\0')
                    break;
            } else
                number[pNum++] = line[i];
        }
        maxNum = maxSubArray(numArray, length);
        //printf("%d\n", maxNum);
        length = 0;
    }
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_second(start, end);
    printf("execution time of maxSubArray(): %lf sec\n", cpu_time);


    fclose(fp);

    return 0;
}

int maxSubArray(int A[], int n)
{
    int sum = 0;
    int maxNumber = A[0];
    for(int i=0; i<n; ++i) {
        sum += A[i];
        sum = MAX(0, sum);
        maxNumber = MAX(sum, maxNumber);
    }
    return maxNumber;
}
