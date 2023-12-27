#include<bits/stdc++.h>
using namespace std; 
using namespace chrono;

int main(){

	int n ; cin >>n ; 
	int arr[n] ; 
	for(int i = 0 ; i< n ; i++) cin >> arr[i];
	char ch[n] ; 
	for(int i = 0 ; i< n ; i++) cin >> ch[i] ; 

	map<int,char> mp ; 

	for(int i =0 ; i < n ; i++){

		mp [ arr[i] ]  = ch[i] ; 
	}
	pair<const int,char>*it ;
	for(auto i : mp ){
		if(i.first == 2){
			it = &i ; 
		}
	}


	auto it1 = mp.find(3) ; 

 	cout << &it  << endl;

 	cout << &it1 ; 


}