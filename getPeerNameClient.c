/*GET PEER NAME CLIENT*/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main(int argc,char *argv[])
{
        int s;
	char add[16];
        struct sockaddr_in server,addr;
        socklen_t len;
        s=socket(AF_INET,SOCK_STREAM,0);
        server.sin_family=AF_INET;
        inet_aton("172.20.0.7",&server.sin_addr);
        server.sin_port=htons(atoi(argv[1]));
        if(connect(s,(struct sockaddr *)&server,sizeof(server))<0)
        {
                perror("connect");
                exit(0);
        }
        len=sizeof(addr);

        getpeername(s,(struct sockaddr *)&addr,&len);
	inet_ntop(AF_INET,&addr.sin_addr,add,sizeof(add)); //converts from binary to text form
        printf("peer IP address:%s\n",add);
        printf("peer port:%d\n",ntohs(addr.sin_port));
}
