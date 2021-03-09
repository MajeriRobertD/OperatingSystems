#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<math.h>




int main(){

    int arr[] = {1,2,1};
    int i, cube, totalsum;

    pid_t pid ;
    totalsum =0;
    cube =0;

    for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        pid = fork();

        if(pid == -1){
            perror("Error");
            exit(1);
        }

        if(pid == 0){

            cube = arr[i]*arr[i]*arr[i];
            totalsum += cube;
            printf("Cube of %d is %d, computed by process with pid: %d \n",arr[i], cube, getpid() );
        }

        if(pid){
          return 0;

        }
    }

    printf("Total sum of cubes is: %d\n", totalsum );
    return  0;
}