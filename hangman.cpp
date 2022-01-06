#include <bits/stdc++.h>
using namespace std;
string gamestring;
int totalgausedletters;

bool isPresent(char gussedletter,string givenstring){
    bool ans=false;
    for(int i=0;i<givenstring.length()*2;i+=2){
        if(givenstring[i/2]==gussedletter){
            ans=true;
            gamestring[i]=gussedletter;
            totalgausedletters++;
        }
    }
    return ans;
}

int main() {
	string givenstring="gourav";
	 totalgausedletters=0;
	gamestring="";
    bool pressedletters[26]={false};
	for(int i=0;i<givenstring.length();i++){
	    gamestring+="_ ";
	}
	cout<<gamestring<<endl;
	int lifes=5;
	while(lifes){
	    cout<<"Guess the letter"<<endl;
	    cout<<"You have total "<<lifes<<" lifes"<<endl;
	    char gausedLetter;cin>>gausedLetter;
        int indexofpressedkey=(int)gausedLetter-97;
        if(pressedletters[indexofpressedkey]==false){
            pressedletters[indexofpressedkey]=true;
	        if(!isPresent(gausedLetter,givenstring)){
	            lifes--;
	            cout<<"oops wrong letter try harder"<<endl;
	        }
	        else{
	            if(totalgausedletters!=givenstring.length()){
	                cout<<"You have guessed the correct letter here is the updated word"<<endl;
	                cout<<gamestring<<endl;
	            }
	            else{
	                cout<<"Wow you have guessed it right"<<endl;
	                cout<<gamestring<<endl;
	                break;
	            }
	        }
            if(lifes==0){
	            cout<<"Game Over"<<endl;
	        }
        }
	    else{
            cout<<"You have already pressed this key"<<endl;
        }
	}
	return 0;
}
