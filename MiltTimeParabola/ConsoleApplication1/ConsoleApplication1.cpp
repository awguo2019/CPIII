// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	int proj;
	int t1;
	int t2;
	int hr1;
	int hr2;
	int min1;
	int min2;
	int hrt;
	int mint;
	double a;
	double b;
	double c;
	double r1;
	double r2;
	double x1;
	double x2;
	double y1;
	double y2;
	double m;
	double yint;
	double xcr1;
	double ycr1;
	double xcr2;
	double ycr2;

	while (1) {
		cout << "Which lab do you want to run? (0-exit, 1-Military, 2-Parabola) ";
		cin >> proj;
		switch (proj) {

		case 1: cout << "Enter earlier time (as a single number): ";
			cin >> t1;
			cout << "Enter later time: (as a single number): ";
			cin >> t2;
			hr1 = floor(t1 / 100);
			min1 = t1 % 100;
			hr2 = floor(t2 / 100);
			min2 = t2 % 100;
			if (min1 > 60) {
				min1 = min1 - 60;
				hr1 = hr1 + 1;
			}
			if (min2 > 60) {
				min2 = min2 - 60;
				hr2 = hr2 + 1;
			}
			mint = min2 - min1;
			hrt = hr2 - hr1;
			if (mint < 0) {
				mint = mint + 60;
				hrt = hrt - 1;
			}
			if (hrt < 0) {
				hrt = hrt + 24;
			}
			cout << "The difference in time is " << hrt << " hours and " << mint << " minutes." << endl;
			break;

		case 2: cout << "Enter a, b, and c: ";
			cin >> a >> b >> c;
			cout << "Your function is " << a << "x^2 + " << b << "x + " << c << endl;
			if ((pow(b, 2) - (4 * a*c)) >=0) {
				r1 = (-b - pow((pow(b, 2) - 4 * a*c), .5)) / (2 * a);
				r2 = (-b + pow((pow(b, 2) - 4 * a*c), .5)) / (2 * a);
				cout << "The two roots to this quadratic equation are " << r1 << " and " << r2 << endl;
			}
			else {
				r1 = (-b - pow((-(pow(b, 2) - 4 * a*c)), .5)) / (2 * a);
				r2 = (-b + pow((-(pow(b, 2) - 4 * a*c)), .5)) / (2 * a);
				cout << "The two roots to this quadratic equation are " << r1 <<"i and " << r2<<"i" << endl;

			}
			cout << "The derivative for this function is " << 2.0 * a << "x + " << b << endl;

			cout << "Enter x1 and x2 for the line: ";
			cin >> x1 >> x2;
			cout << "Enter y1 and y2 for the line: ";
			cin >> y1 >> y2;

			

			if (x1 != x2) {
				m = (y1 - y2) / (x1 - x2);
				yint = y1 - m*x1;
				cout << "The slope is " << m << endl;
				cout << "Y-intercept at " << yint << endl;
			}
			else {
				cout << "The slope is invalid." << endl;
				cout << "Y-intercept at " << y1 << endl;
			}
			
			xcr1 = (-(b-m) - pow((pow((b - m), 2) - 4 * a*(c-yint)), .5)) / (2 * a);
			xcr2 = (-(b - m) + pow((pow((b - m), 2) - 4 * a*(c - yint)), .5)) / (2 * a);
			ycr1 = xcr1*m + yint;
			ycr2 = xcr2*m + yint;
			cout << "The points of intersection are (" << xcr1 << "," << ycr1 << ") and (" << xcr2 << "," << ycr2 << "). " << endl;
			break;
		}


	}
    return 0;
}

