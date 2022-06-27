/*
 * @Author: BlackFrog
 * @Date: 2022-06-27 10:35:43
 * @LastEditTime: 2022-06-27 12:44:20
 * @Description: 
 * https://en.cppreference.com/w/cpp/thread/condition_variable
 * https://cplusplus.com/reference/condition_variable/condition_variable/
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <string>

std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;

void work_thread() {
    std::unique_lock<std::mutex> lk(m);  
    cv.wait(lk, []{return ready;});

    // after the wait, we own the lock.
    std::cout << "Worker thread is processing data\n";
    data += " after processing";

    // Send data back to main()
    processed = true;
    std::cout << "Worker thread signals data processing completed\n";

    // Manual unlocking is done before notifying, to avoid waking up
    // the waiting thread only to block again (see notify_one for details)
    lk.unlock();
    cv.notify_one();

}

int main(int, char**) {
    
    std::thread worker(work_thread);
    data = "Example data";
    // send data to the worker thread
    {
        std::lock_guard<std::mutex> lk(m);
        ready = true;
        std::cout << "main() signals data ready for processing\n";
    }
    cv.notify_one();
    // wait for the worker
    {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, []{return processed;});
    }
    std::cout << "Back in main(), data = " << data << '\n';
    worker.join();
    std::cout << "Hello, world!\n";
}
