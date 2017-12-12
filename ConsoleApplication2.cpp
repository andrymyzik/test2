#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <windows.h>
#include <string.h>
using namespace std;
FILE*f;
int n;
double a, *mas;
void vyvid()
{
	system("cls");
	fopen_s(&f, "File.dat", "rb+");
	fread(&n, sizeof(int), 1, f);
	mas = new double[n];
	fread(mas, sizeof(double), n, f);
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
	fclose(f);
}


void main()
{
	int ch;

	for (;;)
	{
		cout << "Menu: (viberit nomer dlya vikonanna diyi)" << endl;
		cout << "1)\tStvorennia failu ta napovnennia yoho informatsiieiu" << endl;
		cout << "2)\tVstavka elementu na zadanu pozytsiiu" << endl;
		cout << "3)\tVydalennia elementu iz zadanoi pozytsii" << endl;
		cout << "4)\tVydalennia elementa iz zadanym znachenniam" << endl;
		cout << "5)\tSortuvannia masyvu danykh u samomu faili" << endl;
		cout << "6)\tPidrakhunok serednoho aryfmetychnoho elementiv masyvu" << endl;
		cout << "7)\tVyvid masyvu danykh na ekran" << endl;
		cin >> ch;

		switch (ch) {

		case 1:


			system("cls");
			fopen_s(&f, "File.dat", "wb+");
			cout << "Vvedit kilkist elementiv ta elementy:\n";
			cin >> n;
			fwrite(&n, sizeof(int), 1, f);
			for (int i = 0; i < n; i++)
			{
				cin >> a;
				fwrite(&a, sizeof(double), 1, f);
			}





			fclose(f);
			vyvid();


			cout << std::endl << "Done!" << std::endl << std::endl;
			break;

		case 2:


			system("cls");
			int k1;
			double d;
			cout << "Vstavka elementu na zadanu pozytsiiu" << endl << "Vvedit cher pozytsii:\t";
			cin >> k1;
			cout << "Vvedit element:\t";
			cin >> d;
			fopen_s(&f, "File.dat", "rb+");
			for (int i = n; i > k1; i--)
			{
				fseek(f, sizeof(int) + i * sizeof(double), SEEK_SET);
				fread(&a, sizeof(double), 1, f);
				fseek(f, sizeof(int) + (i + 1) * sizeof(double), SEEK_SET);
				fwrite(&a, sizeof(double), 1, f);
			}
			fseek(f, sizeof(int) + k1 * sizeof(double), SEEK_SET);
			fwrite(&d, sizeof(double), 1, f);
			fseek(f, 0, SEEK_SET);
			if (k1 <= n)
			{
				n++;
				fwrite(&n, sizeof(int), 1, f);
				fclose(f);
				vyvid();
			}
			else
			{
				cout << "Vvedena pozytsiia vykhodyt za mezhi masyvu\n";
			}

			cout << std::endl << "Done!" << std::endl << std::endl;
			break;

		case 3:


			system("cls");
			int k;
			cout << "Vydalennia elementu z zadanoi pozytsii" << endl << "Vvedit cher pozytsii:\t";
			cin >> k;
			fopen_s(&f, "File.dat", "rb+");
			for (int i = (k - 1); i < n; i++)
			{
				fseek(f, sizeof(int) + (i + 1) * sizeof(double), SEEK_SET);
				fread(&a, sizeof(double), 1, f);
				fseek(f, sizeof(int) + i * sizeof(double), SEEK_SET);
				fwrite(&a, sizeof(double), 1, f);
			}
			if (k < n)
			{
				n--;
				fseek(f, 0, SEEK_SET);
				fwrite(&n, sizeof(int), 1, f);
				fclose(f);
				vyvid();
			}
			else
			{
				cout << "Vvedena pozytsiia vykhodyt za mezhi masyvu" << endl;
			}


			cout << std::endl << "Done!" << std::endl << std::endl;
			break;

		case 4:


			system("cls");
			double p1;

			cout << "4)\tVydalennia elementa iz zadanym znachenniam" << endl << "Vvedit znachennia elementy\t";
			cin >> p1;
			fopen_s(&f, "File.dat", "rb+");
			for (int i = 0; i < n; i++)
			{
				fseek(f, sizeof(int) + i * sizeof(double), SEEK_SET);
				fread(&a, sizeof(double), 1, f);
				if (a == p1)
				{
					k1 = i;
					break;
				}
			}
			for (int i = k1; i <= n; i++)
			{
				fseek(f, sizeof(int) + (i + 1) * sizeof(double), SEEK_SET);
				fread(&a, sizeof(double), 1, f);
				fseek(f, sizeof(int) + i * sizeof(double), SEEK_SET);
				fwrite(&a, sizeof(double), 1, f);
			}
			fseek(f, 0, SEEK_SET);
			n--;

			fseek(f, 0, SEEK_SET);
			fwrite(&n, sizeof(int), 1, f);
			fclose(f);
			vyvid();


			cout << std::endl << "Done!" << std::endl << std::endl;
			break;

		case 5:


			system("cls");
			double min, max;
			fopen_s(&f, "File.dat", "rb+");
			for (int j = n; j > 0; j--)
			{
				for (int i = 0; i < j; i++)
				{
					fseek(f, sizeof(int) + i * sizeof(double), SEEK_SET);
					fread(&min, sizeof(double), 1, f);
					fseek(f, sizeof(int) + (i + 1) * sizeof(double), SEEK_SET);
					fread(&max, sizeof(double), 1, f);
					if (min > max)
					{
						double m = min;
						min = max;
						max = m;
					}
					fseek(f, sizeof(int) + i * sizeof(double), SEEK_SET);
					fwrite(&min, sizeof(double), 1, f);
					fseek(f, sizeof(int) + (i + 1) * sizeof(double), SEEK_SET);
					fwrite(&max, sizeof(double), 1, f);
				}
			}
			fclose(f);
			vyvid();


			cout << std::endl << "Done!" << std::endl << std::endl;
			break;

		case 6:




			system("cls");
			double s1;

			fopen_s(&f, "File.dat", "rb+");
			s1 = 0;
			for (int i = 0; i < n; i++)
			{
				fseek(f, sizeof(int), SEEK_SET);
				fread(&a, sizeof(double), 1, f);
				
			}
			s1 = s1 / n;
			cout << "Serednie aryfmetychne elementiv masyvu rivne:\t" << s1 << endl;
			fclose(f);



			cout << std::endl << "Done!" << std::endl << std::endl;
			break;

		case 7:

			vyvid();


			cout << std::endl << "Done!" << std::endl << std::endl;
			break;




		default:
			cout << "Enter number from [1] ot [7]" << std::endl;
			break;


		}
	}
}

