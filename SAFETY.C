// program to implement BANKER'S  algorithm (safety algorithm)
#include <conio.h>
#include <stdio.h>
int p[10], max1[10], max2[10], max3[10], all1[10], all2[10], all3[10], need1[10], need2[10], need3[10], count = 0, avail1, avail2, avail3, seq[10];
char finish[10];
void main()
{
    int flag = 0, i, j, k, n;
    clrscr();
    printf("\nenter the number of process:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        p[i] = count;
        finish[i] = 'F';
        count++;
    }
    printf("\nenter the allocation of each process:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d", &all1[i], &all2[i], &all3[i]);
    }

    printf("\nenter the maximum need of each process:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d", &max1[i], &max2[i], &max3[i]);
    }

    printf("\nenter the available resources:\n");
    scanf("%d%d%d", &avail1, &avail2, &avail3);

    for (i = 0; i < n; i++)
    {
        need1[i] = max1[i] - all1[i];
        need2[i] = max2[i] - all2[i];
        need3[i] = max3[i] - all3[i];
    }

    printf("\nTHE TABLE IS:\n");
    printf("\nprocess  allocation  maximum  need  available\n");
    for (i = 0; i < n; i++)
    {
        printf("%5d%6d %d %d%7d %d %d%5d %d %d%4d %d %d\n", p[i], all1[i], all2[i], all3[i], max1[i], max2[i], max3[i], need1[i], need2[i], need3[i], avail1, avail2, avail3);
    }

    k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (avail1 >= need1[j] && avail2 >= need2[j] && avail3 >= need3[j] && finish[j] == 'F')
            {
                finish[j] = 'T';
                seq[k] = j;
                avail1 = avail1 + all1[j];
                avail2 = avail2 + all2[j];
                avail3 = avail3 + all3[j];
                k++;
            }
        }
    }

    if (k == n)
    {
        printf("\nthe safe sequence is:\n");
        for (i = 0; i < n; i++)
            printf("%d ", seq[i]);
    }
    else
        printf("\nthe system is in deadlock state\n");
    getch();
}
