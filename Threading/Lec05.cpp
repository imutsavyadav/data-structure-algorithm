// Topiic std::mutex::try_lock() on Mutex In c++11 Threading 

// 0. try_lock() Tries to lock the mutex. Return immediately. On sucessful lock acquistion returns true otherwise return false
// 1. If try_lock() is not able to lock mutex. then it doesn't get blocked that's why it is called non-blocking.
// 2. If try_lock is called again by the same thread which owns the mutex. the behavior is undefined.
// 3. It is a dead lock situation with undefined behaviour. (if you want to be able to lock the same mutes by same thread 
// 	   more than one time go for recursive_mutes)

#include<iostream> 
#include<thread>
#include<mutex>

using namespace std ; 
int counter = 0 ; 
std:: mutex mtx ; 

void increaseTheCounterFor10000Time(){
	for(int i = 0 ; i<100000 ; ++i){
		if(mtx.try_lock()){
			++counter;
			mtx.unlock();
		}
	}
}

int main() {
	std::thread t1(increaseTheCounterFor10000Time);
	std::thread t2(increaseTheCounterFor10000Time);

	t1.join();
	t2.join();

	cout << "counter could increase upto :" << counter ;
}


// Therre are so many try_lock function
// 1. std::try_lock(m1,m2,m3.....)
// 2. std::mutex::try_lock
// 3. std::shared_lock::try_lock
// 4. std::timed_mutes::try_lock
// 5. std::unique_lock::try_lock
// 6. std::shared_mutex::try_lock
// 7. std::recursive_mutex::try_lock
// 9. std::recursive_mutes::try_lock