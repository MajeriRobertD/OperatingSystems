#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>



int main(){
    int pfd1[2];
    int pfd2[2];

    pid_t pid;
    char ch;



    if(pipe(pfd1) == -1){
        fprintf(stderr, "Pile Failed");
        return 1;
    }

    if(pipe(pfd2) == -1){
        fprintf(stderr, "Pile Failed");
        return 1;
    }

    pid = fork();

    if(pid == -1){
        perror("Error");
        exit(1);
    }

    //Parent code
    else if(pid > 0){

        char filename[] ="lab10p14.c";
        char filecontent[1000];

        close(pfd1[0]);

        write(pfd1[1], filename, strlen(filename)+1);
        close(pfd1[1]);

        wait(NULL);

        close(pfd2[1]);
        int thesize = read(pfd2[0], filecontent, sizeof(filecontent));
        write(1, filecontent, thesize);
        close(pfd2[0]);
    }

    //Child code
    else{

        close(pfd1[1]);
        char filename[100];

        read(pfd1[0], filename, 100);

        FILE *file = fopen(filename,"r");


        if(file == NULL){
            printf("\nUnable to open file.\n");
            exit(EXIT_FAILURE);
        }
        close(pfd1[0]);

        close(pfd2[0]);

         while((ch = fgetc(file)) != EOF){
             write(pfd2[1], &ch , strlen(&ch));

         }

         close(pfd2[1]);
         exit(0);



    }



}
