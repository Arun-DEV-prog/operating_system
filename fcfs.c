#include <stdio.h>

int main() {
  int bt[20], wt[20], tat[20], i, n;
  float wtavg, tatavg;

// clrscr();

  printf("\nEnter the number of processes: ");
  scanf("%d", &n);

 
  for (i = 0; i < n; i++) {
    printf("Enter Burst Time for Process P%d: ", i);
    scanf("%d", &bt[i]);
  }

  
  wt[0] = 0;
  tat[0] = bt[0];

  wtavg = wt[0];
  tatavg = tat[0];

  // Calculate Waiting Time and Turnaround Time
  for (i = 1; i < n; i++) {
    wt[i] = wt[i - 1] + bt[i - 1];
    tat[i] = wt[i] + bt[i];

    wtavg += wt[i];
    tatavg += tat[i];
  }

  printf("\n------------------------------------------------------------");
  printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
  printf("\n------------------------------------------------------------");

  for (i = 0; i < n; i++) {
    printf("\nP%d\t%d\t\t%d\t\t%d", i, bt[i], wt[i], tat[i]);
  }

  printf("\n------------------------------------------------------------");
  printf("\nAverage Waiting Time = %.2f", wtavg / n);
  printf("\nAverage Turnaround Time = %.2f", tatavg / n);

// getch();
  return 0;
}