#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

void main(int argc, char **argv) {
    freopen("ex2.txt", stdout, "w");
    int append = 0;
    if (!strcmp(argv[1], "-a")) {
        append = 1;
    }
    FILE *files[(const int)(argc - 1 - append)];
    //Data in files
    char *data[(const int)(argc - 1 - append)];
    for (int i = 1 + append, j = 0; i < argc; ++i, ++j) {
        files[j] = fopen(argv[i], "r");
        if(files[j] == NULL){
            printf("File %s doesn't exist", argv[i]);
            return;
        }
        int cnt = 0, sz = 1;
        data[j] = (char *)(malloc(sz * sizeof(char)));
        char c;
        while((c = fgetc(files[j])) != EOF){
            data[j][cnt++] = c;
            if(cnt == sz){
                sz *= 2;
                data[j] = (char *)(realloc(data[j], sz * sizeof(char)));
            }
        }
        data[j] = (char *)(realloc(data[j], cnt * sizeof(char)));
        fclose(files[j]);
    }
    for (int i = 1 + append, j = 0; i < argc; ++i, ++j) {
        if(append)
            files[j] = fopen(argv[i], "a");
        else
            files[j] = fopen(argv[i], "w");
    }
    for(int i = 0; i < argc - 1 - append; ++i){
        printf("%s\n", data[i]);
        for(int j = 0; j < argc - 1 - append; ++j){
            if(j == i)
                continue;
            fprintf(files[i], "%s\n", data[j]);
        }
        fclose(files[i]);
    }
}