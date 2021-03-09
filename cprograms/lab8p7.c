#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>



int main(){


    int arr[] = {1,2,3,4,5,6,7};

    int i, cube, totalsum;

    pid_t pid ;

    for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        pid = fork();

        if(pid == -1){
            perror("Error");
            exit(1);
        }


        if(pid == 0){
            cube = arr[i]^3 ;

        }

        if(pid){
            totalsum += cube;
        }

    }


    printf("%d\n", totalsum );


    return  0;
}