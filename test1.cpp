#include<iostream>
#include<vector>
#include<iterator>

using namespace std;
class stl{
public:
  void vec(){
     vector<int> v;
    int i;
    vector<int>::iterator it;
    cout<<"Number of elements in vector"<<endl;
    cin>>i;
    while(i>0){
      int a;
      cout<<"enter the elements"<<endl;
      cin>>a;
      v.push_back(a);
      i--;
    }

    cout<<"size of vector is : "<<v.size()<<endl;

    for(it=v.begin(); it<v.end(); it++){
      cout<<*it<<endl;
    }
  }
};


int main(){
  stl s;
  s.vec();
  return 0;
}
