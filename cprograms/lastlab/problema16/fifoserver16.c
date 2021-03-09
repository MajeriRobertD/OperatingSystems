#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<ctype.h>

#define myfifo1 "/tmp/myfifo1"
#define myfifo2 "/tmp/myfifo2"


int main(){

    int fd1;
    int fd2;
    char filename[100];
    int read_bytes;
    char line[300];
    int prevwasspace =1 ;
    int words = 0;

    fd1 = open(myfifo1, O_WRONLY);
    fd2 = open(myfifo2, O_RDONLY);
    char ch;


    //getting file name from the pipe
    read_bytes = read(fd2, filename, sizeof(filename));
    filename[read_bytes] = '\0';
    printf("Server: Received file name: %s \n", filename);

    FILE *file = fopen(filename,"r");
    if(file == NULL){
        printf("\nUnable to open file.\n");
        exit(EXIT_FAILURE);
    }

         while((ch = fgetc(file)) != EOF){

             //counting the beginning of each word
             if(isspace(ch)){
                 prevwasspace = 1;
             }
             else{
                 if(prevwasspace)
                     words++;
                 prevwasspace = 0;
             }
         }


    write(fd1, &words, sizeof(words));


     close(fd1);
     close(fd2);

    return 0;

}
