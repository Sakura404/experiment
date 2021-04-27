#include<stdio.h>
#include<pthread.h>
pthread_t thread[2];
int number=0;
pthread_mutex_t mnt;
void * producer()
{
int i=0;
for(i=0;i<10;i++)
{
/*开始互斥锁*/
pthread_mutex_lock(&mnt);
if(number==0){
number++;
/*进行数据操作*/
printf("producer item.\n");
}
/*关闭互斥锁*/
pthread_mutex_unlock(&mnt);
sleep(1);
}
/*线程退出*/
pthread_exit(NULL);
}
void * customer()
{
int i=0;
for(i=0;i<10;i++)
{
/*开始互斥锁*/
pthread_mutex_lock(&mnt);
if(number>0){
number--;
/*进行数据操作*/
printf("customer item.\n");
}
/*关闭互斥锁*/
pthread_mutex_unlock(&mnt);
sleep(1);
}
/*线程退出*/
pthread_exit(NULL);
}
int main(void)
{
/*互斥锁初始化*/
pthread_mutex_init(&mnt,NULL);
/*创建生产者线程*/
pthread_create(&thread[0],NULL,producer,NULL);
/*创建消费者线程*/
pthread_create(&thread[1],NULL,customer,NULL);
/*等待工人1线程的结束*/
pthread_join(thread[0],NULL);
/*等待工人2线程的结束*/
pthread_join(thread[1],NULL);
return 0;
}

gcc -pthread  -o  pc.out  producerconsumer1.c
