#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>

#define myfifo1 "/tmp/myfifo1"
#define myfifo2 "/tmp/myfifo2"


int main(){

    int fd1;
    int fd2;

    int read_bytes;

    char filename[100];
    char filecontent[100];

    fd1 = open(myfifo1, O_RDONLY);
    fd2 = open(myfifo2, O_WRONLY);

    //getting filename from user
    printf("Enter file name:\n");
    fgets(filename, sizeof(filename), stdin);
    int stringlen = strlen(filename);
    filename[stringlen - 1] = '\0';


    write(fd2, filename, strlen(filename));
    printf("Filename : %s  was sent to server\n",filename);
    char s[1000];
    int thesize;

    while( (thesize = read(fd1, filecontent, sizeof(filecontent))) > 0){
          write(1, filecontent, thesize);

    }

        close(fd1);
        close(fd2);
    return 0;

}
