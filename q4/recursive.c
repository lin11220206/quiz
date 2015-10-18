#include <stdio.h>

#define MAX(a,b) (a>b?a:b)

int maxSubArray(int A[], int n);

int main()
{
    int a[10] = {-2,1,-1,4,-1,2,1,-5,4};
    printf("%d\n", maxSubArray(a, 10));
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
