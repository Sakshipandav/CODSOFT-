
#include <iostream>
using namespace std;

     void check(int a,int b)
  {
      if(a>b)
      {
          cout<<"Too high!!!"<<endl;
      }
      if(b>a)
      {
          cout<<"Too low!!!"<<endl;
      }
  }
    
int main() {

  int a,b=78;
  while (a!=b)
  {
  cout<<"Enter a number:- ";
  cin>>a;
  
check(a,b);
  
  }
  
  cout<<"Congratulations!!! You guessed it right."<<endl;
    return 0;
}
