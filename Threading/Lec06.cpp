// Topiic std::try_lock() on Mutex In c++11 Threading 

// 0: std::try_lock() tries to lock all the lockable objects passed in it one by one in given order. 

//  SYNTAX:  std::try_lock(m1,m2,m3,m4,...mn)
//  The actual use of std::try_lock() function is, it can try to lock multiple mutex objects at the same time.

// 1: On success this funtion return -1 otherwise it will return 0 based mutex index number which it could not lock.
// 2: if if fail to lock any of the mutex it will release all the mutex it locked before. 
// 3: if a call a try_lock results in an exception, unlock is called for any locked objects before rethrowing


#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;
using namespace std::chrono;
int X = 0 , Y = 0 ; 
std::mutex m1 , m2 ; 

void doSomeWorkForSeconds(int seconds){
	std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void incrementXY(int& XorY , std::mutex&m , const char* desc){
	for(int i=0 ; i< 5 ; i++){
		m.lock();
		++XorY;
		cout << desc << XorY << endl;
		m.unlock();
		doSomeWorkForSeconds(1);
	}
}

void consumeXY(){
	int useCount = 5 ; 
	int XplusY = 0 ; 
	while(1){
		int lockResult = std::try_lock(m1,m2);
		if(lockResult == -1 ){
			if(X!=0 && Y!=0){
				--useCount ; 
				XplusY+=X+Y;
				X=0;
				Y=0;
				cout << "XplusY " << XplusY << endl; 
			}
			m1.unlock();
			m2.unlock();
			if(useCount == 0) break;
		}
	}
}


int main(){
	std::thread t1(incrementXY,std::ref(X) ,std::ref(m1) ,"X ");
	std::thread t2(incrementXY,std::ref(Y) ,std::ref(m2) ,"Y ");
	std::thread t3(consumeXY);

	t1.join();
	t2.join();
	t3.join();;
	return 0 ; 
}

















