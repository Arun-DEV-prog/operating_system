#include<stdio.h>

void main(){
     int i, j, n;

     int bu[10],wa[10],tat[10],ct[10];
     int t, max;
     float awt=0,att=0, temp=0;


     printf("Enter tthe number of process:  __");
     scanf("%d",&n);

     for(i=0;i<n;i++){
         printf("Enter the number of process P%d",i+1);
         scanf("%d",&bu[i]);
         ct[i]=bu[i];
     }

     printf("\nEnter the Time Quantam: ");

     scanf("%d",&t);

     max=bu[0];

      for(i=1;i<n;i++){
         if(max<bu[i])
             max=bu[i];
      }

      
      for(j=0; j<(max/t)+1; j++){
          for(i=0;i<n;i++){
              if(bu[i] !=0 ){
                  if(bu[i] <=t){
                     temp =temp + bu[i];
                      tat[i]=temp;
                      bu[i]=0;
                  }else{
                     bu[i]=bu[i]-t;
                     temp +=t;
                  }
              }
          }
      }

       for(i = 0; i < n; i++)
    {
        wa[i] = tat[i] - ct[i];
        awt += wa[i];
        att += tat[i];
    }


        printf("\n-------------------------------------------------------------");
    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
    printf("\n-------------------------------------------------------------");

    for(i = 0; i < n; i++)
    {
        printf("\nP%d\t%d\t\t%d\t\t%d",
               i + 1, ct[i], wa[i], tat[i]);
    }

    printf("\n-------------------------------------------------------------");
    printf("\nAverage Waiting Time = %.2f", awt / n);
    printf("\nAverage Turnaround Time = %.2f", att / n);


}