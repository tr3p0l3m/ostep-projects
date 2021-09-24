#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_LEN 50
#define floor
#define log10

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
    //int counter = 0;
    //char *destination = (char *)malloc(sizeof(char) * (len * 2 + 1));
    //char number[MAX_LEN];
    //char *temp = NULL;
    while (line_size > 0)
    {
        //printf("%d\n", atoi(line));
        int found = 1;
        for (int x = 0; x < found; x++)
        {
            /* code */

            int j = 0;
            char buffer[200];
            int binary = atoi(line);
            if (line[j] == '0')
            {
                line[j] = '1';
            }
            int binaryfake = atoi(line);
            sprintf(buffer, "%d", binaryfake);
            printf("%s\n", buffer);

            int decimal = 0, rem, base = 1;
            int temp = binary;

            while (temp > 0)
            {
                /* code */
                rem = temp % 10;
                ;
                decimal = decimal + rem * base;
                temp = temp / 10;
                base = base * 2;
            }

            int nDigits = strlen(buffer);
            while (nDigits < 1)
            {
                /* code */
                nDigits++;
            }

            printf("The decimal number is: %d\n", decimal);
            printf("The print stream is: ");
            for (int i = 0; i < decimal; i++)
            {
                printf("%c", line[nDigits]);
            }
            printf("\n");
            printf("%d is the length of the binary\n", nDigits);
            printf("%c is the next character of the line\n", line[nDigits]);

            char buf[strlen(line) + 1];
            strncpy(buf, line + nDigits + 1, strlen(line) - nDigits);
            printf("%s\n", buf);

            if (line[nDigits] != '\0')
            {
                /* code */
                //char buf[strlen(line) + 1];

                // strncpy(buf, line + nDigits + 1, strlen(line) - nDigits);
                // printf("%s\n", buf);
                line = buf;
                found++;
            }
            else
            {
                found--;
            }
        }

        //line = buf;

        return 0;
    }

    return 0;
}