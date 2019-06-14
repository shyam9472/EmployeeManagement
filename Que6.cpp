#include<iostream>
#include<string>
using namespace std;

void encrypt(string str){
	char temp;

	int i = 0;	
	while(i<str.length()-1){		
		temp = str[i];
		str[i] = str[i+1];
		str[i+1] = temp;
		i = i+2;		

	}

	int n = str.length();
	for(int i =0 ; i < n/2 ; i++) {
		temp = str[i];
		str[i] = str[n-1-i];
		str[n-1-i] = temp;
	}
	int a[100];
	for(int i = 0 ; i<n; i++){
		a[i] = (int)str[i];
	}
	cout<<"The encrypted string is : \t";
	for(int i = 0 ; i<n; i++){
		cout<<a[i];
	}
	cout<<endl;
}

void decrypt(int a[],int n){
	string s;
	char temp;
	for(int i = 0 ; i < n ; i++){
		s = s + (char)a[i];
		//cout<<s[i]<<(char)a[i];
	}
	//cout<<s;
	for(int i =0 ; i < n/2 ; i++) {
		temp = s[i];
		s[i] = s[n-1-i];
		s[n-1-i] = temp;
	}

	int i = 0;	
	while(i<n-1){		
		temp = s[i];
		s[i] = s[i+1];
		s[i+1] = temp;
		i = i+2;		

	}	
	
	cout<<"The dencrypted string is : \t"<<s<<endl;
}
int main() {
	int i;
	while(true){
	cout<<"Choose your operation : \n1.Encryption\n2.Decryption\n3.Exit"<<endl;
	cin>>i;
	if(i == 1){
		char s[100];
		cout << "Enter the string to be Encrypted: ";
		cin >> s;
		string str(s);
		encrypt(str);	
	}
	if(i == 2){	
		int a[50],n;
		cout<<"Enter the numbers of elements";
		cin>>n;
		cout<<"Enter the values of elements";
		for(int i = 0 ; i < n ; i++){
			cin>>a[i];
		}
		decrypt(a,n);
	}
	if(i==3) { break;}
	}
	
	return 0;
	
}
