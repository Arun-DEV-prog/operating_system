#include <stdio.h>

void main()
{
    int buffer[10];
    int bufsize = 10;
    int in = 0, out = 0;
    int produce, consume;
    int choice = 0;

    while(choice != 3)
    {
        printf("\n1. Produce");
        printf("\n2. Consume");
        printf("\n3. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if((in + 1) % bufsize == out)
                {
                    printf("\nBuffer is Full");
                }
                else
                {
                    printf("Enter the value: ");
                    scanf("%d", &produce);

                    buffer[in] = produce;
                    in = (in + 1) % bufsize;

                    printf("Item Produced Successfully.");
                }
                break;

            case 2:
                if(in == out)
                {
                    printf("\nBuffer is Empty");
                }
                else
                {
                    consume = buffer[out];
                    printf("\nConsumed Value = %d", consume);

                    out = (out + 1) % bufsize;
                }
                break;

            case 3:
                printf("\nProgram Terminated.");
                break;

            default:
                printf("\nInvalid Choice");
        }
    }
}