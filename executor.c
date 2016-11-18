#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <unistd.h>

#include <errno.h>

#define BUFFERSIZE 100

int main(int argc, char *argv[]) {
  printf("Type a command: ");
  char buffer[BUFFERSIZE];
  while (fgets(buffer, BUFFERSIZE, stdin) == NULL) {}
  
  char *s = buffer;
  char *command[BUFFERSIZE];
  int i = 0;

  while (buffer[i] != '\n' && buffer[i] != 0) {
    i++;
  }
  buffer[i] = 0;
  i = 0;
  while (s) {
    command[i] = strsep(&s," ");
    if (strcmp(command[i],"\n") == 0) {
      command[i] = 0;
    }
    i++;
  }
  command[i] = 0;
  int err = execvp(command[0], command);
  if (err == -1) {
    printf("Error: %d, %s\n",errno,strerror(errno));
  }
}
