#include "stdio.h"
#include "stdlib.h"
#include "string.h"



int main(int argc, char const *argv[])
{

 FILE *input, *output;
    char ch, read[100];
    int wordLen, i, p= 0;


    input = fopen(argv[1], "r");
    output = fopen("ouput.txt", "w+");
    if(input == NULL || output == NULL){
        printf("Unable to open file.");
        exit(0);
}


   const char * word = argv[2];
   const char * replace = argv[3];

    rewind(input);
    while(!feof(input)){


        fscanf(input, "%s\n", read);

        if(strcmp(read, word) == 0){
            strcpy(read,replace);
        }

        fprintf(output, "%s ",read);
    }



    rewind(output);
    while(1){
        ch = fgetc(output);
        if(ch == EOF){
            break;
        }
        printf("%c", ch);
    }
    fclose(input);
    fclose(output);


}