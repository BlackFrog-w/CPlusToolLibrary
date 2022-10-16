/*
 * @Author: BlackFrog
 * @Date: 2022-08-19 20:45:03
 * @LastEditTime: 2022-08-20 11:25:26
 * @Description: 
 * 进程间通信方式：管道
 * 
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/msg.h>
#include <sys/types.h>
#include<unistd.h>
#include <iostream>

// struct msgbuf {
//     long mtype;       /* message type, must be > 0 */
//     char mtext[50];    /* message data */
// };

int main(){
    //IPC_PRIVATE
    
	std::cout << "begin" << std::endl;
	
	int id = msgget(0x121212,O_CREAT|O_RDWR|0644);

	std::cout << "begin2" << std::endl;

    if(-1 == id){
        perror("msgget error");
        return 1;
    }


    pid_t pid = fork();


    if (pid < 0)//如果返回值小于0,则创建失败
    {
        printf(" error\n");
        exit(0);
    }


    if(pid == 0){ //返回值等于0,表示创建成功,是子进程运行

        printf("子进程写队列 pid=%d \n",getpid());

        for (int i = 0; i < 100; ++i) {
            sleep(1);

            char text[50] = "x-is sub test";
            int buf_size = sizeof(text)+sizeof(long);
            struct msgbuf* buf = (msgbuf *)malloc(buf_size);

            buf->mtype= i;
            strcpy(buf->mtext,text);

            int snd_ret = msgsnd(id,buf,buf_size,0);

//            printf("snd %s,snd_ret=%d \n",str,snd_ret);
            free(buf);


        }



    }else{ //main
        printf("主进程读取队列 pid=%d \n",getpid());

//		sleep(1);

        for (int i = 0; i < 100; ++i) {

            char text[50];
            int buf_size = sizeof(text)+sizeof(long);

//            struct msgbuf_t* buf_t;
//            buf_t= (msgbuf_t*)malloc(8);

            struct msgbuf* buf = (msgbuf *)malloc(buf_size);
            bzero(buf,buf_size);

            int rcv_ret = msgrcv(id,buf,buf_size,0,0);
            if(rcv_ret>=0){
                printf("rcv rcv_ret=%d,mtype=%ld,mtext=%s\n",rcv_ret,buf->mtype,buf->mtext);
                free(buf);
                buf = nullptr;
            }else{
                printf("rcv rcv_ret=%d \n",rcv_ret);
                break;
            }

        }

    }
    int ctl_ret = msgctl(id,IPC_RMID, nullptr);
    printf("pid=%d,ctl_ret=%d \n",getpid(),ctl_ret);

}