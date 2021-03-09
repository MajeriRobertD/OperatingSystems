#include "stdio.h"
#include <unistd.h>
#include <sys/wait.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>


int isVowel(char x){
     if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' ||
        x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
        return 1;
    return 0;
}



int main(){

    char givenString[] = "Here to remove the vowels";
    int i, j, status;
    pid_t pid ;

    for(i = 0; i< strlen(givenString); i++){

        if(isVowel(givenString[i]) == 1){
            char thevowel = givenString[i];

            pid = fork();

            if(pid == -1){
                perror("Error");
                exit(1);
            }
            if(pid == 0){
               for(j = i; j < strlen(givenString); j++)
                    givenString[j] = givenString[j+1];
                printf("\nRemoving the vowel %c with process : %d\n", thevowel, getpid() );

            }

            if(pid){
                return 0;
            }

        }

    }

    printf("\n%s\n", givenString );
    return 0;
}