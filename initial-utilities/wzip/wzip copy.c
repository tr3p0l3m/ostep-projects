#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    char *line = NULL;
    char *encoding = NULL;
    int counter = 0;

    size_t line_buf_size = 0;
    ssize_t line_size;
    line_size = getline(&line, &line_buf_size, fileopen);

    //printf("%s", line);
    for (int i = 0; line[i]; i++)
    {
        /* code */
        counter = 1;
        while (line[i] == line[i + 1])
        {
            /* code */
            counter++;
            i++;
        }

        if (i > 1)
        {
            /* code */
            printf("%d", counter);
            printf("%c\n", line[i]);

            sprintf(encoding, "%d", counter);
            getchar();
            encoding = encoding + line[i];
            printf("%s\n", encoding);
        }
        else
        {
            encoding = encoding + line[1];
            printf("%s\n", encoding);
        }
    }

    printf("%s\n", encoding);
    fwrite(encoding, sizeof(line), strlen(encoding), fileopen);
    line_size = getline(&line, &line_buf_size, fileopen);

    return 0;
}