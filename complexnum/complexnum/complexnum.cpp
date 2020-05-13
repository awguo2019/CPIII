// complexnum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>


using namespace std;

string qs;
string rs;
float q;
float w;
int check;

void getdata(){
	string userget;
	int usernum;
	check = 0;
	qs = "";
	rs = "";
	q = 0;
	w = 0;

	cout << "Enter complex number (a+bi): ";
	cin >> userget;
	usernum = userget.length();
	if (userget[0] == '-'){
		qs = qs + userget[0];
		check = check + 1;
		for (int i = 1; i < usernum; i++){
			if (userget[i] != '+' && userget[i] != '-'){
				qs = qs + userget[i];
				check++;
			}
			else{
				if (userget[i] == '-'){
					rs = rs + '-';
					check++;
				}
				break;
			}

		}

		for (int i = check; i < (usernum - 1); i++){
			rs = rs + userget[i];
			check++;
		}
	}

	else{
		for (int i = 0; i < (usernum - 1); i++){
			if (userget[i] != '+' && userget[i] != '-'){
				qs = qs + userget[i];
				check++;
			}
			else{
				if (userget[i] == '-'){
					rs = rs + '-';
					check++;
				}
				

				break;
			}

		}

		for (int i = (check); i < (usernum - 1); i++){
			rs = rs + userget[i];

		}

	}
	q = stof(qs.c_str());
	w = stof(rs.c_str());

}
class complexnum{
public:
	complexnum::complexnum(float x, float y);
	complexnum::complexnum();
	void copy(float x, float y);
	void add(complexnum n1, complexnum n2);
	void subt(complexnum n1, complexnum n2);
	void div(complexnum n1, complexnum n2);
	void mult(complexnum n1, complexnum n2);
	void exp(complexnum n1, float e);
	void neg();
	float abs();
	string ts();


private:
	float a;
	float b;
	string s;
};

void complexnum::copy(float x, float y){
	a = x;
	b = y;
}
complexnum::complexnum(float x, float y){
	a = x;
	b = y;

}
void complexnum::neg(){
	a = -a;
	b = -b;

}
complexnum::complexnum(){
	a = 0;
	b = 0;

}


void complexnum::add(complexnum n1, complexnum n2){
	a = n1.a + n2.a;
	b = n1.b + n2.b;
	
}

void complexnum::subt(complexnum n1, complexnum n2){
	a = n1.a - n2.a;
	b = n1.b - n2.b;

}

void complexnum::mult(complexnum n1, complexnum n2){
	a = n1.a*n2.a - n1.b*n2.b;
	b = n1.b*n2.a + n1.a*n2.b;

}

void complexnum::div(complexnum n1, complexnum n2){
	float d;
	d = (n2.a*n2.a + n2.b*n2.b);
	complexnum conj(n2.a, (-n2.b));

	complexnum::mult(n1, conj);
	a = a / d;
	b = b / d;

}

void complexnum::exp(complexnum n1, float e){
	float av;
	float theta;

	av = n1.abs();
	theta = n1.a / av;
	theta = acos(theta);
	a = pow(av, e)*cos(e*theta);
	b = pow(av, e)*sin(e*theta);

}

float complexnum::abs(){
	float x;
	x = pow((a* a + b*b), .5);
	return x;
}



string complexnum::ts(){
	string ss;
	string as;
	string bs;
	
	as = to_string(a);
	bs = to_string(b);
	if (a != 0){
		if (b < 0){
			ss = as + (bs)+"i";
		}
		if (b > 0){
			ss = as + "+" + bs + "i";
		}
		if (b == 0){
			ss = as;
		}
	}
	else{
		if (b != 0){
			ss = bs + "i";
		}
		else{
			ss = "0";
		}
	}
	return ss;
}



int main()
{
	char ans;
	int choose;
	
	
	float p;
	float exp;
	complexnum x;
	complexnum y;
	complexnum z;
	cout << fixed;
	cout << setprecision(2);

	check = 0;
	do{
		getdata();
		x.copy(q, w);
		cout << "1 = add, 2 = subtract, 3 = multiply, 4 = divide, 5 = absolute value, 6 = exponent" << endl;
		cout << "What do you want to do? ";
		cin >> choose;

		
		switch (choose){
		case 1: 
			getdata();
			y.copy(q, w);
			
			z.add(x, y);
			cout << z.ts();
			cout << endl;
			break;

		case 2:
			getdata();
			y.copy(q, w);
			z.subt(x, y);
			cout << z.ts();
			cout << endl;
			break;

		case 3:
			getdata();
			y.copy(q, w);

			z.mult(x, y);
			cout << z.ts();
			cout << endl;
			break;

		case 4:
			getdata();
			y.copy(q, w);

			z.div(x, y);
			cout << z.ts();
			cout << endl;
			break;

		case 5:
			p = x.abs();
			cout << p << endl;
			break;

		case 6:
			cout << "What power do you wish to raise the number to? ";
			cin >> exp;
			z.exp(x, exp);
			cout << z.ts() << endl;
			if (exp == .5){
				z.neg();
				cout << z.ts() << endl;

			}

			break;


		}
		
		
		
		
		
		cout << "Continue? (Y/N) ";
		cin >> ans;
	} while (ans == 'Y' || ans == 'y');

	return 0;
}

