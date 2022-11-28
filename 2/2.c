#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

int compute_area(int *result)
{
    return 2 * result[0] * result[1] + 2 * result[1] * result[2] + 2 * result[0] * result[2];
}

int sort(int * dimensions, const int length)
{
    int is_ok = 1;

    for (int i = 0; i < length - 1; i++)
    {
        if (dimensions[i] > dimensions[i + 1])
        {
            is_ok = 0;
        }
    }

    if (is_ok == 1)
    {
        return length;
    }
    else
    {
        for (int i = 0; i < length - 1; i++)
        {
            if (dimensions[i] > dimensions[i + 1])
            {
                int temp = dimensions[i + 1];
                dimensions[i + 1] = dimensions[i];
                dimensions[i] = temp;
            }
        }

        return sort(dimensions, 3);
    }
}

int compute_ribbon(int * result) {
    sort(result, 3);

    return (2 * (result[0] + result[1])) + (result[0] * result[1] * result[2]);
}

int compute_slack(int *result)
{
    // The surface of smallest rectangle
    sort(result, 3);

    return result[0] * result[1];
}

int main()
{
    FILE * fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    int total = 0;
    int total_ribbon = 0;
    fp = fopen("input", "r");
    if (fp == NULL)
        exit(-1);

    const char * delimiter = "x";

    while ((read = getline(&line, &len, fp)) != -1)
    {
        int input[3];
        char *ptr;

        ptr = strtok(line, delimiter);
        int it = 0;
        while (ptr != NULL)
        {
            input[it] = atoi(ptr);
            it++;
            ptr = strtok(NULL, delimiter);
            
        }
        total += compute_area(input) + compute_slack(input);
        total_ribbon += compute_ribbon(input);
    }

    fclose(fp);
    if (line)
        free(line);
    printf("Total wrap: %d\n", total);
    printf("Total robbin: %d\n", total_ribbon);
    return 0;
}