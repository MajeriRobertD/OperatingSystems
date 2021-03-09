#include "stdio.h"
#include "stdlib.h"

int main(int argc, char const *argv[])
{
    char ch;
    int characters;
    int line;

    FILE *file = fopen(argv[1], "r") ;

    if(file == NULL){
        printf("\nUnable to open file.\n");
        exit(EXIT_FAILURE);
    }

    characters =  line = 0;
    while((ch= fgetc(file)) != EOF)
        {
            if(ch == '\n'){
                line++;
                printf("Line:  %d\n",line);
                printf("Characters on this line:  %d\n",characters );
                characters =0;
            }
            else
                characters++;

        }

    return 0;
}