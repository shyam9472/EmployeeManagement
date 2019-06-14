#include<iostream>
#include<string>

using namespace std;
//static int count =0;
void swap(char& a, char& b){
	char temp;
	temp = a;
	a = b;
	b = temp;
}
void permute(string s,int i,int n)
{	
    //count++;
    int j;
    if (i == n)
        cout << s << "\n";
    else
    {
        for (j = i; j < s.length(); j++)
        {
            swap(s[i],s[j]);
            permute(s, i + 1, n);
	    //cout<<s<<endl;
            swap(s[i],s[j]);
        }  
    }
}
int main(){
	string s ;
	cout<<"Enter the String"<<endl;
	cin>>s;
	cout<<"Permutations are :"<<endl;
	permute(s,0,s.length()-1);
	//cout<<count;
	//cout<<s;
	//swap(s[0],s[1]);
	//cout<<s;
	return 0;
}
