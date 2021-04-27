#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<errno.h>
#include<semaphore.h>
#include<sys/ipc.h>
#include<string.h>
#define BUFFER_SIZE 5
#define SIZE 30
int pipe_fd[2];
int i=0,j=0;
sem_t mutex,full,avail;
char *write_buffer="hello";
void *producer(void *arg)
{
int real_write;
char pro_rand=0;
while(i<10)
{
sem_wait(&avail);
sem_wait(&mutex);
/*产生1-3随机数，作为延迟的秒数*/
pro_rand=((rand()%3)+1);
printf("\nProducer:delay=%d\n",pro_rand);
if((real_write=write(pipe_fd[1],write_buffer,strlen(write_buffer)))==-1)
{
if(errno==EAGAIN)
{
printf("The FIFO has not been read!\n");
}
}else{
printf("Write %d to the FIFO\n",strlen(write_buffer));
}
sem_post(&full);
sem_post(&mutex);
i++;
sleep(pro_rand);
}
pthread_exit(NULL);
}
void *customer(void *arg)
{
char r_buffer[SIZE];
int real_read;
while(j<10)
{
sem_wait(&full);
sem_wait(&mutex);
printf("\nCustomer:Num=%d\n",j);
if((real_read=read(pipe_fd[0],r_buffer,strlen(write_buffer)))==-1)
{
if(errno==EAGAIN)
{
printf("No data!\n");
}
}
printf("Read>>%s<<from FIFO\n",r_buffer);
sem_post(&avail);
sem_post(&mutex);
j++;
}
pthread_exit(NULL);
}
int main()
{
pthread_t thread[2];
int ret=0;
int tmp=0;
/*创建无名管道*/
tmp=pipe(pipe_fd);
if(tmp<0)
{
printf("fail to create pipe!\n");
exit(1);
}
/*创建3个信号量*/
ret=sem_init(&mutex,0,1);
ret+=sem_init(&avail,0,BUFFER_SIZE);
ret+=sem_init(&full,0,0);
if(ret!=0)
{
printf("fail to initial anonymous semaphore!\n");
return ret;
}
/*创建生产者线程*/
ret=pthread_create(&thread[0],NULL,producer,NULL);
if(ret!=0)
{
printf("Create producer thread error\n");
return ret;
}
/*创建消费者线程*/
ret=pthread_create(&thread[1],NULL,customer,NULL);
if(ret!=0)
{
printf("Create customer thread error\n");
return ret;
}
/*等待生产者消费者线程结束*/
pthread_join(thread[0],NULL);
pthread_join(thread[1],NULL);
/*关闭管道*/
close(pipe_fd[0]);
close(pipe_fd[1]);
return 0;
}


编译格式：  gcc -pthread  -o  pc.out  producerconsumer2.c