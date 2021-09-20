#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fileopen;
    fileopen = fopen(argv[1], "r");
    if (fileopen == NULL)
    {
        /* code */
        printf("wcat: No file availble");
        exit(1);
    }

    //char *line = NULL;
    char line[1024];
    while (fgets(line,1024, fileopen))
    {
        printf("%s",line);
    }
}