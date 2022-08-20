#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* string_replace(char* source, size_t sourceSize, char* substring, char* with)
{
    char* substring_source = strstr(source, substring);
    if (substring_source == NULL) 
    {
        return NULL;
    }
 
    if (sourceSize < strlen(source) + (strlen(with) - strlen(substring)) + 1) 
    {
        printf("Buffer size is too small\n");
        return NULL;
    }
 
    memmove
    (
        substring_source + strlen(with),
        substring_source + strlen(substring),
        strlen(substring_source) - strlen(substring) + 1
    );
 
    memcpy(substring_source, with, strlen(with));
    return substring_source + strlen(with);
}

int main(void)
{
    //batch file
    FILE *file = fopen("batchmux.sh", "w");
    if(file == NULL)
    {
        printf("error opening file\n");
        exit(1);
    }

    //integer for episode count
    //int counter = get_int("Number of episodes: \n");
    printf("Number of episodes: \n");
    char ccounter[10];
    fgets(ccounter, sizeof(ccounter), stdin);
    int counter = atoi(ccounter);

    //mkvmerge command
    printf("Input command: \n");
    char command[2000];
    fgets(command, sizeof(command), stdin);

    //bash script header
    fprintf(file, "#!/bin/bash\n");

    char output[2000] = {0};
    char ii[10] = {0};

    //loop function
    if (counter < 100) 
    {

        for (int i = 1; i < counter + 1; i++)
        {
            snprintf(ii, 10, "%02d", i);
            snprintf(output, 2000, "%s", command);
            while(string_replace(output, 2000, "XX", ii));
            fprintf(file, "%s", output);
        }
    }
    else 
    {
        for (int i = 1; i < counter + 1; i++)
        {
            snprintf(ii, 10, "%03d", i);
            snprintf(output, 2000, "%s", command);
            while(string_replace(output, 2000, "XX", ii));
            fprintf(file, "%s", output);
        }
    }
    //end
    fclose(file);
}
