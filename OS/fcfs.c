#include<stdio.h>
void main()
{
	int i,j,bt[10],n,wt[10],tt[10],w1=0,t1=0;
	float aw,at;
	printf("Enter no:of processes:\n");
	scanf("%d",&n);
	printf("Enter the burst time of processes:\n");
	for(i=0;i<n;i++)
		scanf("%d",&bt[i]);
	for(i=0;i<n;i++)
	{
		wt[0]=0;
		tt[0]=bt[0];
		wt[i+1]=bt[i]+wt[i];
		tt[i+1]=tt[i]+bt[i+1];
		w1=w1+wt[i];
		t1=t1+tt[i];
	}
	aw=w1/n;
	at=t1/n;
	printf("\nbt \t wt \t tt \n");
	for(i=0;i<n;i++)
		printf("%d\t%d\t%d\n",bt[i],wt[i],tt[i]);
		printf("aw=%f\n,at=%f\n",aw,at);
}

