#include<pthread_copy.h>

int pram_check(int arg, const char* sfile, int pronum)
{
	if(arg < 3)
	{
		printf("缺少参数.\n");
		exit(0);
	}
	if((access(sfile, F_OK)) != 0)
	{
		printf("文件不存在\n");
		exit(0);
	}
	if(pronum < 0 || pronum > 100)
	{
		printf("参数不符合要求.\n");
		exit(0);
	}
	printf("%d\n",pronum);
	return ;	
}
