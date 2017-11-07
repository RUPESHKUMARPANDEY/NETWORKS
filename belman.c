#include<stdio.h>

struct node{
int from[20];
int dist[20];
}rt[10];

int main()
{
int costmat[10][10],nodes,i,j,k,count=0;

printf("Enter number of nodes\n");
scanf("%d",&nodes);
printf("Enter the cost matrix\n");
for(i=0;i<nodes;i++)
{
for(j=0;j<nodes;j++)
{
scanf("%d",&costmat[i][j]);
costmat[i][i]=0;
rt[i].dist[j]=costmat[i][j];
rt[i].from[j]=j;
}
}

do
{
count=0;
for(i=0;i<nodes;i++)
{
for(j=0;j<nodes;j++)
{
for(k=0;k<nodes;k++)
{
if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])
{
rt[i].dist[j]=costmat[i][k]+rt[k].dist[j];
rt[i].from[j]=k;
count++;
}
}
}
}
}while(count!=0);

for(i=0;i<nodes;i++)
{
printf("\n\nFor router %d\n\n",i+1);
for(j=0;j<nodes;j++)
{
printf("node %d via %d Distance %d\n",j+1,rt[i].from[j]+1,rt[i].dist[j]);
}
}
return 0;
}
