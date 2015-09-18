#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <stdio.h>

#define DATA_SIZE 100
#define SOCK_PATH "/tmp/receiver_sock"

int main(int argc, char* argv[])
{
	int sfd, count;
	char data[DATA_SIZE];
	struct sockaddr_un addr;
	sfd = socket(AF_UNIX, SOCK_DGRAM, 0);
	memset(&addr, 0, sizeof(struct sockaddr_un));
	addr.sun_family = AF_UNIX;
	strncpy(addr.sun_path, SOCK_PATH, sizeof(addr.sun_path) - 1);
	for(count =0; ; count++)
	{
		sprintf(data,"%d\n",count);
		sendto(sfd, data, DATA_SIZE, 0, (struct sockaddr*)&addr, sizeof(struct sockaddr_un));
		printf("%d\n", count);
		fflush(NULL);
	}
}
