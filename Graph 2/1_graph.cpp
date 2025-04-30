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

// representation of graph by adjecency matrix

signed main() { 
    int n , m ; // n - > node  , m -> edge 
    cin >> n >> m ; 

    // 2d array / 2d vector we use macros 

    vvi adjm (n+1 , vi(n+1 , 0));
    // no. of column is n+1 and initialize with zero

    // take input of edges 
    rep(i,0,m){
        int x , y ; 
        // undirected edges therefore 
        cin >>x >> y;

        adjm[x][y] = 1 ; 
        adjm[y][x] = 1 ; 
        // we mark both in adjencency matrix 
    }
    // let see what adjency matrix make 
    rep(i,1,n+1){
        rep(j,1,n+1)
         cout << adjm[i][j] << " ";
     cout << endl;
    }
    
}
/* 
input
7 7
1 2
1 3
2 4
2 5
2 6
2 7
7 3
*/