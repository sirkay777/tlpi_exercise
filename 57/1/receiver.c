#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define SOCK_PATH "/tmp/receiver_sock"
#define BUFF_SIZE 10

char buffer[BUFF_SIZE];

int main(int argc, char* argv[])
{
	int sfd;
	struct sockaddr_un addr;
	sfd = socket(AF_UNIX, SOCK_DGRAM, 0);
	memset(&addr, 0, sizeof(struct sockaddr_un));
	addr.sun_family = AF_UNIX;
	strncpy(addr.sun_path, SOCK_PATH, sizeof(addr.sun_path) - 1);
	bind(sfd, (struct sockaddr*)&addr, sizeof(struct sockaddr_un));
	for(;;){
		recvfrom(sfd, buffer, BUFF_SIZE, 0, NULL, NULL);
		printf("%s\n", buffer);
		fflush(NULL);
		sleep(1);
	}
}
