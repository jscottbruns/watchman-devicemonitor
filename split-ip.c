#include <ctype.h>
#include <stdio.h>
#include <stdint.h>

void int2Ipaddr(int);
int ipToInt(int, int, int, int);


int main(void) {
    char *str = "10.100.1.4", *str2;
    unsigned char value[4] = {0};
    size_t index = 0;

    str2 = str; /* save the pointer */
    while (*str) {
        if (isdigit((unsigned char)*str)) {
            value[index] *= 10;
            value[index] += *str - '0';
        } else {
            index++;
        }
        str++;
    }

    unsigned long ulip;
    ulip = ipToInt(value[0], value[1], value[2], value[3]);

    printf("values in \"%s\": %d %d %d %d\n", str2,
              value[0], value[1], value[2], value[3]);
    printf("Long IP: %lu\n", ulip);

    int2Ipaddr(ulip);

    return 0;
}

void int2Ipaddr(int ip)
{
    unsigned char bytes[4];
    bytes[0] = ip & 0xFF;
    bytes[1] = (ip >> 8) & 0xFF;
    bytes[2] = (ip >> 16) & 0xFF;
    bytes[3] = (ip >> 24) & 0xFF;   
    printf("%d.%d.%d.%d\n", bytes[3], bytes[2], bytes[1], bytes[0]);        
}

int ipToInt(int first, int second, int third, int fourth)
{
    return (first << 24) | (second << 16) | (third << 8) | (fourth);
}
