/*
 * @Author: BlackFrog
 * @Date: 2022-06-12 19:49:36
 * @LastEditTime: 2022-06-12 19:58:20
 * @Description: 
 * 
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */

#pragma once
#include <mutex>
#include <queue>

template <typename T>
class SafeQueue {
private:
    /* data */
    std::queue<T> m_queue;

    std::mutex m_mutex;
public:
    SafeQueue(/* args */) {}

    SafeQueue(SafeQueue& other) {

    }

    ~SafeQueue() {

    }

    bool empty() {
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_queue.empty();
    }

    int size() {
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_queue.size();
    }

    void enqueue(T& t) {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_queue.push(t);
    }

    bool dequeue(T& t) {
        std::unique_lock<std::mutex> lock(m_mutex);

        if(m_queue.empty()) {
            return false;
        }
        t = std::move(m_queue.front());
        m_queue.pop();
        return true;
    }
};

