#include<iostream>
#include<thread>

using namespace std;

void threadFunc(){
  cout<<"Hello you are in thread"<<endl;
}

int main(){

  cout<<"You are in main"<<endl;
  thread t(threadFunc);
    // t.join();
  cout<<"You are back to main now"<<endl;
  return 0;
}
