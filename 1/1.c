#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE* fp;
    char input[10000];
    fp = fopen("input.dat", "r");
    if(fp == NULL) {
        printf("Failed to open input file");
    }
    fgets(input, 10000, fp);
    printf("input: %s", input);
    fclose(fp);

    int floor = 0;

    for(int i = 0; i < strlen(input); i++) {
        printf("%c", input[i]);
        if(input[i] == "\0") { break; }
        if(input[i] == '(') { floor = floor + 1; }
        else { floor = floor - 1; }
    }
    printf("He is at floor %d", floor);
    return 0;
}
