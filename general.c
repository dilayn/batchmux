#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(void)
{
    FILE *file = fopen("batchmux.sh", "w");
    if(file == NULL)
    {
        printf("error opening file\n");
        exit(1);
    }
    int counter = get_int("Number of episodes: \n");
    string command = get_string("Input command\n");

    fprintf(file, "#!/bin/bash\n");
    for (int i = 1; i < counter + 1; i++)
    {
        fprintf(file, "%s\n", command);
    }
    fclose(file);
}
