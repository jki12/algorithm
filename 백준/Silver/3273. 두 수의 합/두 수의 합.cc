#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

using namespace std;
typedef unsigned int uint;

int main(void)
{
    uint n, x;
    uint arr[1000000] = { 0, };
    uint ans = 0;

    scanf("%d", &n);
    
    uint* nums = (uint*)malloc(n * sizeof(uint));
    for (int i = 0; i < n; ++i) {
        int temp;
        scanf("%d", &temp);

        nums[i] = temp;
        arr[temp - 1]++;
    }

    scanf("%d", &x);
    
    for (int i = 0; i < n; ++i) {
        // assert(0 <= x - nums[i] - 1 && x - nums[i] - 1 < 1000000);
        if (0 < x - nums[i] && x - nums[i] <= 1000000 && arr[x - nums[i] - 1] == 1) {
            ans++;
        }
    }

    printf("%d", ans / 2);

    free(nums);
    return 0;
}