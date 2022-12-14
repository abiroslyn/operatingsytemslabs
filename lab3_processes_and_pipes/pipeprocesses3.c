#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
  int pipefd[2], pipe2[2];
  int pid, pid2;

  char *cat_args[] = {"cat", "scores", NULL};
  char *grep_args[] = {"grep", argv[1], NULL};
  char *sort_args[] = {"sort", NULL};
  
  pipe(pipefd);
  pipe(pipe2);

  pid = fork();

  if (pid == 0) // child
    {
      pid2 = fork();
      if (pid2 == 0) {
        dup2(pipe2[0], 0); // read from pipe2
        close(pipe2[1]);
        close(pipefd[1]);
        close(pipefd[0]);
        execvp("sort", sort_args);
      }
      else {
      dup2(pipe2[1], 1); // write to pipe2
      dup2(pipefd[0], 0); // read from pipefd
      close(pipefd[1]);
      close(pipe2[0]);
      execvp("grep", grep_args);
      }
    }
  else {
      dup2(pipefd[1], 1); // write to pipefd
      close(pipefd[0]);
      execvp("cat", cat_args);
    }
}