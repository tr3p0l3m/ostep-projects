#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int agrc, char *argv[])
{
    FILE *fileopen = fopen(argv[1], "r");
    if (fileopen == NULL)
    {
        printf("wgrep: file not found!");
        exit(1);
    }

    //user input
    char *input = NULL;
    input = argv[2];

    char *line = NULL;

    size_t line_buf_size = 0;
    ssize_t line_size;
    line_size = getline(&line, &line_buf_size, fileopen);
    while (line_size > 0)
    {
        char *temp;
        temp = strstr(line, input);
        if (temp != NULL)
        {
            /* code */
            printf("%s\n", line);
        }

        line_size = getline(&line, &line_buf_size, fileopen);
    }

    return 0;
}