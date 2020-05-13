// JottoMotto.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>  
#include <iomanip>
#include <algorithm> 
#include "Dictionary.h" 



using namespace std;


struct player{
	string username;
	int score;

};

player topten[10];


int main()
{
	int turns;
	double time;


	string mode;
	string userguess;
	string userjword;
	int guesses;
	int gameover;
	int jotts;
	double modifier;
	char decide;
	decide = 'y';


	do{
		fin.open("topten.txt");
		string STRING;
		int u;
		u = 0;

		while (!fin.eof()) // To get you all the lines.
		{
			getline(fin, topten[u].username); // Saves the line in STRING.
			getline(fin, STRING);
			topten[u].score = atoi(STRING.c_str());
			u++;
		}

		fin.close();

		system("cls");
		time = 0;
		turns = 0;
		clock_t start = clock();
		cout << "What difficulty do you want?"<<endl<<"1 = Easy (All unique letters), 2 = Hard (Same letters) ";
		cin >> mode;
		if (mode == "1"){
			mode = "ezjotto.txt";
			modifier = 1;
		}
		else{
			mode = "jotto.txt";
			modifier = .5;
		}


		aidict ad;
		dict cdict(mode);
		jword ans(cdict.randword());
		gameover = 0;

		do{
			cout << "Enter five letter word to guess: (Give up = 0) ";
			cin >> userguess;
			if (userguess == "0"){

				cout << "You lose! Your word was " << ans.giveup()<<endl;
				gameover = -1;
				break;

			}
			transform(userguess.begin(), userguess.end(), userguess.begin(), toupper);
			
			if (cdict.binsearch(userguess) != -1){
				turns++;
				jotts = ans.getjotts(userguess);
				if (jotts != 999){
					cout << jotts << " jotts" << endl;
				}
				else{
					cout << "You guessed the word correctly! ";
					
					clock_t stop = clock();
					time = (double)(stop - start)/1000;
					cout << "You took " << turns << "turns and " << time << "seconds!"<<endl;
					gameover = 1;
				}


			}
			else{
				cout << "That's not a valid word!"<<endl;

			}


		} while (gameover != 1);

		if (gameover == 1){
			string username;
			int score;
			player temporary;

			cout << "Enter username: ";
			cin >> username;
			score = time*.2*turns*modifier;
			topten[10].score = score;
			topten[10].username = username;
			for (int x = 0; x < 10; x++){
				for (int y = x + 1; y < 11; y++){
					if (topten[y].score < topten[x].score){
						temporary = topten[x];
						topten[x] = topten[y];
						topten[y] = temporary;
					}

				}

			}
		}
		cout << endl << "       KUMMER'S KRAZY TEN" << endl << endl;

		for (int e = 0; e < 9; e++){
			cout << resetiosflags(ios::right) << setfill(' ') << setw(12) << topten[e].username << setiosflags(ios::right) << setw(12) << topten[e].score << endl;

		}

		fout.open("topten.txt");
		for (int a = 0; a < 10; a++){
			fout << topten[a].username << endl;
			fout << topten[a].score << endl;

		}
		fout.close();

		cout << "Continue? (Y/N) ";
		cin >> decide;

	} while (decide != 'n' || decide != 'N');





	return 0;
}

