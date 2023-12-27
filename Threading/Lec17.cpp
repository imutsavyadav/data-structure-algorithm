// /d/ Topic: Producer Consumer Problem Or Buffer Problem

// The Problem Statment:
// 1. Producer will produce and consumer will cosume with synchronization of a common buffer.
// 2. Until producer thread produces any data consumer thread can't consume.
// 3. Thread will use condition_varialble to notify each other.
// 4. We need mutex if we use condition_variable because CV waits on mutex.
// 5. This is one of hte example of porducer consumer there are many. 

// Producer thread steps:
// 1. lock mutex, if success then go ahead otherwise wait for mutex to get free. 
// 2. check if buffer is full and if it full then unlock mutex and sleep, it not then go ahead and porduce. 
// 3. insert item in buffer. 
// 4. unlock mutex. 
// 5. notify consumer

// Consumer thread steps: 
// 1. lock mutex, if success then go ahead otherwise wait for mutex to get free. 
// 2. check if buffer is empty and it is, then unlock the mutex and sleep, if not then go ahead and consume. 
// 3. consume ithem from buffer. 
// 4. unlock mutex. 
// 5. notify producer

// IMP
// Producer and Consumer have to notify each other upon completion of their job.

#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>
#include<bits/stdc++.h>
using namespace std;

std::mutex mu;
std::condition_variable cond;
deque<int>buffer ; 
const unsigned int maxBufferSize = 50 ; 

void producer(int val){
	while(val){
		std::unique_lock<std::mutex> locker(mu);
		cond.wait(locker,[](){return buffer.size()< maxBufferSize;});
		buffer.push_back(val);
		cout << "Producer : " << val << endl;
		val--;
		locker.unlock();
		cond.notify_one();
	}
}


void consumer(){
	while(true){
		std::unique_lock<std::mutex> locker(mu);
		cond.wait(locker,[](){return buffer.size() > 0 ;});
		int val = buffer.back();
		buffer.pop_back();
		cout << "Consumer : " << val << endl;
		locker.unlock();
		cond.notify_one();
	}
}

int main(){
	std::thread t1(producer,100);
	std::thread t2(consumer);

	t1.join();
	t2.join();

	return 0; 
}
