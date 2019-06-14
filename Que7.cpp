#include<iostream>

using namespace std;

int fac(int n) {
	if(n == 1){
		return 1;
	}
	else{
		return n*fac(n-1);
	}
}

int main() {
	int n, res;
	cout<<"Enter the number : ";
	cin>>n;
	res = fac(n);
	cout<<"The factorial of the given number is : "<<res<<endl;
}
