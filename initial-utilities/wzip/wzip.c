#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX_LEN 50

int main(int argc, char *argv[])
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
    char *destination = (char *)malloc(sizeof(char) * (len * 2 + 1));
    char number[MAX_LEN];
    while (line_size > 0)
    {
        int i = 0;
        int k = 0;
        int j = 0;
        int counter = 0;

        for (i = 0; i < len; i++)
        {
            /* code */
            counter = 1;

            while (i + 1 < len && line[i] == line[i + 1])
            {
                counter++;
                i++;
            }
            // if (counter == 1)
            // {
            /* code */

            // int converter = CHAR_BIT * sizeof counter; /* however many bits are in an integer */
            // while(converter--) {
            //     putchar('0' + ((counter >> i) & 1)); 
            // }
            int binary = 0, mod, temp=1;
            while(counter != 0){
                mod = counter % 2;
                binary = binary+mod*temp;
                temp = temp * 10;
                counter = counter / 2;
            }
            
            sprintf(number, "%d", binary);

            //sprintf(number, "%d", counter);
            //}

            for (k = 0; *(number + k); k++)
            {
                /* code */

                destination[j] = number[k];
                j++;
                //printf("%s\n",destination);
            }
            // if (counter == 1){
            //     j--;
            // }
            destination[j] = line[i];
            j++;
        }

        //destination[j] = '\0';

        //printf("%s\n", destination);

        fwrite(destination, line_buf_size, sizeof(destination), fileopen);
        return line_size;
    }

    return 0;
}