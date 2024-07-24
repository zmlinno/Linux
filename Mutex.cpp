#include<iostream>
#include<thread>
#include<mutex>


std::mutex mtx;
//创建一个互斥锁

void print_thread_id(int id)
{
    mtx.lock(); // 获取锁

    std::cout<<"Thread"<<id<<std::endl;
    mtx.unlock();//释放锁
}

int main()
{
    std::thread t1(print_thread_id,1);
    std::thread t2(print_thread_id,2);
    t1.join();
    t2.join();
    return 0;
}