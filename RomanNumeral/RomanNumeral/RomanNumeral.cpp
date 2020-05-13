// RomanNumeral.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <io.h>
#include <windows.h>
#include <fcntl.h>
#include <cstdio>
#pragma execution_character_set( "utf-8" )
using namespace std;


void toClipboard(const std::string &s){
	OpenClipboard(0);
	EmptyClipboard();
	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, s.size());
	if (!hg){
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg), s.c_str(), s.size());
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT, hg);
	CloseClipboard();
	GlobalFree(hg);
}


int main()
{
	//setlocale(LC_ALL, "en_US.utf8");
	//char* locale = setlocale(LC_ALL, "English"); // Get the CRT's current locale.
	//std::locale lollocale(locale);
	//setlocale(LC_ALL, locale); // Restore the CRT.
	//std::wcout.imbue(lollocale); // Now set the std::wcout to have the locale that we got from the CRT.
	//std::wcout << "Ŧ";




	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = 20;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Lucida Console"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	system("COLOR F1");
	int arab;
	char roman[30];
	int proj;
	int count;
	int bignum;
	string current;
	int no;
	long avalues[7];
	char rvalues[7];
	int use;
	int testnum;
	string romanxd;
	string underscore;
	string rvalue[30];
	long avalue[30];
	int len;


	avalues[0] = 1;
	rvalues[0] = 'I';
	avalues[1] = 5;
	rvalues[1] = 'V';
	avalues[2] = 10;
	rvalues[2] = 'X';
	avalues[3] = 50;
	rvalues[3] = 'L';
	avalues[4] = 100;
	rvalues[4] = 'C';
	avalues[5] = 500;
	rvalues[5] = 'D';
	avalues[6] = 1000;
	rvalues[6] = 'M';

	rvalue[13] = "iv";
	rvalue[14] = "v";
	rvalue[15] = "ix";
	rvalue[16] = "x";
	rvalue[17] = "xl";
	rvalue[18] = "l";
	rvalue[19] = "xc";
	rvalue[20] = "c";
	rvalue[21] = "cd";
	rvalue[22] = "d";
	rvalue[23] = "cm";
	rvalue[24] = "m";

	avalue[13] = 4000;
	avalue[14] = 5000;
	avalue[15] = 9000;
	avalue[16] = 10000;
	avalue[17] = 40000;
	avalue[18] = 50000;
	avalue[19] = 90000;
	avalue[20] = 100000;
	avalue[21] = 400000;
	avalue[22] = 500000;
	avalue[23] = 900000;
	avalue[24] = 1000000;



	rvalue[0] = "I";
	rvalue[1] = "IV";
	rvalue[2] = "V";
	rvalue[3] = "IX";
	rvalue[4] ="X";
	rvalue[5] = "XL";
	rvalue[6] = "L";
	rvalue[7] = "XC";
	rvalue[8] = "C";
	rvalue[9] = "CD";
	rvalue[10] = "D";
	rvalue[11] = "CM";
	rvalue[12] = "M";

	avalue[0] = 1;
	avalue[1] = 4;
	avalue[2] = 5;
	avalue[3] = 9;
	avalue[4] = 10;
	avalue[5] = 40;
	avalue[6] = 50;
	avalue[7] = 90;
	avalue[8] = 100;
	avalue[9] = 400;
	avalue[10] = 500;
	avalue[11] = 900;
	avalue[12] = 1000;

	proj = 1;

	while (proj == 1 | proj == 2){
	
		cout <<"How to convert? (Roman->Arabic 1, Arabic->Roman 2, exit->0) ";
		cin >> proj;

		switch (proj){

		case 1: cout << "Enter Roman numeral: ";

			cin >> roman;

			for (int i = 0; i < 30; i++){
				if (roman[i] == '\0'){
					count = i;

					break;
				}
			}

			bignum = 1;
			use = 0;
			arab = 0;

			for (int i = (count); i >= 0; i--){
				for (int a = 0; a <= 6; a++){
					if (roman[i] == rvalues[a]){
						use = a;

					}
				}
				if (avalues[use] >= bignum){
					bignum = avalues[use];
					arab = arab + avalues[use];

				}
				else{
					arab -= avalues[use];
				}


			}
			arab = arab - 1;
			cout << arab<<endl;
			break;


		case 2: cout << "Enter arabic numeral: ";
			cin >> arab;
			no = 0;
			romanxd = "";
			underscore = "";
			len = 0;
			for (int i = 24; i >-1; i--){
				testnum = floor(int(arab / avalue[i]));
				//cout << testnum<<endl;
				arab = arab % avalue[i];
				current = rvalue[i];
				for (int i = 0; i < testnum; i++){
					len++;
					romanxd = romanxd + current;
				}
			}

			for (int i = 0; i <= len; i++){
				if (romanxd[i] == 'm' | romanxd[i] == 'c' | romanxd[i] == 'd' | romanxd[i] == 'x' | romanxd[i] == 'l' | romanxd[i] == 'v' | romanxd[i] == 'i'){
					underscore = underscore + "_";
					
				}
				else{
					underscore = underscore + " ";
				}

			}
			toClipboard(romanxd);
			for (int i = 0; i <= len; i++){
				romanxd[i] = toupper(romanxd[i]);
			}
			/*if (arab = 4000){
				underscore = "__";
			}*/
			cout << underscore << endl;
			cout << romanxd<<endl;
			
			
			cout << endl;
		}



	}
	return 0;
}

