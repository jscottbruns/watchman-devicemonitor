#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(void)
{
// IPv4 demo of inet_ntop() and inet_pton()
struct sockaddr_in antelope;
char *some_addr;

inet_aton("10.0.0.1", &antelope.sin_addr); // store IP in antelope

    some_addr = inet_ntoa(antelope.sin_addr); // return the IP
    printf("%d\n", atoi(some_addr)); // prints "10.0.0.1"

// and this call is the same as the inet_aton() call, above:
    antelope.sin_addr.s_addr = inet_addr("10.0.0.1");

}
