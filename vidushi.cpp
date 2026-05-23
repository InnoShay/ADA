#include<stdio.h>
void main()
{
int alloc[10][10], max[10][10], need[10][10];
int avail[10], work[10];
int finish[10], safe[10];
int n, m, i, j, k = 0, flag;
clrscr();
printf("Enter number of processes: ");
scanf("%d",&n);
printf("Enter number of resources: ");
scanf("%d",&m);
printf("\nEnter Allocation Matrix:\n");
for(i=0;i<n;i++)
for(j=0;j<m;j++)
scanf("%d",&alloc[i][j]);
printf("\nEnter Max Matrix:\n");
for(i=0;i<n;i++)
for(j=0;j<m;j++)
scanf("%d",&max[i][j]);
printf("\nEnter Available Resources:\n");
for(j=0;j<m;j++)
scanf("%d",&avail[j]);
for(i=0;i<n;i++)
for(j=0;j<m;j++)
need[i][j] = max[i][j] - alloc[i][j];
for(j=0;j<m;j++)
work[j] = avail[j];
for(i=0;i<n;i++)
finish[i] = 0;
for(i=0;i<n;i++)
{
flag = 0;
for(j=0;j<n;j++)
{
if(finish[j] == 0)
{
for(int r=0;r<m;r++)
{
if(need[j][r] > work[r])
break;
if(r == m-1)
{
for(int r2=0;r2<m;r2++)
work[r2] += alloc[j][r2];
finish[j] = 1;
safe[k++] = j;
flag = 1;
}
}
}
}
if(flag == 0)
break;
}
if(k == n)
{
printf("\nSystem is in SAFE state\nSafe Sequence:\n");
for(i=0;i<n;i++)
printf("P%d ", safe[i]);
}
else
getch();
printf("\nSystem is NOT in safe state");
}