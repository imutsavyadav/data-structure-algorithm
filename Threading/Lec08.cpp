// Topic: Recursive Mutex In C++ (std::recursive_mutex)

// Notes: 
// 0. Its is same as mutex but , Same thread can lock one mutex multiple times using recursive_mutex.

// 1. If thread T1 first call lock/try_lock on recursive mutex m1 , then m1 is locked by T1, now
//     as T1 have aquired 10 times lock/try_lock on mutex m1 then thread t1 will have to unlock

// 2. But is T1 have aquired 10 times lock/try_lock on mutex m1 then thread t1 will have to unlock 
// 	  it 10 times ohterwise no other thread will be able to lock mutesx m1. 
//		It means recursive_mutex keeps count hwo many iimes it was locked so that many imes it shoub by unlocked

// 3. How many times we can lock recursive_mutex is not defined but when that number reaches and if we were calling 
// 	  lock() it will return std::system_error OR if we were calling try_lock() then it will return false.

// BOTTOM TIME:
// 0. It is similar to mutex but have extra facility that it can be locked multple time by same thread.
// 1. If we can avoid recursive_mutex then we should because it brings overhead to the sytem. 
// 3. It can be used in loops also. 

#include<iostream>
#include<thread> 
#include<mutex>
using namespace std; 

// Example 1: With Recursion 

std::recursive_mutex m1 ; 
int buffer = 0 ; 

void recursion(char c , int loopFor){
	if(loopFor<0)
		return ; 
	m1.lock();
	cout<< c << " " << buffer++  << endl;
	recursion(c, --loopFor);
	m1.unlock();	  
}

int main(){
	thread t1(recursion , '0' , 10);
	thread t2(recursion , '1' , 10);
	t1.join();
	t2.join();
	return 0 ; 
}


// Example 2: Wit loop

std :: recursive_mutex m1 ; 

int main(){
	for(int i = 0 ; i< 5 ; i++){
		m1.lock();
		std::cout << "locked " << i ; endl ; 
	}

	for(int i = 0 ; i<5 ; i++){
		m1.unlock();
		std::cout <<"blocked " << i << endl;
	}
	return 0 ; 
}








