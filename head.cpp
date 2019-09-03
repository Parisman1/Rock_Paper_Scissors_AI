#include "head.h"

	round::round(){
		ai_win = false;
		i_win = false;
		tie = false;
	}

	void round::Set_winner(int win){
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

	void round::Set_choices(int P, int A){
		player = P; // player == players choice
		Ai = A; // Ai == ai's choice
	}

	bool round::Get_winner(){
		if(ai_win == true){
			return true;
		}
		return false;
	}

	int round::Get_Ai_choice(){
		return Ai;
	}

	int round::Get_Player_choice(){
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
			cout << "Rock (1)" << endl;
			cout << "Paper (2)" << endl;
			cout << "Scissors (3)" << endl;
			cout << "SHOOT!" << endl;
			cout << "exit(0)" << endl;
			cin >> ans;
			if(ans == 0){
				exit(0);
			}
			if(ans == 5589663502){
				//Debug_Mode();
			}
		}while(ans < 1 || ans > 3);

		cout << "You played ";

		switch(ans){
			case 1:
				ans = 0;
				cout << "Rock!" << endl;
			break;

			case 2:
				ans = 1;
				cout << "Paper!" << endl;
			break;
			
			case 3:
				ans = 2;
				cout << "Scissors!" << endl;
			break;
		}

		//robot brain shit 
		robo_ans = Brain();
		
		cout << "The AI played ";
		switch(robo_ans){
			case 0:
				cout << "Rock!" << endl;
				break;
			case 1:
				cout << "Paper!" << endl;
				break;
			case 2:
				cout << "Scissors!" << endl;
				break;
		}

		decide_winner(ans, robo_ans);
	}
//need to pass in a rounds instance to keep it alive
	//R(0) > S(2) || P(1) > R(0) || S(2) > P(1)
	void Game::decide_winner(int P, int A){
		//tempt = round;
		round tempt = round();
		if(P == 0){
			if(A == 0){ // TIE
				tempt.Set_choices(0, 0);
				tempt.Set_winner(2);
				rounds.push_back(tempt);
				number_ties++;
				cout << "It's a TIE!" << endl;
			}
			if(A == 1){ // AI
				tempt.Set_choices(0, 1);
				tempt.Set_winner(1);
				rounds.push_back(tempt);
				number_wins_Ai++;
				cout << "You LOSE!" << endl;
			}
			if(A == 2){ // HUMAN
				tempt.Set_choices(0, 2);
				tempt.Set_winner(0);
				rounds.push_back(tempt);
				number_wins_player++;
				cout << "You WIN!" << endl;
			}
		}
		if(P == 1){
			if(A == 0){ // HUMAN
				tempt.Set_choices(1, 0);
				tempt.Set_winner(0);
				rounds.push_back(tempt);
				number_wins_player++;
				cout << "You WIN!" << endl;
			}
			if(A == 1){ // TIE
				tempt.Set_choices(1, 1);
				tempt.Set_winner(2);
				rounds.push_back(tempt);
				number_ties++;
				cout << "It's a TIE!" << endl;
			}
			if(A == 2){ // AI
				tempt.Set_choices(1, 2);
				tempt.Set_winner(1);
				rounds.push_back(tempt);
				number_wins_Ai++;
				cout << "You LOSE!" << endl;
			}
		}
		if(P == 2){
			if(A == 0){ // AI
				tempt.Set_choices(2, 0);
				tempt.Set_winner(1);
				rounds.push_back(tempt);
				number_wins_Ai++;
				cout << "You LOSE!" << endl;
			}
			if(A == 1){ // HUMAN
				tempt.Set_choices(2, 1);
				tempt.Set_winner(0);
				rounds.push_back(tempt);
				number_wins_player++;
				cout << "You WIN!" << endl;
			}
			if(A == 2){ // TIE
				tempt.Set_choices(2, 2);
				tempt.Set_winner(2);
				rounds.push_back(tempt);
				number_ties++;
				cout << "It's a TIE!" << endl;
			}
		}
	}

	int Game::choose_rand(vec1 C){
		srand(time(NULL));

		int P = 0;
		P = rand() % 100;

		return C[P];
	}

	int Game::Brain(){
		int ans = 0;

		ans = choose_rand(chance);

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