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

// make an visited array of type bool 

bool vis[N];

// Depth First Search Funtion 
 
 void dfs(int node){
     // first mark visited to that node 
     vis[node] = 1;

     // preOrder print
     // cout<<node<<" ";

     // inOrder - work on that current node
     vector<int> :: iterator it;
     repi(it , adj[node].begin() ,adj[node].end()) {
         if(!vis[*it]){ // if node is node visited otherwise it++
             vis[*it]=1; // mark as visited
             dfs(*it);   // and call recurcively for that node
         }
     }

     // post order 
      cout << node << " ";
 }

int main(){
    int n , m ; 
    cin >> n >> m ; 
    // make vis array set as false
    rep(i,0,N)
    vis[i]=0;

    // take input of the graph as adjecency list 
    int x , y;
    rep(i,0,m){
        cin >> x >> y ; 

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // now call the dfs fuction for the root node ;

    dfs(1);

}