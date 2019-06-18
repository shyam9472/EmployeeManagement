#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

class puzzle{
  int player1 , player2;
  string str;
public:
  puzzle(){
    this->player1 = 0;
    this->player2 = 0;
  }
  void incrementPlayer1(){
    this->player1 = this->player1 + 1;
  }
  void incrementPlayer2(){
    this->player2 = this->player2 + 1;
  }

  int getPlayer1(){
    return this->player1;
  }

  int getPlayer2(){
    return this->player2;
  }
  void setString(){
    cout<<"Enter the string "<<endl;
    cin>>this->str;
  }

  int game(){
    int res;
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
        res = 0;
  		}
  		if(countAll == str.length()){
  			cout<<endl<<"Congrats you have won!!!!\nThe guessed word is : "<<str<<endl;
        res = 1;
  			break;
  		}
    }
    return res;
  }
};

int main(){
  again:
  puzzle p1;
  int n, point;
  cout<<"Enter the number of games you want to play."<<endl;
  cin>>n;
  for(int i =0 ; i< n ;i++){
    point = 0;
    cout<<"First player: Enter the string."<<endl;
    p1.setString();
    system("clear");
    cout<<"Second player: Here you go."<<endl;
    point =  p1.game();
    // cout<<point;
    if(point == 0){
      p1.incrementPlayer1();
    }
    else{
      p1.incrementPlayer2();
    }
    point = 0;
    cout<<"Second player: Enter the string."<<endl;
    p1.setString();
    system("clear");
    cout<<"First player : Here you go."<<endl;
    point =  p1.game();
    // cout<<point;
    if(point == 0){
      p1.incrementPlayer2();
    }
    else{
      p1.incrementPlayer1();
    }
  }
  tiebreaker:
  cout<<"The final score is \n Player 1 : "<<p1.getPlayer1()<<"\nPlayer 2 : "<<p1.getPlayer2()<<endl;
  if(p1.getPlayer1() >> p1.getPlayer2()){
    cout<<"Player 1 is the final winner . Congratulations Player 1"<<endl;
  }
  else if(p1.getPlayer2() >> p1.getPlayer1()){
    cout<<"Player 2 is the final winner . Congratulations Player 2"<<endl;
  }
  else{
    int p;
    cout<<"This appears to be a tie "<<endl<<"Do you want a tie breaker!!!"<<endl<<"Press 1 for tiebreaker.\nPress 2 to play new game.\nPress 3 to exit.";
    cin>>p;
    if(p == 1){
      point = 0;
      cout<<"First player: Enter the string."<<endl;
      p1.setString();
      system("clear");
      cout<<"Second player: Here you go."<<endl;
      point =  p1.game();
      // cout<<point;
      if(point == 0){
        p1.incrementPlayer1();
      }
      else{
        p1.incrementPlayer2();
      }
      point = 0;
      cout<<"Second player: Enter the string."<<endl;
      p1.setString();
      system("clear");
      cout<<"First player : Here you go."<<endl;
      point =  p1.game();
      // cout<<point;
      if(point == 0){
        p1.incrementPlayer2();
      }
      else{
        p1.incrementPlayer1();
      }
      goto tiebreaker;
    }
    if(p == 2){
      goto again;
    }

  }
}
