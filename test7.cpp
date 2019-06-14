#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

int main()
{
	int num;
	// bool valid = false;

		// valid = true; //Assume the cin will be an integer.
    try{
		cout << "Enter an integer value: " << endl;
		cin >> num;

		if(cin.fail()){
      throw 20;
    } //cin.fail() checks to see if the value in the cin
					//stream is the correct type, if not it returns true,
					//false otherwise.

			// cin.clear(); //This corrects the stream.
			// cin.ignore(); //This skips the left over stream data.
			// cout << "Please enter an Integer only." << endl;
			// valid = false; //The cin was not an integer so try again.
    }
    catch(int e){
      cout<<"Enter in numeric format only";
    }



	cout << "You entered: " << num << endl;

	// system("PAUSE");
	return 0;
}
