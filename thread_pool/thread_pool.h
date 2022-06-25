/*
 * @Author: BlackFrog
 * @Date: 2022-06-12 20:07:44
 * @LastEditTime: 2022-06-12 21:37:43
 * @Description: 
 * https://wangpengcheng.github.io/2019/05/17/cplusplus_theadpool/
 * https://www.cnblogs.com/ailumiyana/p/10016965.html#%E7%AE%80%E4%BB%8B
 * https://github.com/kanade2010/ThreadPool
 * https://www.cnblogs.com/lzpong/p/6397997.html
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */

#pragma once
#include <functional>
#include <future>
#include <mutex>
#include <queue>
#include <thread>
#include <utility>
#include <vector>
#include "safe_queue.h"

class ThreadPool
{
private:
    /* data */

    class ThreadWorker
    {
    private:
        /* data */
        int m_id;
        ThreadPool* m_pool;

    public:
        ThreadWorker(ThreadPool* pool, const int id): m_pool(pool), m_id(id) { }

        void operator() () {
            std::function<void()> func;

            bool dequeued;

            while (!m_pool->m_shutdown)
            {
                {
                    std::unique_lock<std::mutex> lock(m_pool->m_conditional_mutex);

                    if(m_pool->m_queue.empty()) {
                        m_pool->m_conditional_lock.wait(lock);
                    }

                    dequeued = m_pool->m_queue.dequeue(func);

                }

                if(dequeued) {
                    func();
                }
            }
        }

        ~ThreadWorker() {

        }
    };

    bool m_shutdown;

    SafeQueue<std::function<void()>> m_queue;

    std::vector<std::thread> m_threads;

    std::mutex m_conditional_mutex;

    std::condition_variable m_conditional_lock;





public:
    ThreadPool(const int n_threads): m_threads(std::vector<std::thread>(n_threads)), m_shutdown(false) {

    }

    ThreadPool(const ThreadPool&) = delete;

    ThreadPool(ThreadPool&&) = delete;

    ThreadPool& operator=(const ThreadPool&) = delete;

    ThreadPool& operator=(ThreadPool &&) = delete;

    void init() {
        for (int i = 0; i < m_threads.size(); ++i) {
            m_threads[i] = std::thread(ThreadWorker(this, i));//分配工作线程

        }
    }   

    void shutdown() {
        m_shutdown = true;
        m_conditional_lock.notify_all(); //通知 唤醒所有工作线程

        for (int i = 0; i < m_threads.size(); ++i) {
            if(m_threads[i].joinable()) { //判断线程是否正在等待

            m_threads[i].join();  //将线程加入等待队列

            }
        }
    }

    template<typename F, typename...Args>
    auto submit(F&& f, Args&&... args) -> std::future<decltype(f(args...))> {
        // Create a function with bounded parameters ready to execute
        // 

        std::function<decltype(f(args...))()> func = std::bind(std::forward<F>(f), std::forward<Args>(args)...);//连接函数和参数定义，特殊函数类型,避免左、右值错误

        // Encapsulate it into a shared ptr in order to be able to copy construct // assign 
        //封装获取任务对象，方便另外一个线程查看结果

        auto task_ptr = std::make_shared<std::packaged_task<decltype(f(args...))()>>(func);

        // Wrap packaged task into void function
        //利用正则表达式，返回一个函数对象

        std::function<void()> wrapper_func = [task_ptr]() {
            (*task_ptr)(); 
        };

        // 队列通用安全封包函数，并压入安全队列

        m_queue.enqueue(wrapper_func);

        // 唤醒一个等待中的线程

        m_conditional_lock.notify_one();

        // 返回先前注册的任务指针

        return task_ptr->get_future();                                                                                              
    }

    ~ThreadPool(){
        
    }
};

