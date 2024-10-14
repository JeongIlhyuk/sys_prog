#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	pid_t pid;
	int sz = 4096;
	void *ptr = NULL;
	int fd=shm_open("test",O_RDWR|O_CREAT,0666);
	
	if(fd ==-1){
		perror("open failed\n");
	}
	
	ftruncate(fd,sz);
	ptr = mmap(0,sz,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

	if((pid=fork())==0){
		sleep(5);
		munmap(ptr,sizeof(void*));
		ptr=mmap(0,sz,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
		printf("child with ptr %ld\n",*(unsigned long*)ptr);
		shm_unlink("test");	
	}else{
		sleep(1);
		*(unsigned long*)ptr=100;
		wait(NULL);
		shm_unlink("test");
	}
}
