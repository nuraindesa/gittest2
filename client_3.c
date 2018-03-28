
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
void checkHostName(int hostname)

{

    if (hostname == -1)

    {

        perror("gethostname");

        exit(1);

    }

}

void checkHostEntry(struct hostent * hostentry)

{

    if (hostentry == NULL)

    {

        perror("gethostbyname");

        exit(1);

    }

}

void checkIPbuffer(char *IPbuffer)

{

    if (NULL == IPbuffer)

    {

        perror("inet_ntoa");

        exit(1);

    }

}


int main ()
{
	char buf[100];
	int k;
	int a=1; 
	int sock_desc;
	struct sockaddr_in client;
	memset (&client, 0, sizeof(client));
	sock_desc=socket(AF_INET,SOCK_STREAM,0);
	
	if(sock_desc==-1)
	{
	printf("Error in socket creation");
	exit (1);
	}

	client.sin_family=AF_INET;
	client.sin_addr.s_addr=inet_addr("192.168.174.132");
	client.sin_port=6272;
	
	k=connect(sock_desc,(struct sockaddr*)&client,sizeof(client));
	if (k==-1)
	{
		printf("Error in connecting to server");
		exit(1);
	}
	char hostbuffer[256];

    char *IPbuffer;

    struct hostent *host_entry;

    int hostname;

hostname = gethostname(hostbuffer, sizeof(hostbuffer));

    checkHostName(hostname);

    host_entry = gethostbyname(hostbuffer);

    checkHostEntry(host_entry);

IPbuffer = inet_ntoa(*((struct in_addr*)

                           host_entry->h_addr_list[0]));

 

    printf("Hostname: %s\n", hostbuffer);

    printf("Host IP: %s\n", IPbuffer);

	while(1)
	{	
		
		printf("\nEnter data to be send to server: ");
		fgets(buf, 100,stdin);
		

		if(strncmp(buf,"end",3)==0)
		break;


		k=send(sock_desc,buf,100,0);
		k=recv(sock_desc,hostbuffer,100,0);
		k=recv(sock_desc,IPbuffer,100,0);
		printf("hostname : %s \n",hostbuffer);
		printf("ip : %s \n",IPbuffer);

		if(k==-1)
		{
			printf("Error in sending");
			exit (1);
		}

		k=recv(sock_desc,buf,100,0);
		printf ("server : %s ",buf);
		if (k==-1)
		{
			printf("error in receiving");
			exit(1);
		}		
}
	close (sock_desc);
	exit(0);
	return 0;
}

