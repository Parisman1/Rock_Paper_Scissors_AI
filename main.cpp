#include "head.h"
#include <iostream>
#include <vector>
//#include <>

using namespace std;

int main()
{
	Game game = Game();
	bool start = false;
	string ans;
	
	cout << "Generic welcome message" << endl;

	while(!start){
		cout << "Are you ready to play rock paper scissors? (Y/N)" << endl;
		cin >> ans;

		if(ans == "Y"){start = true;}
	}

	while(1){
		game.play_round();
		

		cout << "----------------Current score----------------" << endl;
		cout << "----You : " << game.Get_number_pw() << " ----" << endl;
		cout << "----Them: " << game.Get_number_aw() << " ----" << endl;
		cout << "----Ties: " << game.Get_number_ties() << " ----" << endl;

	}


	return 0;
}