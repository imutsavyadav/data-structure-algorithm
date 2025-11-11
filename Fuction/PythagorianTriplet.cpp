#include<iostream>
using namespace std;
int main()
{
  int a, b;
  cin>>a>>b;
   void triplet(int, int);
   triplet(a,b);
   cout<<"This is the pythagoras triplet"<<endl;
   cout<<"Between The given no.";
   return 0;
}
void triplet(int N1, int N2){
  for(int i=N1; i<N2; i++){
    for(int j=N1; j<=N2; j++){
      for(int k=N1; k<=N2; k++){
        if(k*k==(i*i+j*j))
        cout<<k<<" "<<i<<"  " <<j<<" " <<endl;
      }
    }
  }
  // int x = max(a, max(b,c));
  // int y, z;
  // if(x == a)
  // {
  //   y=b;
  //   z=c;
  // }
  // else if(x==b){
  //   y=a;
  //   z=c;
  // }
  // else{
  //   y=a;
  //   z=b;
  // }
  // if(x*x==(y*y+z*z))
  // return true;
  // else
  // return false;
  
}
