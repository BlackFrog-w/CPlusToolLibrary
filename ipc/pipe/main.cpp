/*
 * @Author: BlackFrog
 * @Date: 2022-08-19 20:45:03
 * @LastEditTime: 2022-10-17 21:52:11
 * @Description: 
 * 进程间通信方式：管道
 * 
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */


#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<string.h> 
#include <iostream> 

int main(int argc, char *argv[]) 
{ 
	int pipefd[2]; 
	if(pipe(pipefd) == -1) 
		perror("pipe error!"); 
 
	pid_t pid; 
	pid = fork(); 
	if(pid == -1) 
		perror("fork error!"); 
 
	if(pid == 0){ 
		close(pipefd[0]); 
		write(pipefd[1], "hellopp", 7); 
		close(pipefd[1]); 
		exit(EXIT_SUCCESS);
        std::cout << "hello, wangshuo" << std::endl; 
	} 
 
	close(pipefd[1]); 
	char buf[10] = {0}; 
	read(pipefd[0], buf, 10); 
	printf("buf=%s\n", buf); 
 
    sleep(2);
	return 0; 
} 