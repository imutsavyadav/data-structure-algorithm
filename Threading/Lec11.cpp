// Topic: Condition Variable In c__ threading 

// Imporatant point: CV are used for two purposes
// A. Notify other threads
// B. Wating for some conditions

// 1. Condition Variable allows running threads to wait on some conditions and onnce those condtions are met the wating thread
//		 is notified using : 
// 			a. notify_one();
//			b. notify_all();

// 2. You need mutex to use condition variable. 
// 3. If some thread want to wait one some condtion then it has to do these things:
// 		a. Acquire the mutex lock using std::unique_lock<std::mutex> lock(m);
// 		b. Execute wait, wat_for , or wait_until . The wait operations atomically release the mutex
// 			and suspend the execution of the threa. 
// 		c. When the conditon variable is notified, the thread is awakened, and hte mutex is automically required.
// 			The thread should then check the conditon and resume wating if the wake up was spurios.

// NOTE: 
// 1. Conditoni varibles are used to synchronizes two or more threds.
// 2. Best use case of condition variable is Producer/Consumber Problem 

#include<iostream>
#include<thread>
#include <mutex>
#include<condition_variable>
using namespace std; 

std::condition_variable cv ; 
std::mutex m1 ; 
long balance = 0 ; 

void addMoney(int money) {
	std::lock_guard<mutex> lg(m);
	balance+=money;
	cout << "Amount Added Current Balance: " << balance << endl;
	cv.notify_one();
}

void withdrawMoney(int money){
	std::unique_lock<mutex> ul(m) ; 
	cv.wait(ul , []{ return (balance!=0) ? true : false ;});
	if(balance>=money){
		balance-=money;
		cout << "Amount Deducted: " << money << endl;
	}else{
		cout << "Amount Can't Be Deducted, Current Balance Is Less Than " << money << endl;
	}
	cout<< "Current Balance Is: " << balance << endl;
 }

 int main() {
 	std::thread t1(withdrawMoney,500);
 	std::thread t2(addMoney,500);
 	t1.join();
 	t2.join();
 	return 0 ; 
 }













