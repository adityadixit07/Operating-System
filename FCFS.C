// program to implement FCFS problem on c
#include <conio.h>
#include <stdio.h>
void main()
{
    int p[10], i, j, n, b[10], a[10], w[10], tt[10], bt[10], temp, count = 0;
    float avgw = 0, avgt = 0;
    // clrscr();
    printf("\nenter the number of processes u want:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        p[i] = count;
        count++;
    }
    printf("\n\nenter the arrival time of processes:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("\n\nenter the burst time of processes:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if ((j + 1) == n)
                break;

            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;

                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    w[0] = 0;
    bt[0] = b[0];

    for (i = 1; i < n; i++)
        bt[i] = b[i] + bt[i - 1];

    for (i = 1; i < n; i++)
        w[i] = bt[i - 1] - a[i];

    for (i = 0; i < n; i++)
        tt[i] = w[i] + b[i];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if ((j + 1) == n)
                break;

            if (p[j] > p[j + 1])
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;

                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;

                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                temp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp;

                temp = tt[j];
                tt[j] = tt[j + 1];
                tt[j + 1] = temp;
            }
        }
    }

    printf("\nThe problem is:\n");
    printf("   P  AT  BT  WT  TT \n");
    for (i = 0; i < n; i++)
    {
        printf("%4d%4d%4d%4d%4d\n", p[i], a[i], b[i], w[i], tt[i]);
    }
    for (i = 0; i < n; i++)
    {
        avgw = avgw + w[i];
        avgt = avgt + tt[i];
    }
    avgw = avgw / n;
    avgt = avgt / n;
    printf("\naverage WT=%f  average TT=%f\n", avgw, avgt);
    getch();
}
