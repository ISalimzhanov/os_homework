#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	char *str = "Hello";
	int SZ = 5;
	for(int i = 0; i < SZ; ++i){
		printf("%c", str[i]);
		sleep(1);
	}
}
