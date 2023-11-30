#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() 

{
    // printing Parent Process before creating child processes
    printf("Parent process %d which will create all child processes \n", getpid()); 
    pid_t pid;
    
    //Creating first child process using fork
    pid = fork(); 
    wait(NULL); // waiting until 1st child processed is completed
    //Creating second child process using fork
    pid = fork(); 
    wait(NULL); // waiting until 2nd child processed is completed
    if (pid == 0) // checking if the child processes are completed
    {
        // Code executed by the first child process

        //Third fork to create subsequent child processes
        fork();
        wait(NULL); // waiting until 3rd child processed is completed
        //Fourth fork to create subsequent child processes
        fork(); 
        wait(NULL); // waiting until 4th child processed is completed
    } 
    // code executed by both parent and child processes
    printf("Child process ID: %d Parent Process ID: %d\n", getpid(), getppid());



    return 0;
}