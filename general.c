#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char output[1000000] = {0};
    FILE *file = fopen("batch.sh", "w");
    if(file == NULL)
    {
        printf("error opening file\n");
        exit(1);
    }
    int counter;
    printf("Number of episodes: \n");
    scanf("%d", &counter);

    char command[10000] = {0};
    printf("Input command\n");
    scanf("%s", &command);

    fprintf(file, "#!/bin/bash\n");
    for (int i = 1; i < counter + 1; i = i + 1)
    {
        snprintf(output, 1000000, "%s\n", command);
        fprintf(file, "%s", output);
    }
    fclose(file);
}
