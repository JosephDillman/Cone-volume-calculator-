//Lab report program code for CMPT128 D200, created by Joseph Dillman and Tal Kazakov on oct 26, 2016.

//This program is designed to calculate the volume of several cones given a diameter value, the outputs 
//will be placed into an organized table. The volumes will be based on cones of height 1, 7, 9, and 15cm,
//the diameter will increase by an user inputed interval value and the volume
//calculations will be printed for a specified number of rows given from the user
//Users will not be able to input invalid values more than 3 times

//last edited: october 26, 2016

#include <iostream>
#include <iomanip>
#include <cmath>
#pragma warning(disable: 4996)
using namespace std;

int main()
{

	//declare and initialize variables 
	double diameter = 0.0;
	double interval = 0.0;
	double volume1cm = 0.0;
	double volume7cm = 0.0;
	double volume9cm = 0.0;
	double volume15cm = 0.0;
	int rows = 0;
	int count = 0;

	//declare and initialize constants, which will be used to limit variables
	const double MAXDIAMETER = 60.000;
	const double MINDIAMETER = 0.000;
	const double MAXINTERVAL = 5.000;
	const double MININTERVAL = 0.100;
	const double TWELVE = 12.0;
	const double height1 = 1.0;
	const double height7 = 7.0;
	const double height9 = 9.0;
	const double height15 = 15.0;
	const int MAXROWS = 23;
	const int MINROWS = 1;
	const double PI = 3.1415926589;

	//prompt user to input value for diameter
	//if an invalid value is entered, the user will be given 2 more tried before the program is terminated
	cout << "enter the diameter of the base of the cone for the first row" << endl;
	cout << "0.000 <= x <= 60.000 ";
	cin >> diameter;
	while (diameter < MINDIAMETER || diameter > MAXDIAMETER)
	{
		if (count > 1)
		{
			cout << "Exceeded number of tries reading the initial diameter of the cone" << endl;
			cout << "Program is terminating";
			return(1);
		}
		cout << fixed << showpoint << setprecision(3);
		cout << " You entered " << diameter << endl;
		cout << "TRY AGAIN PLEASE" << endl;
		cout << "enter the diameter of the base of the cone for the first row" << endl;
		cout << "0.000 <= x <= 60.000 ";
		cin >> diameter;
		count++;
	}

	//prompt user to input value for number of rows, 3 tried given 
	cout << "enter the number of rows in the table 1 <= x <= 23 ";
	cin >> rows;
	count = 0;
	while (rows < MINROWS || rows > MAXROWS)
	{
		if (count > 1)
		{
			cout << "Exceeded number of tries reading the number of rows" << endl;
			cout << "Program is terminating";
			return(2);
		}
		cout << " You entered " << rows << endl;
		cout << "TRY AGAIN PLEASE" << endl;
		cout << "enter the number of rows in the table 1 <= x <= 23 ";
		cin >> rows;
		count++;
	}

	//prompt user to input value for length of interval, 3 tried given 
	cout << "enter the length of the interval between entries in the table" << endl;
	cout << "0.100 <= diamInterval <= 5.000 ";
	cin >> interval;
	count = 0;
	while (interval < MININTERVAL || interval > MAXINTERVAL)
	{
		if (count > 1)
		{
			cout << "Exceeded number of tries reading the interval" << endl;
			cout << "Program is terminating";
			return(3);
		}
		cout << fixed << showpoint << setprecision(3);
		cout << " You entered " << interval << endl;
		cout << "TRY AGAIN PLEASE" << endl;
		cout << "enter the length of the interval between entries in the table" << endl;
		cout << "0.100 <= diamInterval <= 5.000 ";
		cin >> interval;
		count++;
	}

	//headings for the table are printed 
	cout << endl << endl;
	cout << setw(15) << "Diameter";
	cout << setw(15) << "Volume for";
	cout << setw(15) << "Volume for";
	cout << setw(15) << "Volume for";
	cout << setw(15) << "Volume for";
	cout << endl;
	cout << setw(30) << "height 1cm";
	cout << setw(15) << "height 7cm";
	cout << setw(15) << "height 9cm";
	cout << setw(15) << "height 15cm";
	cout << endl;

	//calculations for all values are completed and printed inside a loop 
	//the loop will repeat until all rows are completed
	//the loop will not print calculations of diameter greater than 120.0
	count = 0;
	while (count < rows)
	{
		volume1cm = PI*diameter*diameter*height1 / TWELVE;
		volume7cm = PI*diameter*diameter*height7 / TWELVE;
		volume9cm = PI*diameter*diameter*height9 / TWELVE;
		volume15cm = PI*diameter*diameter*height15 / TWELVE;

		//print an error message if the diameter is greater than 120.0cm
		if (diameter >= 120.0)
		{
			cout << "diameter of cone exceeded the maximum value allowed, line not printed" << endl;
			count++;
		}

		else
		{
			//set precision, print the values 
			cout << fixed << showpoint << setprecision(3);
			cout << setw(15) << diameter;
			cout << setw(15) << volume1cm;
			cout << setw(15) << volume7cm;
			cout << setw(15) << volume9cm;
			cout << setw(15) << volume15cm;
			cout << endl;
			count++;
			diameter = diameter + interval;
		}
	}
	return(0);
}








