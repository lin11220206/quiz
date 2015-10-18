#include <stdio.h>

#define MAX(a,b) (a>b?a:b)

int maxSubArray(int A[], int n);

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
    int pNum = 0;

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

        printf("%d\n", maxSubArray(numArray, length));
        length = 0;
    }

    fclose(fp);
    return 0;
}

int maxSubArray(int A[], int n)
{
    int maxSubArraySum(int A[], int n, int maxNumber, int sum) {
        if(n == 0)
            return maxNumber;
        sum += A[0];
        sum = MAX(0, sum);
        maxNumber = MAX(sum, maxNumber);

        return maxSubArraySum(A+1, n-1, maxNumber, sum);
    }

    maxSubArraySum(A, n, A[0], 0);
}
