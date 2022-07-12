#include<pthread_copy.h>


typedef struct ARG
{
	int pos;
	int blocksize;
	char* sfile;
	char* dfile;
}Arg,*pArg;

void* jobs(void* pram)
{
	pArg arg = (pArg)pram;
		
	pthread_copy(arg->sfile,arg->dfile,arg->blocksize,arg->pos);
	
}

//创建线程并分配任务
int thread_create(const char* sfile, const char* dfile, int blocksize, int pronum)
{
	//设置分离态:
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	//创建线程
	//定义一个数组，用来给线程工作函数传参
	
	int flags = 0;
	pthread_t tid;
	int err;
	pArg arg;
	printf("pronum %d\n",pronum);
	for(flags; flags < pronum; flags++)
	{
		//根据传进来的参数pronum计算每个线程任务的起始位置
		arg->pos = flags*blocksize;
		arg->blocksize = blocksize;
		arg->sfile = sfile;
		arg->dfile = dfile;
		if((err = (pthread_create(&tid, &attr, &jobs, (void*)arg))>0))
		{
			printf("pthread_create called error %s\n",strerror(err));
			exit(0);
		}
		printf("pthread tid %x\n",(unsigned int)tid);
		usleep(200);
	}
	return 0;
}
