#include <stdint.h>
#include <stdio.h>
#include <winsock.h>

uint16_t my_ntohs(uint16_t n){
	return n << 8 | n >> 8;
	//return ((n & 0x00FF) << 8) | ((n & 0xFF00) >> 8));
}

uint32_t my_ntohl(uint32_t m) {
	return 
		((m & 0xFF000000) >> 24) | 
		((m & 0x00FF0000) >> 8) | 
		((m & 0x0000FF00) << 8) | 
		((m & 0x000000FF) << 24);
}

int main() {
	{
		uint8_t packet[] = { 0x00, 0x50 };
		uint16_t* p = reinterpret_cast<uint16_t*>(packet);
		uint16_t port = *p;
		port = ntohs(port);
		printf("%d\n", port);
	}

	{
		uint8_t packet[] = { 0x12, 0x34, 0x56, 0x78 };
		uint32_t* p = reinterpret_cast<uint32_t*>(packet);
		uint32_t ip = *p;
		ip = ntohl(ip);
		printf("%x\n", ip);
	}
}

