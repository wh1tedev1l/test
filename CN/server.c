#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
int main()
{
	int a,bd,sd,newsd,port,clilen;
	char lost[20],sendmsg[20],recvmsg[20];
	struct sockaddr_in servaddr,cliaddr;
	sd=socket(AF_INET,SOCK_STREAM,0);
	if(sd<0)
		printf("Can't Create\n");
	else
		printf("Socket Created\n");
	printf("Enter Port Number:\n");
	scanf("%d",&port);
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(port);
	a=sizeof(servaddr);
	bd=bind(sd,(struct sockaddr*)&servaddr,a);
	if(bd<0)
		printf("Can't Bind\n");
	else
		printf("\nBinded\n");
	listen(sd,5);
	clilen=sizeof(cliaddr);
	newsd=accept(sd,(struct sockaddr*)&cliaddr,&clilen);
	if(newsd<0)
		printf("Can't Accept\n");
	else
		printf("Accepted\n");
	printf("Enter the lost frame:\n");
	scanf("%s",lost);
	send(newsd,lost,20,0);
	recv(newsd,recvmsg,20,0);
	printf("\nFrame %s is successfully received",recvmsg);
	return 0;
}
