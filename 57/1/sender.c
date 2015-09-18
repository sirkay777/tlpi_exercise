#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>

#define BUFF_SIZE 10
#define SOCK_PATH "/tmp/receiver_sock"
#define SEND_DATA "data to send"

int main(int argc, char* argv[])
{
	int sfd, count;
	struct sockaddr_un addr;
	sfd = socket(AF_UNIX, SOCK_DGRAM, 0);
	memset(&addr, 0, sizeof(struct sockaddr_un));
	addr.sun_family = AF_UNIX;
	strncpy(addr.sun_path, SOCK_PATH, sizeof(addr.sun_path) - 1);
	for(count =0; count < 1000; count++)
	{
		sendto(sfd, SEND_DATA, sizeof(SEND_DATA), 0, (struct sockaddr*)&addr, sizeof(struct sockaddr_un));
	}
}
