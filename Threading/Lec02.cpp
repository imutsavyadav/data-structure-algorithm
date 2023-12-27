#include<bits/stdc++.h>
using namespace std ; 
using namespace chrono;

// TOPIC : Type of thread creation in C++11
// There are 5 different types we can create thread in C++11 using Callable Obects.

// NOTE : 
// If create multiple Thread at same it is not guarated which one is start first. 


// // 1 Function Pointer 

void fun(int x ){
	while(x-- >0){
		cout << x << endl;
	}
}

int main(){
	std::thread t(fun , 10) ; 
	t.join();
	return 0 ; 
}


// 2 Lamda function 
// Example 

int main() {

	// Lambda funciton
	auto fun = [](int x){
		while(x-- >0){
			cout << x << endl;
		}
	};

	std::thread t(fun,10);

	// we can also pass this lamda call inside the thread 

	std::thread t1([](int x){
		while(x-- >0){
			cout << x << endl;
		}
	},11);

	t.join();
	t1.join();	

	return 0 ; 

}


// // 3 Functor (Funciton Object)

class Base{
	public: 
		// Here we create a functor in the class 
		// We overloadint the operator than it is nothing but a functor
		// and this particular function is treated as callable object
		void operator()(int x){
			while(x-- >0){
				cout << x << endl;
			}
		}	

};


int main(){
	// Creation of the Thread  and pass the f
	std::thread t((Base()),10);
	t.join();
	return 0 ; 
}









// 4 Non Static Member funciton 


class Base{
	public:
		void run(int x){
			while(x-- >0){
				cout << x << endl ; 
			}
		}
};

int main(){
	// So This is the non static member function so you need an object  to call it.
	Base b; 
	// Here be have to provide the 3 things 
	// 1-> address of the member function 
	// 2-> address of the object 
	// 3-> other the parameter part
	std::thread t(&Base::run,&b,11);
	t.join();
	return 0 ; 
}



// 5 Static Member function 

class Base{
	public:
		static void run(int x){
			while(x-- >0){
				cout << x << endl;
			}
		}
};


int main(){
	// So this the static member function No need of an obect to call it.

	// Here we pass simply the address of the funtion in the thread
	// and other is the parameter part

	std::thread t(&Base::run , 10);
	t.join();

	return 0 ; 
}



