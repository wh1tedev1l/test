#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
int main()
{
	int i,sd,n,port;
	char sendmsg[100],recvmsg[100];
	struct sockaddr_in servaddr;
	printf("Enter the port\n");
	scanf("%d",&port);
	sd=socket(AF_INET,SOCK_STREAM,0);
	if(sd<0)
		printf("cant create\n");
	else
		printf("socket created\n");
        servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(port);
	if(connect(sd,(struct sockaddr*)&servaddr,sizeof(servaddr)<0))
		printf("canot create");
	else
		printf("socket is created\n");
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(port);
	if(connect(sd,(struct sockaddr*)&servaddr,sizeof(servaddr)<0))
		printf("can't connect\n");
	else
		printf("connected\n");
	printf("enter the no of frames\n");
	scanf("\nAll the Frame\n");
	for(i=0;i<=n;i++)
		printf("frame %d\n",i);
	recv(sd,recvmsg,20,0);
	printf("\nLost Frame %s is retansmitted",recvmsg);
	strcpy(sendmsg,recvmsg);
	send(sd,sendmsg,20,0);
	return 0;
}
