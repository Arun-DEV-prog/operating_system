#include<stdio.h>


void main()
{
    int p[20], bt[20], pri[20], wt[20], tat[20];
    int i, k, n, temp;
    float wtavg, tatavg;


    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input Burst Time and Priority
    for(i = 0; i < n; i++)
    {
        p[i] = i + 1;

        printf("\nEnter Burst Time and Priority for Process P%d: ", i + 1);
        scanf("%d%d", &bt[i], &pri[i]);
    }

    // Sort according to Priority (Smaller number = Higher Priority)
    for(i = 0; i < n - 1; i++)
    {
        for(k = i + 1; k < n; k++)
        {
            if(pri[i] > pri[k])
            {
                // Swap Process
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;

                // Swap Burst Time
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                // Swap Priority
                temp = pri[i];
                pri[i] = pri[k];
                pri[k] = temp;
            }
        }
    }

    // Waiting Time and Turnaround Time
    wt[0] = 0;
    tat[0] = bt[0];

    wtavg = wt[0];
    tatavg = tat[0];

    for(i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];

        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\n---------------------------------------------------------------");
    printf("\nPROCESS\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
    printf("\n---------------------------------------------------------------");

    for(i = 0; i < n; i++)
    {
        printf("\nP%d\t%d\t\t%d\t\t%d\t\t%d",
               p[i], pri[i], bt[i], wt[i], tat[i]);
    }

    printf("\n---------------------------------------------------------------");
    printf("\nAverage Waiting Time = %.2f", wtavg / n);
    printf("\nAverage Turnaround Time = %.2f", tatavg / n);

    
}