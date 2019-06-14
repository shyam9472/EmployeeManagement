#include<iostream>
//#include<strings>

using namespace std;

int main() {
	char str1[100];
	cout<<"Enter the string : "<< endl;
	cin>>str1;
	string str(str1);
	cout<<str;
	int l = str.length();
	cout<<endl<<l;
	cout<<str[3];
	str[3] = 't';	
	cout<<str;
	return 0;
}
