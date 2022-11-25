#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Definitions
int compute_floor(char * input[]) {
    int floor = 0;
    for(int i = 0; i < strlen(input); i++) {
	switch(*input[i]) {
	    case '(': floor++; break;
	    case ')': floor--; break;
	    default: break;
        }
    }
    return floor;
}

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

    int floor = compute_floor("(())(((");
    printf("He is at floor %d", floor);
    return 0;
}

