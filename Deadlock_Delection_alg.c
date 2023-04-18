#include <stdio.h>

int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n, r;

void input();
void show();
void cal();

int main() 
{
    printf("Deadlock Detection Algo\n");
    input();
    show();
    cal();
    return 0;
}

void input()
{
    printf("Enter the no of processes: ");
    scanf("%d", &n);
    printf("Enter the no of resource instances: ");
    scanf("%d", &r);

    printf("Enter the Max Matrix\n");
    for(int i=0; i<n; i++)
        for(int j=0; j<r; j++)
            scanf("%d", &max[i][j]);

    printf("Enter the Allocation Matrix\n");
    for(int i=0; i<n; i++)
        for(int j=0; j<r; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter the Available Resources\n");
    for(int j=0; j<r; j++)
        scanf("%d", &avail[j]);
}

void show()
{
    printf("Process\tAllocation\tMax\tAvailable\n");
    for(int i=0; i<n; i++)
    {
        printf("%d\t", i);
        for(int j=0; j<r; j++)
            printf("%d ", alloc[i][j]);
        printf("\t");
        for(int j=0; j<r; j++)
            printf("%d ", max[i][j]);
        printf("\t");
        if(i==0)
        {
            for(int j=0; j<r; j++)
                printf("%d ", avail[j]);
        }
        printf("\n");
    }
}

void cal()
{
    int finish[100], dead[100];
    int temp, flag=1, k=0, cl=0;

    for(int i=0; i<n; i++)
        finish[i] = 0;

    // find need matrix
    for(int i=0; i<n; i++)
        for(int j=0; j<r; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    while(flag)
    {
        flag = 0;
        for(int i=0; i<n; i++)
        {
            int c = 0;
            for(int j=0; j<r; j++)
            {
                if((finish[i] == 0) && (need[i][j] <= avail[j]))
                {
                    c++;
                    if(c == r)
                    {
                        for(k=0; k<r; k++)
                            avail[k] += alloc[i][k];
                        finish[i] = 1;
                        flag = 1;
                    }
                }
            }
        }
    }

    int j = 0;
    for(int i=0; i<n; i++)
        if(finish[i] == 0)
            dead[j++] = i;

    if(j != 0)
    {
        printf("\n\nSystem is in Deadlock and the Deadlock process are: ");
        for(int i=0; i<j; i++)
            printf("%d ", dead[i]);
    }
    else
        printf("\nNo Deadlock Occurs");
}