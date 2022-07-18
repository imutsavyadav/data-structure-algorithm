#include<bits/stdc++.h>
using namespace std ; 
// problem on dynamic programing 
// flow 
// 0 - 1 knapSack  -> problem statemet , identification , simmilarity , code
// total 6 variation on the 0 - 1 knapsack 
// 1 -> subset sum problem 
// 2 -> equal sum porblem 
// 3 -> count subset sum problem 

int knapSackRec(int wt[] , int val[] , int W, int n);

int kanpSackMem(int wt[], int val[] , int W , int n);

int knapSackTop(int wt[] , int val[] ,int W, int n);

int main(){
    // recurcive code for 0-1 knapSack
    // step 1 :- base condintion -> think about the samlest or largest valid i/p
    // step 2 :- choice diagram -> code the chice diagram 

    // input of the knapsack funtion.
    int n ;  cin>> n; 
    // size of the array 
    // which have to property 
    // 1-> weight array 
    // 2-> value array  
    int wt[n];
    int val[n];

   
    // capacity of the knapSack 
    
    for(int i = 0 ; i< n ; i++){
        cin>> wt[i];
    }
    for(int i  = 0 ; i< n ;i++){
        cin >> val[i];
    }
     int W ; cin>>W;

   cout << knapSackRec(wt,val,W,n);
}

// return the max profit fit in the capacity of the knapSack W 
int knapSackRec(int wt[] , int val[] , int W, int n){
     // base condtion 
     if(n==0 || W==0){
         // no item in the array have profit is zero.
         // with no capacity of kanpSack the profit is zero.
         return 0 ; 
     }

     // choice diagram code
     // move from the last index and check 
     // 1 -> wt of the last item is less then of equal to Capcity W or not
     // 2 -> if it is than have two choice include that item or not inclucde that item 
     // 3 -> if not than item is not included in the knapSack.

     if(wt[n-1]<=W){
         // include or not include
         return max(val[n-1]+knapSackRec(wt,val,W-wt[n-1],n-1),knapSackRec(wt,val,W,n-1));
     }
     else{
         return knapSackRec(wt,val,W,n-1);
     }
     
}

int kanpSackMem(int wt[], int val[] , int W , int n){
    // just simply two line of code in the recursive code 
    // to memorise it 
    // DP = Rec code + Storage --> memorisation technique

    // for storage we create a matrix t[n+1][W+1]
    // to store value of subproblem which used in future subproblem with same input
    // input of the matrix is the changabel input in the recursive code
    // and initialize all the value of matrix with -1 

    vector< vector<int> >t(n+1,vector<int>(W+1,-1));

   // same base condition in the rec code

   if(n==0 || W==0){
       return 0 ; 
   }
   
   // check that particular value is previously calculated or not

   if(t[n][W]!=1){
       return t[n][W];
   }

    if(wt[n-1]<=W){
         // include or not include
          t[n][W] = max(val[n-1]+kanpSackMem(wt,val,W-wt[n-1],n-1),kanpSackMem(wt,val,W,n-1));
     }
     else{
          t[n][W] = kanpSackMem(wt,val,W,n-1);
     }

     return t[n][W];

}

int knapSackTop(int wt[] , int val[] ,int W, int n){
    // this is also called the real DP 
    // here we totaly omit the recurcive call 

    // conversion of rec code  to top down code
    // step 1: ->  base cond change to initialization of matrix 
    // step 2: ->  choice digram fucntion call change to matrix value

    // here matrix is same as the memoriation case but with special property
    // means particular value subproblem answer store in the particular cell

    // final answer is the last cell of the matrix is t[n][W]

    vector< vector<int> >t(n+1,vector<int>(W+1,-1));

    // intialization :-> by the help of nested for loop 
    //                   n convert with i -> indexes of array
    //                   W convert with j -> Capacity of the knapSack

    for(int i = 0 ; i< n ; i++){
        for(int j = 0 ; j< W ; j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }
    }

    // choice diagram code :-> by the help of nested for loop 
    //                         code for all subproblem answer value 
    //                         start with index 1 in i and j

    for(int i = 1 ; i< n ; i++){
        for(int j = 1 ; j< W ;j++){
            if(wt[i-1]<=j){
                // include or not include
                t[i][j] = max( val[i-1]+t[i-1][j-wt[i-1]] , t[i-1][j] );
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][W];

}