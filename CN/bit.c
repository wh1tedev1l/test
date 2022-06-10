#include<stdio.h>
#include<string.h>
int main()
{
	int a[20],b[20],i,j,k,count,n;
	printf("Enter frame length:\n");
	scanf("%d",&n);
	printf("Enter input frame (0's & 1's only):\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	i=0;count=1;j=0;
	while(i<n)
	{
		if(a[i]==1)
		{
			b[j]=a[i];
			for(k=i+1;a[k]==1 && k<n && count<5;k++)
			{
				j++;
				b[j]=a[k];
				count++;
				if(count==5)
				{
					j++;
					b[j]=0;
				}
				i=k;
			}
		}
		else
			b[j]=a[i];
		i++;
		j++;
	}
	printf("After stuffing the frame is:\n");
	for(i=0;i<j;i++)
		printf("%d\n",b[i]);
	return 0;
}
