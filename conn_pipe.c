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
static int pipeFd[2];
static char digit[1];

void create(void){
	if (pipe(pipeFd) == -1){
		printf("error fd");
	}
}

void cWrite(void){
	printf("введите номер вопроса(первая цифра в вопросе):\n");
	printf("0 какого цвета елка?\n");
	printf("1 нумерация в вопросах начинается с нуля?\n");
	printf("2 сколько букв в слове кот?\n");
	printf("3 2+2?\n");
	scanf("%s",digit);
	write(pipeFd[1],digit,strlen(digit));
	
}

void cRead(void){
char numberOfq;
read(pipeFd[0],&numberOfq,1);
	switch(numberOfq){
		case '0':
			printf("зеленая\n");break;
		case '1':
			printf("да\n");break;
		case '2':
			printf("3\n");break;
		case '3':
			printf("4\n");break;
	}

}

void cdelete(void){
	close(pipeFd[0]);
	close(pipeFd[1]);
}

