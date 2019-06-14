#include<iostream>

using namespace std;

int main() {
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
