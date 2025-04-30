#include<bits/stdc++.h>
using namespace std; 

#define vi  vector<int>
#define vvi vector<vi> 
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a ; i<b ; i++)
#define ff first 
#define ss second 
#define setBits(x) builtin_popcount(x)

const int N = 1e5+2 , MOD = 1e9+7 ;
vi adj[N]; // array of vector define globally .

// Representation of the graph by the Adjecency list

int main (){

	int n , m ; 
	// n is no. of node 
	// m is no. of edges
	cin >> n >> m ; 

	// taking input in the list.
	rep(i , 0 , m) {
		int x , y ; 
		cin >> x >> y ; 
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	cout << "Adjecency list of the above graph is given by : " << endl;

	// output Adjecency list 
	// print 2d vector

	rep(i , 1 , n+1){
		cout << "All connected node through "<<i<<endl;
		cout << i << " -> ";  

		 // for(int x : adj[i])
		 // 	cout << x << " ";
		 // cout << endl ;

		vector <int> :: iterator it ; 
		for(it =adj[i].begin() ; it!=adj[i].end() ; it++)
			cout << *it << " " ;
		 cout << endl ; 
	}

	
}