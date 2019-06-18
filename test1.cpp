#include <thread>
#include <iostream>
#include <string>

using namespace std;

void threadFunc(){
	cout<<"Welcome to thread Function."<<endl;
}

int main(){
	thread func(threadFunc);
	if(func.joinable()){
		cout<<"Attaching the thread."<<endl;
		func.join();
	}
	else{
		cout<<"The thread is detached.";
	}
	cout<<"Now you are in Main function.";
	return 0;
}