#include  <stdio.h>
#include  <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     pid_t  pid[1]; 
     int i;
     int status;
    
     ParentProcess();
  
     for(i = 0; i < 2; i++) {
       pid[i] = fork();
  
       switch(pid[i]) {
        case 0:     // child
          ChildProcess();
          wait();
          execl("/bin/ls", "ls", "-l", (char *)0); // children will fork off other children unless....
          break;

        case 1:   // error
          break;

        default: // parent, PID is child's PID
          ParentProcess();
          break;
       }
    }
  
      for(i = 0; i < 2; i++) {
        kill(pid[i]);
        wait(&status);
      }
  printf("Parent terminating! Child status = %d\n", status);
}

void  ChildProcess(void)
{
     int   i;
     time_t t;
     srand((unsigned) time(&t));
     printf("Parent waiting on Child pid = %d...\n", getpid());

     for (i = 1; i <= (rand() % 30); i++) {
          printf("Child Pid: %d is going to sleep!\n", getpid());
          sleep(rand() % 11);
          printf("Child Pid: is awake!\nWhere is my Parent: %d?\n", getppid());
       }
     printf("Child Pid: %d has completed\n", getpid());
}

void  ParentProcess(void)
{
     int   i;
     wait();

}