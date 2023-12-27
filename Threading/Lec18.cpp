// Topic: Sleep and Wait 

// Sleep
// "I'm done with my timeslice, and please don't fiveme another one for
//  one for at least n milisecond." The OS doesn't even try to schedule the
// 	sleeping thread unitl requested time has passed 

// Points
// 1. It will Keep the lock and sleep. 
// 2. Sleep is directly to thread, it is a thread fucntion. 

// Wait
// "I'm done with my timeslice. Don't give me another timeslice until somecalls 
//  notify()." As with sleep(), the OS won't even try to schedule your task unless
// 	someone call notify() (or one of a few other wakeup scenarios occurs.)

// Points
// 1. It release the lock and wait. 
// 2. Wait is on contion variable, it is like there is a condiotn variable, 
// 		in a thread and wait is applied to that CV but it ends up puting there in 
// 			wating state.











