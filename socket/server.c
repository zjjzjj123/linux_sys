#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define MAXLINE 4096
#define SERV_PORT 8000


int main(void)
{
	struct sockaddr_in serveraddr,cliaddr;
	//1.socket
	//2.bind
	//3.listen
	//4.acctep 阻塞监听客户端链接请求
	socklen_t cliaddr_len;
	int listenfd,connfd;
	char buf[MAXLINE];
	char str[INET_ADDRSTRLEN];
	int i,n;
	listenfd = socket(AF_INET,SOCK_STREAM,0);
	//blid
	bzero(&serveraddr,sizeof(serveraddr));
	//地址族协议
	serveraddr.sin_family = AF_INET; 
	//ip地址
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(SERV_PORT);
	bind(listenfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
	//listen
	listen(listenfd,20);
	printf("Accepting connections....\n");
	while(1)
	{
		//accept阻塞监听客户端链接请求
		cliaddr_len = sizeof(cliaddr); 
		connfd = accept(listenfd,(struct sockaddr*)&cliaddr,&cliaddr_len);
		//输出客户端IP地址和端口号
		n = read(connfd,buf,MAXLINE);
		printf("received from %s at PORT %d\n",inet_ntop(AF_INET,&cliaddr.sin_addr,str,sizeof(str)),ntohs(cliaddr.sin_port));
		//和客户端交互数据操作confd
		for (i=0;i<n;i++)
			buf[i] = toupper(buf[i]);
		write(connfd,buf,n);
		close(connfd);
	}
}
