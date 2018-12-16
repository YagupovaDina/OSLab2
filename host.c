#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>

#include "conn.h"
#define BUF_SIZE 1

int main(int argc, char **argv)
{
	int pid;
	sem_t* sem;
	
	sem = (sem_t*)mmap(0,sizeof(*sem),PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);
	sem_init(sem,1,0);
	create();
	pid = fork();
	if (pid > 0){
		cWrite();
		sem_post(sem);
	}
	else if(pid == 0)
	{
		sem_wait(sem);
		cRead();
	}
  	else{
  	  printf("Fork failed!\n");
  	}
sem_close(sem);
cdelete();
  return 0;
}
