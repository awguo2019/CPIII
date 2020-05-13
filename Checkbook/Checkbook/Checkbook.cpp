// Checkbook.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void expand(int);

void expand(int value)
{
	const char * const ones[20] = { "zero", "one", "two", "three", "four", "five", "six", "seven",
		"eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
		"eighteen", "nineteen" };
	const char * const tens[10] = { "", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy",
		"eighty", "ninety" };

	if (value<0)
	{
		cout << "minus ";
		expand(-value);
	}
	else if (value >= 1000)
	{
		expand(value / 1000);
		cout << " thousand";
		if (value % 1000)
		{
			if (value % 1000 < 100)
			{
				cout << " and";
			}
			cout << " ";
			expand(value % 1000);
		}
	}
	else if (value >= 100)
	{
		expand(value / 100);
		cout << " hundred";
		if (value % 100)
		{
			cout << " and ";
			expand(value % 100);
		}
	}
	else if (value >= 20)
	{
		cout << tens[value / 10];
		if (value % 10)
		{
			cout << " ";
			expand(value % 10);
		}
	}
	else
	{
		cout << ones[value];
	}
	return;
}

struct user
{
	double amount;
	string username;
	string password;


};

class database
{
public:
	user current[1000];
	int search(database d, string find, int right);
	database sort(database d, int length);

};



int database::search(database d, string find, int right){
	
	int left;
	int middle;
	left = 0;
	while (left <= right){
		middle = (left + right) / 2;
		if (d.current[middle].username == find){
			return middle;
		}
		else if (d.current[middle].username > find){
			right = middle - 1;
		}
		else{
			left = middle + 1;
		}

	}


	return -1;
}

database database::sort(database d, int length){
	user temp;

	for (int i = 0; i < length; i++){
		for (int j = (i + 1); j < length; j++){

			if (d.current[i].username > d.current[j].username){
				temp = d.current[i];
				d.current[i] = d.current[j];
				d.current[j] = temp;

			}

		}

	}
	
	

	return d;
}



int main()
{
	int user;
	string cashmoney;
	ofstream fout;
	ifstream fin;
	string STRING;
	char ans;
	int userno;
	database checkbook;
	int check;
	char action;
	double money;
	int tno;
	double transactions[100];
	double initial;
	double negtest;
	double test;

	double take;
	double put;
	int takeno;
	int putno;

	do{
		
		
		userno = 0;
		fin.open("users.txt");
		while (!fin.eof()) // To get you all the lines.
		{
			getline(fin, checkbook.current[userno].username); // Saves the line in STRING.
			getline(fin, checkbook.current[userno].password);	//gets database
			getline(fin, STRING);
			checkbook.current[userno].amount = atoi(STRING.c_str());
			userno++;
		}
		fin.close();
		userno--;
		checkbook = checkbook.sort(checkbook, userno);


		cout << "Are you a new user or existing? (1 = make account, 2 = log in) ";
		cin >> user;
		
		switch (user){
		case 1: cout << "Enter username, password, and amount in account:  "; //create user
			cin >> checkbook.current[userno].username;
			cin >> checkbook.current[userno].password;
			cin >> checkbook.current[userno].amount;
			checkbook = checkbook.sort(checkbook, userno);
			cout << "Thank you, " << checkbook.current[userno].username << ", for making an account! ";
			userno++;
			checkbook = checkbook.sort(checkbook, userno);
			break;

		case 2: cout << "Enter username: ";
			    cin >> STRING;
				check = checkbook.search(checkbook, STRING, userno);
				if (check != -1){
					cout << "Enter password: ";
					cin >> STRING;
					if (STRING == checkbook.current[check].password){  //user is completely verified
						cout << "Hello, " << checkbook.current[check].username << "! What would you like to do?"<<endl;
						tno = 0;
						initial = checkbook.current[check].amount;
						tno = 0;
						do{
							cout << "Your current balance is $" << checkbook.current[check].amount<<"."<<endl<< "w = Withdraw, d = Deposit, v = View transactions, q = Quit ";
							cin >> action;
							switch (action){

							case 'w': cout << "How much do you want to withdraw? ";
								cin >> money;
								if ((checkbook.current[check].amount - money) > 0){
									checkbook.current[check].amount = checkbook.current[check].amount - money;
									transactions[tno] = -1 * money;
									tno++;
									
									cout << setfill('_') << setw(40) << "" << endl;
									cout << setfill(' ') << "|" << setw(39) <<"212"<< "|" << endl;
									cout << "|" << setw(39) <<setiosflags(ios::left)<< "Kummer Kash" << "|" << endl;
									cout << "|" << setw(39) << setiosflags(ios::left) << "             Date: March 9, 2017" << "|" << endl;
									cout << "|" << setw(10) << setiosflags(ios::left) << "Pay to" << setw(18)<<checkbook.current[check].username<<setiosflags(ios::right)<<"$"<<setw(10)<<money<< "|" << endl;
									cout << "|" << resetiosflags(ios::right);
									expand(money);
									cout << " dollars" << endl;
									cout << setiosflags(ios::right)<<setfill(' ') << "|" << setw(40) << "|" << endl;
									cout << setiosflags(ios::left) << setfill(' ') << "|" << "  For" << setw(14) << checkbook.current[check].username << setiosflags(ios::right)<< setw(20) << "Kummer Korp" << "|" << endl;
									cout << setiosflags(ios::right) << setfill(' ') << "|" << setw(40) << "|" << endl;
									cout << setfill('_') << setw(41) << "" << endl;
									cout << setfill(' ');
								}
								else{
									cout << "You don't have enough money to do that. ";
									checkbook.current[check].amount = checkbook.current[check].amount - 5;
									transactions[tno] = -1 * money;
									tno++;
									
								}
								break;

							case 'd': cout << "How much do you want to deposit? ";
								cin >> money;
								checkbook.current[check].amount = checkbook.current[check].amount + money;
								transactions[tno] = money;
								tno++;
								check;
								break;

							case 'v': cout << "You originally had $"<<initial << endl<<"Transactions: "<<endl;
								for (int b = 0; b < tno; b++){
									if (transactions[b] >= 0){
										cout << "+"<<transactions[b] << endl;
									}
									else{
								
											cout << transactions[b] << endl;
										
									}
							}
								break;

							case 'q': cout << setfill(' ') << setiosflags(ios::left) << setw(12) << "Transaction" << setw(12) << "Amount" << setiosflags(ios::right) << setw(12) << "Balance" << endl;
								cout << setfill('_') << setw(36) << "" << endl;
								test =initial;
								putno = 0;
								takeno = 0;
								put = 0;
								take = 0;
								cout << resetiosflags(ios::right) << setfill(' ') << setw(12) << "Original" << setw(12) << test << setiosflags(ios::right) << setw(12) << test << endl;
								for (int b = 0; b < tno; b++){
									if (transactions[b] >= 0){
										putno++;
										put = put + transactions[b];
										test = test + transactions[b];
										cout << resetiosflags(ios::right) << setw(12)<<"Deposit"<<setw(12)<<transactions[b] << setiosflags(ios::right)<<test<<endl;
									}
									else{

										negtest = test + transactions[b];
										if (negtest >= 0){
											takeno++;
											take = take - transactions[b];
											test = negtest;
											cout << resetiosflags(ios::right) << setw(12) << "Withdraw" << setw(12) << (-1*transactions[b]) << setiosflags(ios::right) << test << endl;
										}
										else{
											test = test - 5;
											cout << resetiosflags(ios::right) << setw(12) << "IF" << setw(12) << 5 << setiosflags(ios::right) << test << endl;
										}
									}
								}
								cout << setfill('_') << setw(36) << "" << endl;
								cout << "Account Summary" << endl;
								cout << resetiosflags(ios::right) << setfill(' ') << setw(12) << "" << setw(12) << "Number" << setiosflags(ios::right) << setw(12) << "Amount" << endl;
								cout << resetiosflags(ios::right) << setw(24) << "Beginning Balance"<<setiosflags(ios::right) << setw(12) << initial << endl;
								cout << resetiosflags(ios::right) << setw(12) << "Deposits" << setw(12)<<putno<<setiosflags(ios::right) << setw(12) << put << endl;
								cout << resetiosflags(ios::right) << setw(12) << "Withdraws" << setw(12) << takeno << setiosflags(ios::right) << setw(12) << take << endl;
								cout << resetiosflags(ios::right) << setw(24) << "Ending Balance" << setiosflags(ios::right) << setw(12) << checkbook.current[check].amount << endl;
								cout << setfill('_') << setw(36) << "" << endl;
								cout<<setfill(' ')<<"Thank you for working with us! Have a nice day! " << endl;
								break;
							default: cout << "Illegal Transaction code." << endl;
							}
							

						} while (action != 'q');
						break;
					}
					else{
						cout << "Wrong password... ";
						break;
					}
				}
				else{
					cout << STRING <<" was not found within our database. " << endl;
					break;
				}

		default: cout << "Invalid input... ";
			break;

		}


	
		checkbook = checkbook.sort(checkbook, userno);
		fout.open("users.txt");
		for (int a = 0; a < (userno); a++){
			fout << checkbook.current[a].username << endl;
			fout << checkbook.current[a].password << endl;
			fout << checkbook.current[a].amount << endl;
		}
		fout.close();



		cout << "Would you like to continue? (y/n) ";
		cin >> ans;
	}while (ans == 'y');
	
	

	return 0;
}

