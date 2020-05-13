#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>  
#include <iomanip>
#include <algorithm> 

using namespace std;

ifstream fin;
ofstream fout;

class dict{
private:
	string fdict[5000];
	int dictno;
public:
	dict(string p);
	string randword();
	int binsearch(string x);
};

dict::dict(string p){
	string x;
	dictno = 0;
	fin.open(p);
	while (!fin.eof()){
		fin >> x;
		fdict[dictno] = x;
		dictno++;

	}
	fin.close();

}

string dict::randword(){
	string sword;
	int iSecret;
	srand(time(NULL));
	iSecret = rand() % dictno;
	sword = fdict[iSecret];
	return sword;

}

int dict::binsearch(string x){
	int k;
	k = 0;

	for (int i = 0; i < dictno; i++){
		if (fdict[i] == x){
			k = 1;
			break;
		}


	}
	if (k == 1){
		return 1;
	}
	else{
		return -1;
	}
}

class jword
{
private:
	string word;


public:
	jword(string x);
	int getjotts(string x);
	string giveup();

};

jword::jword(string x){
	word = x;
}

string jword::giveup(){
	return word;

}

int jword::getjotts(string x){
	string unique;
	int uno;
	int checky;
	int jotts;
	checky = 0;
	jotts = 0;
	unique = "22222";
	uno = 0;

	for (int b = 0; b < 5; b++){
		checky = 0;
		for (int j = 0; j < 5; j++){
			if (x[b] != unique[j]){
				checky++;
			}

		}
		if (checky == 5){
			unique[uno] = x[b];
			uno++;
		}

	}

	for (int e = 0; e < uno; e++){
		for (int r = 0; r < 5; r++){
			if (word[r] == unique[e]){
				jotts++;
			}

		}

	}
	if (x == word){
		jotts = 999;
	}
	return jotts;

}

class aidict
{
private:
	string udict[5000];
	int aidictno;

public:
	aidict();


};

aidict::aidict(){
	string x;
	aidictno = 0;
	fin.open("jotto.txt");
	while (!fin.eof()){
		fin >> x;
		udict[aidictno] = x;
		aidictno++;

	}
	fin.close();
}
