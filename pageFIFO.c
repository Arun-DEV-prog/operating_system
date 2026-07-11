#include <stdio.h>
#include <conio.h>

int fr[3];

void display();

void main()
{
    int i, j;
    int page[12] = {2,3,2,1,5,2,4,5,3,2,5,2};
    int flag1 = 0, flag2 = 0;
    int pf = 0;
    int frsize = 3;
    int top = 0;

    clrscr();

    // Initialize frames
    for(i = 0; i < frsize; i++)
    {
        fr[i] = -1;
    }

    // Process each page
    for(j = 0; j < 12; j++)
    {
        flag1 = 0;
        flag2 = 0;

        // Check whether page already exists
        for(i = 0; i < frsize; i++)
        {
            if(fr[i] == page[j])
            {
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }

        // Find empty frame
        if(flag1 == 0)
        {
            for(i = 0; i < frsize; i++)
            {
                if(fr[i] == -1)
                {
                    fr[i] = page[j];
                    flag2 = 1;
                    pf++;
                    break;
                }
            }
        }

        // Replace using FIFO
        if(flag2 == 0)
        {
            fr[top] = page[j];
            top++;

            if(top >= frsize)
                top = 0;

            pf++;
        }

        printf("\nAfter Page %d :", page[j]);
        display();
    }

    printf("\n\nTotal Page Faults = %d", pf);

    getch();
}

void display()
{
    int i;

    printf("\t");

    for(i = 0; i < 3; i++)
    {
        if(fr[i] == -1)
            printf("-\t");
        else
            printf("%d\t", fr[i]);
    }
}