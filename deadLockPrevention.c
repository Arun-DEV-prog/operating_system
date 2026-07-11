#include<stdio.h>


void main()
{
    char job[10][10];
    int time[10], avail;
    int tem[10], temp[10];
    int safe[10];
    int ind = 0;
    int i, j, q, n, t;

    

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter Job Name and Resource Needed: ");
        scanf("%s%d", job[i], &time[i]);
    }

    printf("Enter Available Resources: ");
    scanf("%d", &avail);

    // Copy arrays
    for(i = 0; i < n; i++)
    {
        temp[i] = time[i];
        tem[i] = i;
    }

    // Sort according to resource requirement
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(temp[i] > temp[j])
            {
                t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;

                t = tem[i];
                tem[i] = tem[j];
                tem[j] = t;
            }
        }
    }

    // Find Safe Sequence
    for(i = 0; i < n; i++)
    {
        q = tem[i];

        if(time[q] <= avail)
        {
            safe[ind] = q;
            avail = avail - time[q];
            ind++;
        }
        else
        {
            printf("\nNo Safe Sequence Exists.\n");
            break;
        }
    }

    if(ind == n)
    {
        printf("\nSafe Sequence:\n");

        for(i = 0; i < ind; i++)
        {
            printf("%s (%d)", job[safe[i]], time[safe[i]]);

            if(i != ind - 1)
                printf(" -> ");
        }
    }

    
}