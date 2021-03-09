#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>




int main(){
    int a[] = {1,2,3,4};
    if (fork()==0) { // child process
         a[0]+=a[1];

         exit(0);

    }
    // parent process
    a[2]+=a[3];
    wait(NULL);
    a[0]+=a[2];
    printf("The sum is %d\n", a[0]);
}