#include<iostream>

using namespace std;
class pattern{
public:
  void pattern1(){
    int a =5;
    for(int i = 0 ; i < 5 ; i++){
      for(int j = 0; j < 9 ; j++){
        if( j == i || j == 8-i){
          cout<<a;
        }
        else{
          cout<<"_";
        }
      }
      a = a-1;
      cout<<endl;
    }
  }

  void pattern2(){
    int a = 1;
    for(int i =0 ; i<4 ; i++){
      for(int j = 0 ; j<4; j++){
        if(j >= 3-i){
          cout<<a;
          a = a+1;
        }
        else{
          cout<<" ";
        }
      }
      cout<<endl;
    }

  }


  void pattern3(){
    int a =5;
    for(int i = 0 ; i < 5 ; i++){
      for(int j = 0; j < 9 ; j++){
        if( j < i+1 || j > 7-i){
          cout<<"*";
        }
        else{
          cout<<" ";
        }

    }
      cout<<endl;
    }
  }
};
int main(){
  pattern p;
  p.pattern1();
  cout<<endl<<endl;
  p.pattern2();
  cout<<endl<<endl;
  p.pattern3();
}
