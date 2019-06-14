#include<iostream>
#include<string>
using namespace std;

int main(){
  string a,phone;
  cout<<"Enter the line";
  getline(cin, a);
  cout<<"Now enter the phone number";
  getline(cin,phone);
  cout<<endl<<a<<endl<<phone;
  return 0;
}
