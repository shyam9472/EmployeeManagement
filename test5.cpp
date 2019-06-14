#include<iostream>
using namespace std;
class test{
private:
    int a,b;
public:
  test() {}
  test(int a , int b){
    this->a = a;
    this->b = b;
  }
  int add(){
    return a+b;
  }
};
  int main(){
      test t(4,5);
      test t1;
      int q = t1.add();
      cout<<q<<endl;
      return 0;
  }
