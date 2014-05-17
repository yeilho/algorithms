// zigzag problem in DP
#include <stdio.h>
#include <iostream>

int zigzag(int list[], int n)
{
    int *longest = new int[n];
    int *prev = new int[n];
    int max, k;

    longest[0] = 1;
    prev[0] = 0;

    for (int i = 1; i < n; i++) {
        max = 0;
        for (int j = 0; j < i; j++) {
            if (prev[j] > 0) {
                if ((list[i] - list[j]) < 0) {
                    if (max < (longest[j] + 1)) {
                        max = longest[j] + 1;
                        k = j;
                    }
                }
            } else if (prev[j] < 0) {
                if ((list[i] - list[j]) > 0) {
                    if (max < (longest[j] + 1)) {
                        max = longest[j] + 1;
                        k = j;
                    }
                }
            }
        }
        if (max == 0) {
            longest[i] = 2;
            prev[i] = ((list[i] - list[i - 1]) > 0) ? 1 : -1;
        } else {
            longest[i] = max;
            prev[i] = ((list[i] - list[k]) > 0) ? 1 : -1;
        }        
    }

    max = 1;
    for (int i = 0; i < n; i++)
    {
        if (max < longest[i]) {
            max = longest[i];
        }
    }
    delete[] longest;
    delete[] prev;

    return max;
}

int main(int argc, char *argv[])
{
    int list[] = { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 };

    printf("zigzag: %d\n", zigzag(list, 19));
    return 0;
}
