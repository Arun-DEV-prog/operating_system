#include<stdio.h>


void main()
{
    int ms, bs, nob, ef, n;
    int mp[10];
    int tif = 0;
    int i, p = 0;

 

    printf("Enter the Total Memory Available (Bytes): ");
    scanf("%d", &ms);

    printf("Enter the Block Size (Bytes): ");
    scanf("%d", &bs);

    nob = ms / bs;              // Number of memory blocks
    ef = ms - (nob * bs);       // External Fragmentation

    printf("Enter the Number of Processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter Memory Required for Process %d: ", i + 1);
        scanf("%d", &mp[i]);
    }

    printf("\nNumber of Blocks Available = %d\n", nob);

    printf("\n--------------------------------------------------------------");
    printf("\nPROCESS\tMEMORY REQUIRED\tALLOCATED\tINTERNAL FRAGMENT");
    printf("\n--------------------------------------------------------------");

    for(i = 0; i < n && p < nob; i++)
    {
        printf("\nP%d\t%d\t\t", i + 1, mp[i]);

        if(mp[i] > bs)
        {
            printf("NO\t\t---");
        }
        else
        {
            printf("YES\t\t%d", bs - mp[i]);
            tif = tif + (bs - mp[i]);
            p++;
        }
    }

    if(i < n)
    {
        printf("\n\nMemory is Full. Remaining Processes Cannot be Allocated.");
    }

    printf("\n\nTotal Internal Fragmentation = %d", tif);
    printf("\nTotal External Fragmentation = %d", ef);

    
}