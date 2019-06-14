#include<iostream>

using namespace std;

int main() {
	int i = 0;
	int j = 0;
	for(i =0 ; i<5 ; i++)
	{
		if(i%2!=0){
			cout<<endl;		
		}
		else{
			for(int j = 0 ; j<9; j++){

			if( j>=(9/2)-i && j<=(9/2)+i){
				if(j%2==0){
					cout<<"*";		
				}
				else{
					cout<<" ";		
				}
			}
			else{
				cout<<" ";	
			}		
		
		}
		cout<<endl;		
		}		 
	}

	cout<<endl<<endl<<endl;
	cout<<"Enter the length of pattern.";
	int n;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		int a = 65;
		for(int j = 0;j<i+1; j++) 
		{
		cout<<(char)a;
		a =a+1;				
		}
		cout<<endl;	
	}
	return 0;
}

	



