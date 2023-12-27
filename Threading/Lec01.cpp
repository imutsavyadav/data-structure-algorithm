// TOPIC: Introduction to thread in c++ (C++11)

// QUESTIONS
// 1. What do you understand by thread and give one example in C++?

// ANSWER
// 0. In evey application there is a default thread which is main()  in side this we create other threads.
// 1. A Thread is also knowns as lightweight process. Idea is achieve parallelism by divinding a process into multiple threads.
// 		For example:
// 		(a) The browser has multiple tabs that can be different threads. 
// 		(b) MS Word mult be using multiple threads, one thread to format the text , another thread to process inputs (spell checker)
// 		(c) Visual Studio code editor would be using threading for auto completing the code. (Intelligence)

// WAYS TO CREATE THREADS IN C++11
// 1. Function Pointers
// 2. Lambda Functions
// 3. Functors 
// 4. Memeber Funcitons 
// 5. Static Member functions

// REQUIREMENT
// Find the additon of all odd number from 1 to 1900000000 and all even number from 1 to 1900000000



#include<iostream> 
#include<thread>
#include<chrono>
#include<algorithm>
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;

ull OddSum=0;
ull EvenSum=0;

void findEven(ull start,ull end){
    for(ull  i=start;i<=end;++i){
        if((i&1)==0){
            EvenSum+=i;
        }
}
   }


void findOdd(ull start,ull end){
    for(ull i=start;i<=end;++i){
        if((i&1)==1){
            OddSum+=i;
        }
}
   }


int main(){

    ull start=0, end=190000000;

    auto startTime = high_resolution_clock::now();

    std::thread t1(findOdd,start,end);
    std::thread t2(findEven,start,end);

    t1.join();
    t2.join();

    // findOdd(start,end);
    // findEven(start,end);

    auto stopTime = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stopTime-startTime);
    cout <<"OddSum: " << OddSum << endl;
    cout <<"EvenSum: " << EvenSum << endl;
    cout <<"Sec: " << float(duration.count())/1000000 << endl;



    return 0 ; 
 }

                         
                          



















