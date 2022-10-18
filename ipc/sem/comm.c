/*
 * @Author: BlackFrog
 * @Date: 2022-10-18 22:26:28
 * @LastEditTime: 2022-10-18 22:27:51
 * @Description: 
 * 
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
#include "comm.h"
//int semget(key_t key, int nsems, int semflg);

static int CommSemid(int nums, int flags)
{
    key_t _key = ftok(PATHNAME, PROJ_ID);
    if (_key>0)
    {
        return semget(_key, nums, flags);
    }
    else
    {
        perror("CommSemid");
        return -1;
    }
}

int CreatSemid(int nums)
{
    return CommSemid(nums, IPC_CREAT | IPC_EXCL | 0666);
}
// int semctl(int semid, int semnum, int cmd, ...);

int GetSemid(int nums)
{
    return CommSemid(nums, IPC_CREAT);
}
int Destory(int semid)
{
    if (semctl(semid, 0, IPC_RMID)>0)
    {

        return 0;
    }
    else
    {
        perror("Destory");
        return -1;
    }
}

int InitSem(int semid, int which, int _val)
{

    union semun _semun;
    _semun.val = _val;
    if (semctl(semid, which, SETVAL, _semun)<0)
    {
        perror("InitSem");
        return -1;
    }
    return 0;
}
static int SemPV(int semid, int which, int _op)
{
    struct sembuf _sf;
    _sf.sem_num = which;
    _sf.sem_op = _op;
    _sf.sem_flg = 0;
    return semop(semid, &_sf, 1);
}

int P(int semid, int which, int _op)
{
    if (SemPV(semid, which, _op)<0)
    {
        perror("P");
        return -1;
    }
    return 0;
}

int V(int semid, int which, int _op)
{
    if (SemPV(semid, which, _op)<0)
    {
        perror("V");
        return -1;
    }
    return 0;

}