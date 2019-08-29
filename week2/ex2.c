//
// Created by iskab on 29.08.2019.
//

#include <stdio.h>
#include <stdlib.h>

int main(){
    int block = 100, sz = 0;
    char *c = (char *)(calloc(block, sizeof (char)));
    while(((c[sz++] = fgetchar())) != EOF){
        if(!(sz % block)){
            c = (char *)(realloc(c, sz - 1 + block));
        }
    }
    sz--;
    for(int i = sz - 1; i >= 0; --i){
        printf("%c", c[i]);
    }
}
