#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 50

int main(int agrc, char *argv[])
{
    FILE *fileopen = fopen(argv[1], "r");
    if (fileopen == NULL)
    {
        printf("wgrep: file not found!\n");
        exit(1);
    }

    char *line = NULL;

    size_t line_buf_size = 0;
    ssize_t line_size;
    line_size = getline(&line, &line_buf_size, fileopen);
    int len = strlen(line);
    char *destination = (char*) malloc(sizeof(char) * (len * 2 + 1));
    char number[MAX_LEN];
    while (line_size > 0)
    {
        int i = 0;
        int k; 
        int j = k;
        int counter = 0;

        for ( i = 0; i < len; i++)
        {
            /* code */
            while (i + 1 < len && line[i] == line[i+1])
            {
                /* code */
                counter ++;
                i++;

            }

            sprintf(number, "%d", counter);

            for (k = 0; *(number + k); k++, j++)
            {
                /* code */
                if(k == 0){
                    destination[j] = line[k];
                } else {
                destination[j] = number[k];

                }
            }
            
        }

        destination[j] = '\0';

        fwrite(destination, line_buf_size, sizeof(destination), fileopen);
        
        line_size = getline(&line, &line_buf_size, fileopen);
    }

    return 0;
}