// TOPIC : Use of join(), detach() and joinable() In Thred In C++ (C++11)

// JOIN NOTES 
// 0. Oncce a thread is started we wait for this thread to fininsh by calling join function on thread object.
// 1. Double join will result into program termination.
// 2. If needed we should check thread is joinable before joining. (using joinable() function)

// DETACH NOTES
// 0. This is used to detach newly created thread from the parent thread. 
// 1. Always check before detaching a thread that it is joinable ohterwise we may end up double detaching and 
//	  double detach () will result into program termintaion.
// 2. If we have detached thread and main function is returning them the detached thread execution is suspended.

// NOTES:
// Either join()or detach() should be called on thread object, otherwise duirng thread object's destuctor it will
// terminate the program . Because inside destructor it check if thread is still joinable ? if yes hten it terminates the program.





#include<bits/stdc++.h>
using namespace std; 
using namespace chrono;

void run (int count){
	// std::this_thread::sleep_for(chrono::seconds(3));
	while(count--> 0)
		cout << "Utsav" << endl;
	// put these the thread on sleeping for three secodn
}
int main(){
	  std::thread t1(run,10);
	  cout << "main()" << endl;
	  // join function use cases 
	  // t1.join();
	  // if(t1.joinable())
	  // t1.join();

	  // detach fucntion use cased in the threading 
	  t1.detach();
	  if(t1.joinable())
	   t1.detach();

	  cout << "main() after"<<endl;
	  return 0 ; 	
}