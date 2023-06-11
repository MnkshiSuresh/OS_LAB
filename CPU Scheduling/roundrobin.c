#include<stdio.h>

int main() {
    int n, i, j, qtime, flag = 0, remain, time;
    int at[10], bt[10], rt[10];
    int totttime = 0, totwtime = 0;
    
    printf("-----------ROUND ROBIN SCHEDULING------------\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter the arrival time and burst time of each process:\n");
    for (i = 0; i < n; i++) {
        printf("P[%d] Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("P[%d] Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }
    
    printf("Enter the quantum time: ");
    scanf("%d", &qtime);
    
    remain = n;
    for (time = 0, i = 0; remain != 0; time++) {
        if (rt[i] < qtime && rt[i] > 0) {
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        } else if (rt[i] > 0) {
            rt[i] -= qtime;
            time += qtime;
        } 
        
        if (rt[i] == 0 && flag == 1) {
            remain--;
            totwtime += time - at[i] - bt[i];
            totttime += time - at[i];
            flag = 0;
        }   
        
        if (i == n - 1) {
            i = 0;
        } else if (at[i + 1] <= time) {
            i++;
        } else {
            i = 0;
        }
    }
    
    printf("Total Waiting Time: %d\n", totwtime);
    printf("Average Waiting Time: %f\n", (float)totwtime/n);
    printf("Total Turn Around Time: %d\n", totttime);
    printf("Average Turn Around Time: %f\n", (float)totttime/n);
    
    return 0;
}
