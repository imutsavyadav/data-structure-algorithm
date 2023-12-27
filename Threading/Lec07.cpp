// TOPIC :: Timed Mutex IN c++ Threading (std::timed_mutex) 
// @ we have learned Mutex , Reace Condtion, Critical Section in Previos viedo.

// Notes : 
// 0. std::time_mutes is blocked till timeout_time or the lock is aquired and returns true if success otherwise false. 
// 1. Memeber Function 
// 		a. lock
// 		b. try_lock
// 		c. try_lock_for  .... These tow functions makes it different from mutex. 
// 		d. try_lock_until ......
// 		e. unblock

// Example: try_lock_for();
// Watis unitl specified timeout_duration has elapsed or the lock is acquired , which ever comes firs.
// On successful lock acqusition return true, otherwise returns false. 



#include <iostream>
#include <thread> 
#include <mutex>
#include <chrono>
using namespace std ; 

int myAmount = 0 ; 
std::timed_mutex m ; 

void increment(int i){
	if(m.try_lock_for(std::chrono::seconds(1))){
		++myAmount;
		std::this_thread::sleep_for(std::chrono::seconds(2));
		cout << "Thread " << i << " Entered" << endl;
		m.unlock() ;
	}else{
		cout << "Thread " << i << " Couldn't Enter"<< endl;
	}
}

int main() {
	std::thread t1(increment , 1 );
	std::thread t2(increment , 2 ); 

	t1.join();
	t2.join();

	cout << myAmount << endl;
	return 0 ; 
}













