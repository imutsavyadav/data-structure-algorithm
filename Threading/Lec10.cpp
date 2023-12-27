// Topic: unique_lock In c++ (std::unique_lock<mutex> lock(m1))

// Notes:
// 1. The class unique_lock is a mutex ownership wrapper. 
// 2. It Allows: 
// 		a. Can Have Different Locking Stratergies 
// 		b. Time - constrained attempts at locking (try_lock_for , try_lock_until())
//		c. recursive locking 
// 		d. tranfer of lock owership (move not copy) 
// 		e. condition varibales. (See this incoming viedos)

// Locking Stratergies 
// 		TYPE             Effect(S)
// 1.   defer_lock       do not acquire ownership of hte mutex.
// 2.   try_to_lock      try to acquire ownership of the mutex without blocking.
// 3.   adopt_lock       assume the calling thread already has ownership of the mutex.

#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

std::mutex m1 ;
int buffer = 0 ; 

// Example 1 ; 

void task(const char* threadNumber , int loopFor) {
	std::unique_lock<mutex> lock(m1); // Automatically calls lock on mutex m1
	for(int i=0 ; i<loopFor ; i++){
		buffer++;
		cout << threadNumber << buffer << endl;
	}
}


int main() {
	thread t1(task,"T1 " ,10);
	thread t2(task,"T2 " ,10);

	t1.join();
	t2.join();
	return 0 ; 
}




// Example 2 

void task(const char* threadNumber, int loopFor){
	std::unique_lock<mutex> lock(m1,std::defer_lock); //Does not call lock on mutex m1, because used defer_lock
	lock.lock();
	for(int i = 0 ; i< loopFor; i++){
		buffer++;
		coiut << threadNumber << buffer << endl;
	}
	// lock.unlock() ; is not needed as it will be unlocked in destructor of unique_lock.
}


int main() {
	thread t1(task,"T1 " ,10);
	thread t2(task,"T2 " ,10);

	t1.join();
	t2.join();
	return 0 ; 
}



































