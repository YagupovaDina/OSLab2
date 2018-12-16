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
static int* numberOfq;

void create(void){
	numberOfq = (int*)mmap(0,sizeof(*numberOfq),PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);
}

void cWrite(void){
	printf("введите номер вопроса(первая цифра в вопросе):\n");
	printf("0 какого цвета елка?\n");
	printf("1 нумерация в вопросах начинается с нуля?\n");
	printf("2 сколько букв в слове кот?\n");
	printf("3 2+2?\n");
	scanf("%d",numberOfq);
	
}

void cRead(void){
switch(*numberOfq){
	case 0:
		printf("зеленая\n");break;
	case 1:
		printf("да\n");break;
	case 2:
		printf("3\n");break;
	case 3:
		printf("4\n");break;
}
}

void cdelete(void){
	munmap(numberOfq,BUF_SIZE);
}

