#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>


int main(){
	const int SZ = 18;
	char *str = "This is a nice day";
	FILE* file = fopen("ex1.txt", "r+");
	if(file == NULL){
		printf("FILE DOESN'T EXIST");
		return 0;
	}	
	fseek(file, 0L, SEEK_END);
	int file_size = ftell(file);
	fseek(file, 0L, SEEK_SET);
	close(file);
	int fd = open("ex1.txt", "r+");	
	char *addr = (char *) malloc(file_size);
	addr = (char *) mmap(addr, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if(addr == MAP_FAILED){
		printf("MMAP FAILED");
		return 0;	
	}
	for(int i = 0; i < SZ; ++i)
		addr[i] = str[i];
	for(int i = SZ; i < file_size; ++i){	
		addr[i] = ' ';
	}
	return 0;
}

