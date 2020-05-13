#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>

using namespace std;

const char smiley = 1;
const char smil2 = 2;
const char h = 3;
const char d = 4;
const char c = 5;
const char s = 6;

struct card{
	int suit;
	int val;
	string sval;
	string ssuit;
	int score;
};
struct user{
	int score;
	string username;

};
user topten[10];
void wait(int wait_time);
void createdeck(card *deck);
void shuffle(card *deck);
void tostring(card *deck);
void fill(card *deck, card *hand, int handno);
void draw(card *deck, card *hand, int cardno, int deckno);
void output(card *deck, int handno);
void aioutput(card *deck, int handno);
void revealaioutput(card *deck, int handno);
void upoutput(card up);
void replace(card *hand);
void rid(card *hand, int playcard, int handno, card upcard);
void outputtitle();

int main()
{
	ifstream fin;
	ofstream fout;
	card hand1[52];
	card hand2[52];
	card deck[52];
	int cardno;
	int hand1no;
	int hand2no;
	card upcard;
	card playcard;
	int aiwin;
	int uwin;
	int check;
	int userans;
	int suitno[5];
	int aisuitno[5];
	int desuit[5];
	int largest;
	int aisuit;
	int usersuit;
	int bestsuit;
	int playablecard[52];
	int bestcard;
	int userscore;
	int userskip;
	string STRING;
	int u;
	aiwin = 0;
	uwin = 0;
	user temporary;

	createdeck(deck);
	shuffle(deck);
	tostring(deck);

	
	fill(deck, hand1, 0);
	fill(deck, hand2, 8);

	upcard = deck[16];

	cardno = 17;

	hand1no = 8;
	hand2no = 8;
	                               

	

	for (int d = 0; d < 5; d++){
		suitno[d] = 0;
		aisuitno[d] = 0;
	}
	

	for (int e = 0; e < hand1no; e++){
		
		suitno[hand1[e].suit]++;

	}
	for (int f = 0; f < hand2no; f++){
		aisuitno[hand2[f].suit]++;

	}
	userskip = 0;
	u = 0;

	fin.open("topten.txt");
	while(!fin.eof()) // To get you all the lines.
	{
		getline(fin, topten[u].username); // Saves the line in STRING.
		getline(fin, STRING);
		topten[u].score = atoi(STRING.c_str());
		u++;
	}
	fin.close();

	
	do{
		
		outputtitle();
		if (userskip == 0){
			do{

				aioutput(hand2, hand2no);
				upoutput(upcard);
				output(hand1, hand1no);
				check = 0;
				cout << "Which card do you want to play? (-1 for draw) ";
				cin >> userans;
				if (userans == -1){

					for (int a = 0; a < hand1no; a++){
						if (hand1[a].val == upcard.val || hand1[a].suit == upcard.suit){
							check++;

						}

					}
					if (check == 0){
						system("cls");
						outputtitle();
						draw(deck, hand1, hand1no, cardno);
						suitno[hand1[hand1no].suit]++;
						hand1no++;
						cardno++;
						if (cardno == 52){
							cardno = 0;
							shuffle(deck);

						}

					}
					else{
						cout << "You can play a card!" << endl;
						wait(2);
						system("cls");
						outputtitle();

					}
				}
				else{
					if (hand1[userans].val == upcard.val || hand1[userans].suit == upcard.suit || hand1[userans].val == 8){
						upcard = hand1[userans];
						suitno[hand1[userans].suit]--;

						if (hand1[userans].val == 8){
							cout << "Choose your desired suit: (1 = Spades, 2 = Diamonds, 3 = Clubs, 4 = Hearts) ";
							cin >> usersuit;
							upcard.suit = usersuit;
							switch (usersuit){
							case 1: upcard.ssuit = s;
								break;
							case 2: upcard.ssuit = d;
								break;
							case 3: upcard.ssuit = c;
								break;
							case 4: upcard.ssuit = h;
								break;

							}

						}

						rid(hand1, userans, hand1no, upcard);
						hand1no--;
						system("cls");
						
						aioutput(hand2, hand2no);
						upoutput(upcard);
						output(hand1, hand1no);

					}
					else{
						cout << "You can't play that!" << endl;
						wait(2);
						system("cls");
						
						userans = -1;
					}


				}
			} while (userans == -1);
			if (hand1no == 0){
				uwin = 1;
			}

			do{
				cout << "Which card do you want to play? (-1 for end turn) ";
				cin >> userans;
				if (userans != -1){
					if (hand1[userans].val == upcard.val){

						upcard = hand1[userans];
						suitno[hand1[userans].suit]--;

						if (hand1[userans].val == 8){
							cout << "Choose your desired suit: (1 = Spades, 2 = Diamonds, 3 = Clubs, 4 = Hearts) ";
							cin >> usersuit;
							upcard.suit = usersuit;
							switch (usersuit){
							case 1: upcard.ssuit = s;
								break;
							case 2: upcard.ssuit = d;
								break;
							case 3: upcard.ssuit = c;
								break;
							case 4: upcard.ssuit = h;
								break;

							}

						}

						rid(hand1, userans, hand1no, upcard);
						hand1no--;
						system("cls");
						
						aioutput(hand2, hand2no);
						upoutput(upcard);
						output(hand1, hand1no);

					}
					else{
						cout << "You must play a card with a similar value! " << endl;
						wait(2);
						system("cls");
						
						aioutput(hand2, hand2no);
						upoutput(upcard);
						output(hand1, hand1no);
					}



				}


			} while (userans != -1);

			if (hand1no == 0){
				uwin = 1;
			}

			if (uwin == 1){
				break;
			}

			if (upcard.val > 10){
				cout << "Skipped AI!" << endl;
				wait(2);
				system("cls");
				outputtitle();
				continue;
			}
		}
 else{
	 aioutput(hand2, hand2no);
	 upoutput(upcard);
	 output(hand1, hand1no);
	 cout << "User skipped!" << endl;
	 wait(2);
 }
		

		do{
			cout << "Calculating..." << endl;
			wait(2);
			largest = -999;
			for (int z = 0; z < 5; z++){
				desuit[z] = aisuitno[z] - suitno[z];
				if (largest < desuit[z]){
					largest = desuit[z];
				}
			}
			for (int p = 0; p < hand2no; p++){

				playablecard[p] = 0;


			}

			for (int p = 0; p < hand2no; p++){
				if (upcard.suit == hand2[p].suit || upcard.val == hand2[p].val || hand2[p].val == 8){
					playablecard[p] = playablecard[p] + 1000;
				}
				playablecard[p] = playablecard[p] + desuit[hand2[p].suit];
				if (hand2[p].val == 8){
					for (int q = 1; q <= 4; q++){
						if (suitno[q] == 0){
							if (aisuitno[q] > 2){
								playablecard[p] = playablecard[p] + 1000;
								hand2[p].suit = q;
								switch (hand2[p].suit){
								case 1: hand2[p].ssuit = s;
									break;
								case 2: hand2[p].ssuit = d;
									break;
								case 3: hand2[p].ssuit = c;
									break;
								case 4: hand2[p].ssuit = h;
									break;

								}

							}

						}

					}
				}
				if (hand2[p].val > 10){
					playablecard[p] = playablecard[p] + 2;

				}
			}
			bestcard = -1;
			largest = -1000;
			for (int p = 0; p < hand2no; p++){
				if (playablecard[p] > 950){
					if (playablecard[p] > largest){
						playablecard[p] = largest;
						bestcard = p;
					}

				}
			}

			if (bestcard == -1){
				draw(deck, hand2, hand2no, cardno);
				aisuitno[hand2[hand2no].suit]++;
				hand2no++;
				cardno++;
				if (cardno == 52){
					cardno = 0;
					shuffle(deck);

				}

			}
			else{
				upcard = hand2[bestcard];
				aisuitno[hand2[bestcard].suit]--;
				rid(hand2, bestcard, hand2no, upcard);
				hand2no--;
				system("cls");
				
				aioutput(hand2, hand2no);
				upoutput(upcard);
				output(hand1, hand1no);
				wait(2);
				
			}

		} while (bestcard == -1);

		do{
			cout << "Calculating..." << endl;
			wait(2);
			largest = -999;
			for (int z = 0; z < 5; z++){
				desuit[z] = aisuitno[z] - suitno[z];
				if (largest < desuit[z]){
					largest = desuit[z];
				}
			}
			for (int p = 0; p < hand2no; p++){

				playablecard[p] = 0;


			}

			for (int p = 0; p < hand2no; p++){
				if (upcard.val == hand2[p].val){
					playablecard[p] = playablecard[p] + 1000;
				}
				playablecard[p] = playablecard[p] + desuit[hand2[p].suit];
				if (hand2[p].val == 8){
					for (int q = 1; q <= 4; q++){
						if (suitno[q] == 0){
							if (aisuitno[q] > 2){
								playablecard[p] = playablecard[p] + 1000;
								hand2[p].suit = q;
								switch (hand2[p].suit){
								case 1: hand2[p].ssuit = s;
									break;
								case 2: hand2[p].ssuit = d;
									break;
								case 3: hand2[p].ssuit = c;
									break;
								case 4: hand2[p].ssuit = h;
									break;

								}

							}

						}

					}
				}
				if (hand2[p].val > 10){
					playablecard[p] = playablecard[p] + 2;

				}
			}
			bestcard = -1;
			largest = -1000;
			for (int p = 0; p < hand2no; p++){
				if (playablecard[p] > 950){
					if (playablecard[p] > largest){
						playablecard[p] = largest;
						bestcard = p;
					}

				}
			}

			if (bestcard != -1){
				upcard = hand2[bestcard];
				aisuitno[hand2[bestcard].suit]--;
				rid(hand2, bestcard, hand2no, upcard);
				hand2no--;

			}

		} while (bestcard != -1);

		if (upcard.val > 10){
			userskip = 1;

		}
		else{
			userskip = 0;
		}

		wait(2);
		system("cls");

	}while(aiwin == 0);

	if (aiwin = 0){
		cout << "You're a loser!"<<endl;
	}
	else{
		system("cls");
		cout << "You win!"<<endl;
		revealaioutput(hand2, hand2no);
		upoutput(upcard);
		wait(3);
		system("cls");
		
		cout << "Enter name: ";
		cin >> topten[10].username;
		topten[10].score = 0;
		for (int o = 0; o < hand2no; o++){
			topten[10].score = topten[10].score + hand2[o].score;
		}
		for (int x = 0; x < 10; x++){
			for (int y = x + 1; y < 11; y++){
				if (topten[y].score > topten[x].score){
					temporary = topten[x];
					topten[x] = topten[y];
					topten[y] = temporary;
				}

			}

		}
		wait(1);
		system("cls");
		cout << endl<<"       KUMMER'S KRAZY TEN" << endl << endl;
		
		for (int e = 0; e < 9; e++){
			cout << resetiosflags(ios::right)<<setfill(' ') << setw(12) << topten[e].username << setiosflags(ios::right) << setw(12) << topten[e].score << endl;

		}
		

		fout.open("topten.txt");
		for (int a = 0; a < 10; a++){
			fout << topten[a].username << endl;
			fout << topten[a].score << endl;
			
		}
		fout.close();
	}

	system("Pause");
	return 0;
}

void outputtitle(){
	cout << "KUMMER'S KRAZY EIGHTS" << '\n' << endl;


}

void upoutput(card up){
	cout << "-------" << "     " << "-------"<<endl;
	cout << "|" << up.ssuit << "    |" << "     " << "|" << smiley << "    |" << endl;
	cout << "|     |" << "     " << "|     |" << endl;
	cout << "|  " << up.sval << "  |" << "     " << "|  " << smil2 << "  |" << endl;
	cout << "|     |" << "     " << "|     |" << endl;
	cout << "|    " << up.ssuit << "|" << "     " << "|    " << smiley << "|" << endl;
	cout << "-------" << "     " << "-------" << endl;
}


void createdeck(card *deck){
	int cardno;
	cardno = 0;
	for (int i = 1; i <= 4; i++){
		for (int j = 1; j <= 13; j++){

			deck[cardno].suit = i;
			deck[cardno].val = j;
			cardno++;
		}

	}

}


void shuffle(card *deck){
	srand((unsigned)time(NULL));

	int randno;
	card temp;
	for (int i = 0; i < 52; i++){
		randno = rand() % 51;
		temp = deck[i];
		deck[i] = deck[randno];
		deck[randno] = temp;
	}



}


void tostring(card *deck){
	string str;
	for (int i = 0; i < 52; i++){
		str = "";
		switch (deck[i].val){
		case 11: deck[i].sval = "J";
			deck[i].score = 10;
			break;
		case 12: deck[i].sval = "Q";
			deck[i].score = 10;
			break;
		case 13: deck[i].sval = "K";
			deck[i].score = 10;
			break;
		case 10: deck[i].sval = "T";
			deck[i].score = 10;
			break;
		case 1: deck[i].sval = "A";
			deck[i].score = 10;
			break;
		case 8: deck[i].sval = "8";
			deck[i].score = 50;
			break;
		default: deck[i].sval = str + (char)(deck[i].val + '0');
			deck[i].score = deck[i].val;
			break;

		}
		switch (deck[i].suit){
		case 1: deck[i].ssuit = s;
			break;
		case 2: deck[i].ssuit = d;
			break;
		case 3: deck[i].ssuit = c;
			break;
		case 4: deck[i].ssuit = h;
			break;

		}
	}

}
void fill(card *deck, card *hand, int handno){
	for (int i = handno; i < (handno + 8); i++){
		hand[i - handno] = deck[i];

	}


}
void output(card *deck, int cardno){
	for (int i = 0; i < cardno; i++){
		cout << " "<<(i)<<"  ";

	}
	cout << endl; 
	for (int i = 0; i < cardno; i++){
		cout << "--- ";
		
	}
	cout << endl;
	for (int i = 0; i < cardno; i++){
		cout << "|" << deck[i].ssuit<<"| ";
		
	}
	cout << endl;
	for (int i = 0; i < cardno; i++){
		cout << "|" << deck[i].sval << "| ";
		//cout << deck[i].ssuit << deck[i].sval << endl;
	}
	cout << endl;
	for (int i = 0; i < cardno; i++){
		cout << "--- ";

	}
	cout << endl; 

}

void aioutput(card *deck, int cardno){
	for (int i = 0; i < cardno; i++){
		cout << " " << (i) << "  ";

	}
	cout << endl;
	for (int i = 0; i < cardno; i++){
		cout << "--- ";

	}
	cout << endl;
	for (int i = 0; i < cardno; i++){
		cout << "|" << smiley << "| ";

	}
	cout << endl;
	for (int i = 0; i < cardno; i++){
		cout << "|" << smil2 << "| ";
	}
	cout << endl;
	for (int i = 0; i < cardno; i++){
		cout << "--- ";

	}
	cout << endl;
}


void revealaioutput(card *deck, int cardno){
for (int i = 0; i < cardno; i++){
cout << " " << (i) << "  ";

}
cout << endl;
for (int i = 0; i < cardno; i++){
cout << "--- ";

}
cout << endl;
for (int i = 0; i < cardno; i++){
	cout << "|" << deck[i].ssuit << "| ";

}
cout << endl;
for (int i = 0; i < cardno; i++){
	cout << "|" << deck[i].sval << "| ";
}
cout << endl;
for (int i = 0; i < cardno; i++){
cout << "--- ";

}
cout << endl;

}

void draw(card *deck, card *hand, int cardno, int deckno){
	hand[cardno] = deck[deckno];
	
	

}

void rid(card *hand, int playcard, int handno, card upcard){

	for (int i = playcard+1; i < handno; i++){
		hand[i - 1] = hand[i];

	}
	

}
void wait(int wait_time)
{
	long *start_time = new long;
	*start_time = time(0);

	while ((*start_time + wait_time) > time(0)){
	};

	delete start_time;
};