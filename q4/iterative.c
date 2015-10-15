/* FIXME: Implement! */
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
    int sum = 0;
    int maxNumber = A[0];
    for(int i=0; i<n; ++i) {
        sum += A[i];
        sum = MAX(0, sum);
        maxNumber = MAX(sum, maxNumber);
    }
    return maxNumber;
}
