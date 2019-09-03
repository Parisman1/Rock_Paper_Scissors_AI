#ifndef head_h
#define head_h

#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Game
{
	private:
	
		typedef vector<class round> vec0;
		vec0 rounds;

		int number_wins_player;
		int number_wins_Ai;
		int number_ties;

		typedef vector<int> vec1;// each chance starts as a one and can be 
		vec1 chance; // increased or decreased by magic

	public:
	
		Game();
		void play_round();
		void decide_winner(int, int);
		int Get_number_pw(){return number_wins_player;}
		int Get_number_aw(){return number_wins_Ai;}
		int Get_number_ties(){return number_ties;}
		int choose_rand(vec1);
		int Brain();
};

class round{
		private:
			bool ai_win;
			bool i_win;
			bool tie;
			int player;
			int Ai;
		public:
			round();
			void Set_winner(int);
			void Set_choices(int, int);

			bool Get_winner();
			int Get_Ai_choice();
			int Get_Player_choice();
	};

#endif