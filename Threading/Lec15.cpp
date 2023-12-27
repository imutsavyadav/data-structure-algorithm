// Topic: std::future and std::promise in threading. 

// NOTES. 
// 1. std::promise
//		a.Used to set values or exceptions. 
// 2. std::future
//		a.Used to get values from promise.
// 		b.Ask promise if the value is available.
//		c.Wait for the promise.

// Program:

#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
#include<future>
using namespace std ;
using namespace std::chrono;
typedef long int ull;

void findODD(std::promise<ull>&& OddsumPromise , ull start , ull end){
	ull OddSum = 0 ; 
	for(ull i = start , i<=end ; i++){
		if(i&i){
			OddSum+=i;
		}
	}
	OddsumPromise.set_value(OddSum);
}

int main(){
	ull start = 0 ; end = 19000000000;

	std::promise<ull> OddSum;
	std::future<ull> OddFuture = OddSum.get_future();

	cout << "Thread Created!" << endl;
	std::thread t1(findODD,std::move(OddSum) , start , end);

	cout << "Wating for Result !!" << endl;

	cout << "OddSum : " << OddFuture.get() << endl;

	cout << "Completed!!" << endl;
	t1.join();
	return 0 ; 

}


















