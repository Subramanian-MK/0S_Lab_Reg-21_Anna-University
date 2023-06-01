#include<stdio.h>
struct process {
    int pid;
    int btime;
    int wtime;
    int ttime;
} p[10], temp;
int main() {
    int i, j, k, n, ttur, twat;
    float awat, atur;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Burst time for process P%d (in ms): ", (i + 1));
        scanf("%d", &p[i].btime);
        p[i].pid = i + 1;
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if ((p[i].btime > p[j].btime) || (p[i].btime == p[j].btime && p[i].pid > p[j].pid)) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    p[0].wtime = 0;
    for (i = 0; i < n; i++) {
        p[i + 1].wtime = p[i].wtime + p[i].btime;
        p[i].ttime = p[i].wtime + p[i].btime;
    }
    ttur = twat = 0;
    for (i = 0; i < n; i++) {
        ttur += p[i].ttime;
        twat += p[i].wtime;
    }
    awat = (float) twat / n;
    atur = (float) ttur / n;
    printf("\nSJF Scheduling\n\n");
    for (i = 0; i < 28; i++)
        printf("-");
    printf("\nProcess\tB-time\tT-time\tW-time\n");
    printf("\n0");
    for (i = 0; i < n; i++) {
        for (j = 0; j < p[i].btime; j++)
            printf(" ");
        printf("%2d", p[i].ttime);
    }
    return 0;
}
