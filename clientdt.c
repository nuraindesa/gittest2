#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <stdlib.h>
#include<time.h>

int main ()

{

	char buf[100];
	char dt[100];
	char s[100];
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
	client.sin_port=7778;
	k=connect(sock_desc,(struct sockaddr*)&client,sizeof(client));
	if (k==-1)
	{
		printf("Error in connecting to server");
		exit(1);
	}
		
		time_t mytime = time(NULL);
   		char * time_str = ctime(&mytime);
   		time_str[strlen(time_str)-1] = '\0';
   		printf("Current Time : %s\n", time_str);
		
		if (mytime>=0 && mytime< 12 )
		{
    			printf("Good morning ! \n");
		}
		else if (mytime>= 12 && mytime< 18)
		{
			printf("Good afternoon !\n");
		}
		else if (mytime>= 18)
		{
   			printf("Good evening !\n");
		}
		k=recv(sock_desc,dt,100,0);
		printf("Server Time : %s\n",dt);
		k=recv(sock_desc,s,100,0);
		printf(s);

		k=send(sock_desc,time_str,100,0);		
		while(1)
		{
		printf("\nEnter data to be send to server: ");
		fgets(buf, 100,stdin);
		if(strncmp(buf,"end",3)==0)
		break;

		k=send(sock_desc,buf,100,0);
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
