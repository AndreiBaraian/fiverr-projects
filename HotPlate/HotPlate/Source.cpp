#include<iostream>
#include<iomanip>
#include<stdbool.h>
using namespace std;

double A[21][21];
double B[21][21];

void copyMatrix()
{
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			B[i][j] = A[i][j];
}


bool checkStability()
{
	bool ok = true;
		for (int i = 1; i < 19; i++)
			for (int j = 1; j < 19; j++)
			{
				if (abs(A[i][j] - B[i][j]) >= 0.1)
					ok = false;
			}
	return ok;
}

int main()
{
	for(int i=0;i<20;i++)
		for (int j = 0; j < 20; j++)
		{
			if ((i == 0 && j != 0 && j != 19) || (i == 19 && j != 0 && j != 19))
				A[i][j] = 100.0;
			else
				A[i][j] = 0.0;
		}
	cout << fixed;
	cout << "Hotplate simulator" << endl;
	cout << "Printing initial plate..." << endl;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
			if(j != 19)
				cout << setw(10) << setprecision(4) << A[i][j] << ", ";
			else
				cout << setw(10) << setprecision(4) << A[i][j] << " ";
		cout << endl;
	}

	copyMatrix();

	for (int i = 1; i < 19; i++)
		for (int j = 1; j < 19; j++)
			A[i][j] = (B[i - 1][j] + B[i + 1][j] + B[i][j - 1] + B[i][j + 1]) / 4;

	cout << "Printing plate after one iteration..." << endl;

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
			if (j != 19)
				cout << setw(10) << setprecision(4) << A[i][j] << ", ";
			else
				cout << setw(10) << setprecision(4) << A[i][j] << " ";
		cout << endl;
	}


	bool stable = false;

	cout << "Printing final plate..." << endl;

	while (!stable)
	{
		copyMatrix();
		for (int i = 1; i < 19; i++)
			for (int j = 1; j < 19; j++)
				A[i][j] = (B[i - 1][j] + B[i + 1][j] + B[i][j - 1] + B[i][j + 1]) / 4;
		stable = checkStability();
	}

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
			if (j != 19)
				cout << setw(10) << setprecision(4) << A[i][j] << ", ";
			else
				cout << setw(10) << setprecision(4) << A[i][j] << " ";
		cout << endl;
	}

	cout << "Printing final plate for excel..." << endl;

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
			if (j != 0)
				cout << "\t"  << setprecision(4) << A[i][j];
			else 
				cout << setprecision(4) << A[i][j];
		cout << endl;
	}

	return 0;
}