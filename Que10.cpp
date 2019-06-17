#include <iostream>
#include <string>
#include <stdlib.h>
#include<vector>

using namespace std;

void puzzle(string str){
	int attempt = str.length()+1;
	int countAll;
	char tst[str.length()];
	for(int i = 0; i < str.length() ; i++){
		tst[i] = 'x';
	}
	int rightAttempt = str.length();
	while(attempt>0){
		char n;
		vector<int> v;
  	vector<int>::iterator it;
		int count = 0;
		cout<<endl<<"Enter the character"<<endl;
		cin>>n;
		for(int i = 0; i < str.length(); i++){
			if(str[i] == n){
				count++;
				v.push_back(i);
			}
		}
		if(count>0){
			countAll =0;
			cout<<"Good guess"<<endl;
			rightAttempt--;
			for(it = v.begin(); it<v.end(); it++){
        tst[*it] = n;
		}
		for(int i = 0; i<str.length(); i++){
			cout<<tst[i];
		}
		for(int i = 0 ; i<str.length();i++){
			if(tst[i] == str[i]){
				countAll++;
			}
		}
		}
		else{
			cout<<"wrong guess!! please try again."<<endl;
			attempt--;
			if(attempt>0)
			cout<<"Only "<<attempt<<"attempts left"<<endl;
			else
			cout<<"Game Over!!!!\nThe word you were looking for was : "<<str<<endl;
		}
		if(countAll == str.length()){
			cout<<endl<<"Congrats you have won!!!!\nThe guessed word is : "<<str<<endl;
			break;
		}
	// 	if(rightAttempt == 0)
	// 	{
	// 		cout<<"Congrats you have won!!!!\nThe guessed word is : "<<str<<endl;
	//
	//
	// 	break;
	// }

	}
}

int main() {
	string s;
	cout<<"Enter the string."<<endl;
	cin>> s;
	system("clear");
	cout<<"Here Starts the game of guessing !!!!"<<endl<<endl;
	puzzle(s);

	return 0;
}
