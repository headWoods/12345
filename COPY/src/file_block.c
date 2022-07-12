#include<pthread_copy.h>

int file_block(const char* sfile,int pronum)
{
	int fd = open(sfile, O_RDONLY);
	int size = lseek(fd,0,SEEK_END);
	printf("%d\n",size);
	if(size % pronum == 0)
		return size / pronum;
	else
		return (size / pronum) + 1;
}
