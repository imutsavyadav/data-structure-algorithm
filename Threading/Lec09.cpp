// Topic:: lock)guard In C++ (std::lock_guard<mutex> lock(m1)) 

// Notes: 
// 0. It is very light weight wrapper for owning mutex on scoped basis. 
// 1. It acquirs mutex lock the moment you create the oblect of lock)guard. 
// 2. It automatically removes the lock while goes out of space. 
// 3. you can not explicitly unlick the lock_guard. 
// 4. You can not copy lock_guard.

#include <iostream>
#include <thead>
#include <mutex>
using namespace std;
std :: mutex m1 ; 
int buffer = 0 ; 

vod task(const char* threadNumber, int looFor){
	m1.lock();
	for(int i = 0 ; i< loopFor ; i++){
		buffer++;
		cout << threadNumber << buffer << endl;
	}
	m1.unlock();
}

int main(){
	thread t1(task,"T0" , 10);
	thread t2(task,"T1" , 10);
	t1.join();
	t2.join();
	return 0 ; 

}