#include<stdio.h>

void main(){
    int ms, mp[10],i, temp,n=0;
    char ch ='y';

    printf("Enter Total Memory Availabe (bytes): ");
    scanf("%d", &ms);

    temp=ms;

    for(i=0; ch == 'y'; i++, n++){
        printf("Enter memory required for process %d ", i+1);
        scanf("%d", &mp[i]);

        if(mp[i]<temp){
             printf("Memory allocated for process %d\n", i+1);
             temp -=mp[i];
        }else{
             printf("Memory is full\n");
             break;
        }

        printf("Do yo want to continue (y/n): ");
        scanf(" %c", &ch);
    }

     printf("\n-----------------------------------------");
    printf("\nPROCESS\tMEMORY ALLOCATED");
    printf("\n-----------------------------------------");

    for(i=0;i<n;i++){
         printf("\n%d\t%d",i+1, mp[i]);
    }
    printf("\n-----------------------------------------");
    printf("\nTotal memory availabe =%d", ms);
    printf("\nTotak memory allocated =%d", ms - temp);
    printf("\nTotal External F %d", temp);

}