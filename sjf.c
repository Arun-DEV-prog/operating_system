#include<stdio.h>


void main(){
    int p[20],bt[20],wt[20],tat[20];
    int i,k,n,temp;
    float wtavg,tatavg;

     
    printf("\nEnter the number of process: ");
     scanf("%d",&n);

     for(int i=0;i<n;i++){
         p[i]=i;
          printf("Enter Burst time for process %d",i);
          scanf("%d", &bt[i]);
     }
      
     for(i=0;i<n;i++){
         for(k=i+1; k<n;k++){
             if(bt[i]>bt[k]){
                
                 temp=bt[i];
                 bt[i]=bt[k];
                 bt[k]=temp;

                 temp=p[i];
                 p[i]=p[k];
                 p[k]=temp;
             }
         }
     }

     wt[0]=0;
     tat[0]=bt[0];

     wtavg=wt[0];
     tatavg=tat[0];

     for(i=1;i<n;i++){
         wt[i]=wt[i-1]+bt[i-1];
         tat[i]=wt[i]+bt[i];

         wtavg +=wt[i];
         tatavg +=tat[i];
     }

      printf("\n-------------------------------------------------------------");
    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
    printf("\n-------------------------------------------------------------");



     for(i = 0; i < n; i++)
    {
        printf("\nP%d\t%d\t\t%d\t\t%d",
               p[i], bt[i], wt[i], tat[i]);
    }

    printf("\n-------------------------------------------------------------");
    printf("\nAverage Waiting Time = %.2f", wtavg / n);
    printf("\nAverage Turnaround Time = %.2f", tatavg / n);
}