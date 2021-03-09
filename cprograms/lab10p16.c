#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
#include<ctype.h>


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

        char filename[] ="primulfisier.txt";
        int nrwords = 0;

        close(pfd1[0]);

        write(pfd1[1], filename, strlen(filename)+1);
        close(pfd1[1]);

        wait(NULL);

        close(pfd2[1]);
        read(pfd2[0], &nrwords, sizeof(nrwords));
        printf("The  number of words:\n%d\n",nrwords);

        close(pfd2[0]);
    }

    //Child code
    else{
        int words= 0;
        int prevwasspace = 1;
        char filename[100];

        close(pfd1[1]);

        read(pfd1[0], filename, 100);

        FILE *file = fopen(filename,"r");


        if(file == NULL){
            printf("\nUnable to open file.\n");
            exit(EXIT_FAILURE);
        }

        close(pfd1[0]);
        close(pfd2[0]);


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

         write(pfd2[1], &words, sizeof(words));

         close(pfd2[1]);
         exit(0);



    }
}