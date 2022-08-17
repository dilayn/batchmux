#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //char output[1000000] = {0};
    FILE *file = fopen("cowboy.sh", "w");
    if(file == NULL)
    {
        printf("error opening file\n");
        exit(1);
    }
    int counter;
    printf("Number of episodes: \n");
    scanf("%d", &counter); 
    fprintf(file, "#!/bin/bash\n");
    for (int i = 1; i < counter + 1; i = i + 1)
    {
        fprintf(file, "/usr/bin/mkvmerge --priority lower --output '/home/dilayn/mux/remux/Cowboy Bebop - e%02d.mkv' --audio-tracks 1 --subtitle-tracks 6 --language 0:ja --track-name '0:[JySzE] ITBD' --display-dimensions 0:1448x1080 --language 1:ja --track-name '1:[iKaos] 2.0 Japanese [Original Mix] [LD] - FLAC' --sub-charset 6:UTF-8 --language 6:en --track-name '6:[CBM / JySzE] English' '(' '/home/dilayn/mux/Cowboy Bebop/Cowboy Bebop - e%1$02d.mkv' ')' --track-order 0:0,0:1,0:6\n", i);
    }
    fclose(file);
}





//snprintf(output, 1000000, "/usr/bin/mkvmerge --priority lower --output '/home/dilayn/mux/remux/Cowboy Bebop - e%02d.mkv' --audio-tracks 1 --subtitle-tracks 6 --language 0:ja --track-name '0:[JySzE] ITBD' --display-dimensions 0:1448x1080 --language 1:ja --track-name '1:[iKaos] 2.0 Japanese [Original Mix] [LD] - FLAC' --sub-charset 6:UTF-8 --language 6:en --track-name '6:[CBM / JySzE] English' '(' '/home/dilayn/mux/Cowboy Bebop/Cowboy Bebop - e%1$02d.mkv' ')' --track-order 0:0,0:1,0:6\n", i);

//fprintf(file, "%s", output);
