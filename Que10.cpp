#include<iostream>
#include<string>

using namespace std;

void puzzle(string str){
	int attempt = str.length()+1;	
	while(attempt>0){
		char n;
		int count = 0;		
		cout<<"Enter the character"<<endl;
		cin>>n;
		for(int i = 0; i < str.length(); i++){
			if(str[i] == n){
				count++;
			}
		}
		if(count>0){
			cout<<"Good guess"<<endl;
		}
		else{
			cout<<"wrong guess!! please try again."<<endl;			
			attempt--;
			if(attempt>0)
			cout<<"Only "<<attempt<<"attempts left"<<endl;
			else
			cout<<"Game Over!!!!"<<endl;		
		}
	}	
}

int main() {
	string s;
	cout<<"Enter the string."<<endl;
	cin>> s;
	cout<<"Here Starts the game of guessing !!!!"<<endl<<endl;
	puzzle(s);
	return 0;
}
