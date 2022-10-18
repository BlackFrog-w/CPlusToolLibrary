/*
 * @Author: BlackFrog
 * @Date: 2022-10-18 22:25:59
 * @LastEditTime: 2022-10-18 22:27:32
 * @Description: 
 * 信号量
 * 参考链接：https://blog.csdn.net/skyroben/article/details/72513985
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
#include "comm.c"

#include<unistd.h> 

int main()
{
    int semid = CreatSemid(1);
    printf("%d\n", semid);
    InitSem(semid, 0, 1);
    pid_t id = fork();
    if (id == 0)
    {//child
        int semid = GetSemid(0);
        while (1)
        {
            P(semid, 0, -1);
            printf("A");
            fflush(stdout);
            usleep(10000);
            printf("A");
            fflush(stdout);
            usleep(20000);
            V(semid, 0, 1);
        }
    }
    else
    {//father
        while (1)
        {
            P(semid, 0, -1);
            usleep(30000);
            printf("B");
            fflush(stdout);
            usleep(8000);
            printf("B");
            fflush(stdout);
            usleep(20000);
            V(semid, 0, 1);
        }
        if (waitpid(id, NULL, 0) < 0)
        {
            perror("waitpid");
            return -1;
        }

    }
    Destory(semid);
    return 0;
}