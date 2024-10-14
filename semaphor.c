#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

typedef struct shm_data_structure{
	sem_t sem;
	int index;
}SHM;
int main(){
	pid_t pid;
	int i,n=1000000;
	int fd=0;
	int sz=4096;
	void *ptr;

	fd = shm_open("test2",O_RDWR|O_CREAT,0666);
	if(fd==-1){
		perror("shm open:");
		exit(1);
	}
	ftruncate(fd,sz);
	ptr=mmap(0,sz,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	
	SHM *s=(SHM *)ptr;

	s->index=0;
	sem_init(&s->sem,1,1);

	if((pid=fork())==0){
		for(i=0;i<n;i++){
//			sem_wait(&s->sem);
			s->index++;
//			sem_post(&s->sem);
		}	
		shm_unlink("test2");
	}else{
		for(i=0;i<n;i++){
//			sem_wait(&s->sem);
			s->index++;
//			sem_post(&s->sem);
		}
		wait(NULL);
		printf("pid:%d %d\n",getpid(),s->index);
		shm_unlink("test2");
	}
}
