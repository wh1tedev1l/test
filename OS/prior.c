#include<stdio.h>
void main(){
        int i,j,pno[10],prior[10],bt[10],n,wt[10],tt[10],t1=0,w1=0,s;
        float aw,at;
        printf("\nenter the no. of process: ");
        scanf("%d",&n);
        for(i=0;i<n;i++){
                printf("the process %d: \n",i+1);
                printf("enter the burst time no: ");
                scanf("%d",&bt[i]);
                printf("\nenter the priority of process %d: ",i+1);
                scanf("%d",&prior[i]);
                pno[i]=i+1;
        }
        for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                        if (prior[i] < prior[j]){
                                s=prior[i];
                                prior[i]=prior[j];
                                prior[j]=s;
                                s=bt[i];
                                bt[i]=bt[j];
                                bt[j]=s;
                                s=prior[i];
                                pno[i]=pno[j];
                                pno[j]=s;
                        }
                }
        }
        for(i=0;i<n;i++){
                wt[0]=0;
                tt[0]=bt[0];
                wt[i+1]=bt[i]+wt[i];
                tt[i+1]=tt[i]+bt[i+1];
                w1+=wt[i];
                t1+=tt[i];
                aw=w1/n;
                at=t1/n;
        }
        printf("\n job  \t bt \t wt \t at \t prior \n");
        for(i=0;i<n;i++)
                printf("%d  \t %d \t %d \t %d \t %d \n",pno[i],bt[i],wt[i],tt[i],prior[i]);
                printf("\n aw=%f \t at=%f",aw,at);
}
