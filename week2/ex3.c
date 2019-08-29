//
// Created by iskab on 29.08.2019.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        char *temp = (char *) (calloc((const int)(2 * n), sizeof(char)));
        temp[n - 1] = '*';
        for (int j = n - 2, cnt = 1; cnt <= i - 1; --j, ++cnt) {
            temp[j] = '*';
        }
        for (int j = n, cnt = 1; cnt <= i - 1; ++j, ++cnt) {
            temp[j] = '*';
        }
        for(int j = 0; j < 2 * n; ++j){
            printf("%c", temp[j]);
        }
        printf("\n");
        free(temp);
    }
    return 0;
}