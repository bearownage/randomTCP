#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define portnumber 52

int writeShit(int sock) {
	return 0;
}

int main() {
	struct sockaddr_in addr;
	char* hostname = "10.0.0.129";
	struct hostent *hent = gethostbyname(hostname);
	memcpy(&addr.sin_addr.s_addr, hent->h_addr, hent->h_length);
	addr.sin_port = htons(portnumber);
	addr.sin_family = AF_INET;

	int sock;

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) {
		perror("sock error client");
		return 0;
	}

	if ( connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0 ){
		perror("connection failed");
		return 0;
	}

	print("HEre");
	close(sock);
	return 0;
}
