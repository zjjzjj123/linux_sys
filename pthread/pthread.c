#include <pthread.h>
#include <stdio.h>
//编译时  gcc pthread.c -c -lpthread -o pthread
void *th_fun(void * arg)
{
	int *p = (int *arg)
	printf("thread PID = %d\n",getid());
	printf("thread ID = %x\n"(unsigned int)pthread_self());
	printf("thread *arg = %d\n",*p);
	while(1);
}

//执行起来 , ps -eLf and ps -Lw pid
int main(void)
{
	pthread_t tid;
	int n = 10;
	pthread_create(&tid,NULL,th_fun,(void*)&n);//1.创建线程2.线程号填写到tid,3.返回函数调用;
	printf("main thread ID = %x\n",(unsigned int)pthread_self());
	printf("main thread ID = %x\n",(unsigned int)pthread_self());
	printf("main child thread ID = %x\n",(unsigned int)tid);
	printf("main PID = %d\n",getpid());
	while(1);
	return 0;
}
