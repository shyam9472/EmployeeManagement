#include<iostream>

using namespace std;
static int count;
class A {
	
	public :
		A()
		{
			count = 0 ;
		}
		void display() {
			cout<<endl<<"hello display"<<endl;
			count++;		
		}
		
		void f2(){
			cout<<endl<<"hello f2"<<endl;
			count++;
		}
		
		void showCount() {
			cout<<endl<<count<<endl;
		}
};

int main() {
	A b;
	A a;
	a.display();
	a.f2();
	b.display();
	b.f2();
	a.showCount();
}
