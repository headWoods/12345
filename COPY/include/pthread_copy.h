#pragma once 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<pthread.h>



//头文件声明函数

//参数校验
int pram_check(int arg, const char* sfile ,int pronum);

//文件分块
int file_block(const char* sfile , int pronum);

//线程创建并分配任务
int thread_create(const char* sfile , const char* dfile, int blocksize, int pronum);

//拷贝函数
int pthread_copy(const char* sfile, const char* dfile, int blocksize,int pos);
