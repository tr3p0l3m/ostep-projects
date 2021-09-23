#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
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
    //char *destination = (char *)malloc(sizeof(char) * (len * 2 + 1));
    //char number[MAX_LEN];
    char *temp= NULL;
    while (line_size > 0)
    {
        int i = 0;
        //int k = 0;
        //int j = 0;
        //int counter = 0;
        int decimal = 0, base=1, rem;

        for (i = 0; i < len; i++)
        {
            /* code */
            //counter = 1;
            char *tempo;

            while (i + 1 < len)
            {
                if (line[i] == 1 || line[i] == 0)
                {
                    /* code */
                    tempo[i] = line[i];
                    i++;
                }else{
                    printf("%c\n",line[i]);
                }

                printf("%s\n",tempo);
                return 0;
            }
            // if (counter == 1)
            // {
            // /* code */

            int binary = 0;

            binary = atoi(temp);

            while (binary != 0)
            {
                /* code */
                rem = binary % 10;
                decimal = decimal + rem * base;
                binary = binary / 10;
                base = base * 2;
            }

            //printf("%d\n", decimal);
            

            //sprintf(decimal, "%s", temp);

        //     sprintf(number, "%d", decimal);
        //     //}

        //     for (k = 0; *(number + k); k++)
        //     {
        //         /* code */

        //         destination[j] = number[k];
        //         j++;
        //         //printf("%s\n",destination);
        //     }
        //     if (counter == 1){
        //         j--;
        //     }
        //     destination[j] = line[i];
        //     j++;
        }

        //destidecimalnation[j] = '\0';
        //fwrite(destination, line_buf_size, sizeof(destination), fileopen);
        printf("%s\n", line);
        return line_size;
    }

    return 0;
}