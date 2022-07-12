#include<pthread_copy.h>


int pthread_copy(const char* sfile, const char* dfile, int blocksize,int pos)
{
	ssize_t readlen;

	int sfd = open(sfile, O_RDONLY);	
	
	if(sfd == -1)
	{
		printf("open sfile called fail\n");
		return;
	}
	int dfd = open(dfile, O_RDWR|O_CREAT,0664);
	if(dfd == -1)
	{
		printf("open dfile called fail\n");
		return ;
	}
	
	//设置文件读写偏移量
	lseek(sfd, pos, SEEK_SET);
	printf("pos %d\n",pos);
	lseek(dfd, pos, SEEK_SET);

	//进行读写操作
	char buffer[blocksize];
	bzero(buffer,sizeof(buffer));
	readlen = read(sfd,buffer, sizeof(buffer));
	printf("read %d\n",readlen);
	int i = write(dfd, buffer, readlen);
	printf("write  %d\n",i);
	usleep(200);
	//关闭文件描述符
	close(sfd);
	close(dfd);
	return;
}
