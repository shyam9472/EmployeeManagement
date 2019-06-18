#include <iostream> 
#include <utility> 
#include <vector>
#include <list>
using namespace std; 
  
 void listOp(){
 	list <int> li;
 	
 	int a,n;
 	cout<<"Enter the number of elements you want to add in list."<<endl;
 	for(int i = 0 ; i < n ; i++){
 		cout<<"Enter the element"<<endl;
 		cin>>a;
 		li.push_back(a);
 	}

 	showList(li);

 }

 void showList(list <int> li){
 	list <int> :: iterator it;
 	for(it = li.begin(); it != li.end(); ++it){
 		cout<<*it<<"\t";
 	}
 }

int main() 
{ 

   //  pair <int, char> PAIR1 ; 
  	// vector< pair <int,char> > v;
  	// vector< pair <int,char> >::iterator it;
  	// int a,n;
  	// char b;
  	// cout<<"Enter the number of pairs you want to add.";
  	// cin>>n;
  	// for(int i =0 ; i< n ; i++){
  	// 	cout<<"Enter the int part of the pair."<<endl;
  	// 	cin>>a;
  	// 	cout<<"Enter the char part of the pair."<<endl;
  	// 	cin>>b;
  	// 	PAIR1.first = a; 
   //  	PAIR1.second = b ;
  	// 	v.push_back(PAIR1);
  	// }
     
  	// for(int i = 0 ; i < v.size() ; i++){
  	// 	cout<<v[i].first<<"\t"<<v[i].second<<endl;
  	// }
  	listOp();
    return 0; 
}