#include<iostream> 
#include<map> 

using namespace std; 
  
int main() 
{ 	
	int a[50],n;
        map< int, int > mp; 
	map<int, int>::iterator it ; 	
	cout<<"Enter the numbers of elements to be entered : ";
	cin>>n;
	cout<<"Enter the elements : ";
	for(int i =0 ; i < n; i++){
		cin>>a[i];
	}
	for(int i = 0; i<n;i++){
		int count = 1;		
		for(int j = 0 ; j<n ; j++){
			if(a[i] == a[j] && i!=j){
				count++;			
			}
		}
		if(i == 0){
			mp[a[i]] = count;
		}
		else{
			it = mp.find(a[i]);
			if(it == mp.end()) 
			         mp[a[i]] = count;
		}
	}
	int size = mp.size();
	  for (map<int,int>::iterator it=mp.begin(); it!=mp.end(); ++it){
		cout<<"The frequency of "<< it->first <<" is "<<it-> second<<endl;
	}
 
}
