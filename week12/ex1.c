#include <stdio.h>
#include <unistd.h>

int main() {
    freopen("ex1.txt", stdout, "w");
    char s[21];
    int rand = open("/dev/random");
    read(rand, s, 20);
    printf("%s", s);
    return 0;
}