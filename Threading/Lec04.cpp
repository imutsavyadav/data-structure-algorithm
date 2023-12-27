// Topcic: Mutx In C++ Threading | Why Use Mutes | What Is Race Condition And How To Solve It? | What Is Critical Section

// Mutex: Mutual Exclusioln 

// Race Condition: 
// 0. Race condition is a situation where two or more threads/ process happend to change a common data at the same time.
// 1. If there is a race condition then we have to protect it and the protected section is called critical section/region.

// Mutex:
// 0. Mutex is used to avoid race condition. 
// 1. We use lock() , unlock() on mutex to avoid race condtion.

#include <iostream>
#include<thread> 
#include<mutex>
using namespace std ; 

int myAmount = 0 ;  // shared resource common resource 
std::mutex m ; 

void addMoney() { 
	m.lock();
	++myAmount;
	m.unlock();
}

int main() { 
	std::thread t1(addMoney);
	std::thread t2(addMoney);

	// basecially if im not using the concept of the mutex so this 
	// race condition is not be removed 
	t1.join(); 
	t2.join();

	cout << myAmount << endl;

}