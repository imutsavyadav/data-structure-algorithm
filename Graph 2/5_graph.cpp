#include<bits/stdc++.h>
using namespace std; 

#define vi  vector<int>
#define vvi vector<vi> 
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a ; i<b ; i++)
#define repi(i,a,b) for(i=a ; i!=b ; i++)
#define ff first 
#define ss second 
#define setBits(x) builtin_popcount(x)

const int N = 1e5+2 , MOD = 1e9+7 ;
// array of vector of size N for the adjecency list. 

vector<int> adj[N];

// Topological Sort 

int main(){
    int n , m ; 
    cin >> n >> m ; 
    vector <int> indeg(n,0); 

    int x,y ; 
    rep(i,0,m){
        cin>>x>>y;
        adj[x].push_back(y);
        // adj[y].push_back(x);  this line is not conclude in 
        // directed aAcyclic graph
        indeg[y]++; 
    }

    // use the Queue dataStructure for topological sort
    // and firt reach to the end node of the graph 
    // and print the node which have the zero indgre
    // and subtract all connectin node indegree by one and move up

    queue<int>pq;
    for(int i=0 ; i<n ; i++){
        if(indeg[i]==0)
        pq.push(i);
    }
     
     int cnt = 0 ; 
    while(!pq.empty()){
        cnt++;
        int x = pq.front();
        pq.pop();
        cout << x << " ";
            //subtracted the indegre 
            for(auto it : adj[x]){
                indeg[it]--;
                if(indeg[it]==0)
                    pq.push(it);
            }
    }

      
}

// 5 5
// 0 2
// 0 3
// 2 3
// 1 4 
// 1 3
