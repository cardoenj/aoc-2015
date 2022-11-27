#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Definitions
int compute_floor(const char input[]) {
    int floor = 0;
    for(int i = 0; i < strlen(input); i++) {
	switch(input[i]) {
	    case '(': floor++; break;
	    case ')': floor--; break;
	    default: break;
        }
    }
    return floor;
}

int compute_char_at_basement(const char input[]) {
    int floor = 0;
    for(int i = 0; i < strlen(input); i++) {
        switch(input[i]){
            case '(': floor++; break;
            case ')': floor--; break;
            default: break;
        }

        if(floor == -1) {
            return i+1; // position, starting from 1
        }
    }
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

    int floor = compute_floor(input);
    printf("He is at floor %d\n", floor);

    int position = compute_char_at_basement(input);
    printf("He reaches the basement at position %d", position);
    return 0;
}

