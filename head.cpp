#include "head.h"

	Game::round::round(){
		ai_win = false;
		i_win = false;
		tie = false;
	}

	void Game::round::Set_winner(int win){
		if(win == 0){ // robot win
			ai_win = true;
			i_win = false;
		}
		else if(win == 1){ // player win
			ai_win = false;
			i_win = true;
		}
		else{
			ai_win = false;
			i_win = false;
			tie = true;
		}
	}

	void Game::round::Set_choices(int P, int A){
		player = P; // player == players choice
		Ai = A; // Ai == ai's choice
	}

	bool Game::round::Get_winner(){
		if(ai_win == true){
			return true;
		}
		return false;
	}

	int Game::round::Get_Ai_choice(){
		return Ai;
	}

	int Game::round::Get_Player_choice(){
		return player;
	}

	Game::Game(){
		number_wins_Ai = 0;
		number_wins_player = 0;
		number_ties = 0;

		for(int i=0;i<33;i++){//0-32 are for Rock
			chance.push_back(0);
		}
		for(int i=33;i<67;i++){//33-66 are for Paper
			chance.push_back(1);
		}
		for(int i=67;i<100;i++){//67-98 are for scissors
			chance.push_back(2);
		}
	}

	void Game::play_round(){
		int ans = 0;
		int robo_ans = 0;

		do{	
			cout << "Rock (0)" << endl;
			cout << "Paper (1)" << endl;
			cout << "Scissors (2)" << endl;
			cout << "SHOOT!" << endl;
			cout << "exit(3)" << endl;
			cin >> ans;
			if(ans == 3){
				exit(0);
			}
			if(ans == 5589663502){
				//Debug_Mode();
			}
		}while(ans < 0 || ans > 2);

		//robot brain shit 
		robo_ans = Brain();

		decide_winner(ans, robo_ans);
	}

	//R(0) > S(2) || P(1) > R(0) || S(2) > P(1)
	void Game::decide_winner(int P, int A){
		temp = round();
		if(P == 0){
			if(A == 0){ // TIE
				temp.Set_choices(0, 0);
				temp.Set_winner(2);
				rounds.push_back(temp);
				number_ties++;
			}
			if(A == 1){ // AI
				temp.Set_choices(0, 1);
				temp.Set_winner(1);
				rounds.push_back(temp);
				number_wins_Ai++;
			}
			if(A == 2){ // HUMAN
				temp.Set_choices(0, 2);
				temp.Set_winner(0);
				rounds.push_back(temp);
				number_wins_player++;
			}
		}
		if(P == 1){
			if(A == 0){ // HUMAN
				temp.Set_choices(1, 0);
				temp.Set_winner(0);
				rounds.push_back(temp);
				number_wins_player++;
			}
			if(A == 1){ // TIE
				temp.Set_choices(1, 1);
				temp.Set_winner(2);
				rounds.push_back(temp);
				number_ties++;
			}
			if(A == 2){ // AI
				temp.Set_choices(1, 2);
				temp.Set_winner(1);
				rounds.push_back(temp);
				number_wins_Ai++;
			}
		}
		if(P == 2){
			if(A == 0){ // AI
				temp.Set_choices(2, 0);
				temp.Set_winner(1);
				rounds.push_back(temp);
				number_wins_Ai++;
			}
			if(A == 1){ // HUMAN
				temp.Set_choices(2, 1);
				temp.Set_winner(0);
				rounds.push_back(temp);
				number_wins_player++;
			}
			if(A == 2){ // TIE
				temp.Set_choices(2, 2);
				temp.Set_winner(2);
				rounds.push_back(temp);
				number_ties++;
			}
		}
	}

	int Game::choose_rand(vec1 C){
		srand(time(NULL));

		int P = rand() % 100;

		return C[P];
	}

	int Game::Brain(){
		int ans = 0;

		// need to scroll through the list of past games
		// and check to see what we played.
		// what they played
		// and the outcome
		// and base the next move based on what has worked / "thinking ahead logic" 
		

		if(rounds.size() == 0){
			ans = choose_rand(chance);
		}


		

		return ans;
	}