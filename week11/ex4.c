#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int sz = 0;
	char temp[10000];
	FILE* file = fopen("ex1.txt", "r");
	if(file == NULL){
		printf("FILE DOESN'T EXIST");
		return 0;
	}	
	while((temp[sz++] = fgetc(file)) != EOF){};	
	char *str = (char *) calloc(sz, sizeof(char));	
	close(file);
	file = fopen("ex1.memcpy.txt", "w");
	if(file == NULL){
		printf("FILE DOESN'T EXIST");
		return 0;
	}	
	fseek(file, 0L, SEEK_END);
	int file_size = ftell(file);
	fseek(file, 0L, SEEK_SET);
	close(file);
	int fd = open("ex1.txt", "r+");	
	char *addr = (char *) calloc(file_size, sizeof(char));
	addr = (char *) mmap(addr, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if(addr == MAP_FAILED){
		printf("MMAP FAILED");
		return 0;	
	}
	strcpy(addr, str);
	return 0;
}

