#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<fcntl.h>

#define myfifo1 "/tmp/myfifo1"
#define myfifo2 "/tmp/myfifo2"


int main(){

    int fd1;
    int fd2;
    char filename[100];
    int read_bytes;
    char line[300];

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

    while(fgets(line, sizeof(line), file)){
        int len = strlen(line);
        int num = write(fd1, line, len);
        if(num != len)
            perror("write");
    }

     close(fd1);
     close(fd2);

    return 0;

}
