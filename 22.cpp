#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;


int main()
{
	double mas[1000]; //масив для збереження даних
	string s; //строка шляху до фалу
	ifstream f; //файл, з якого будемо отримувати дані
	ofstream r("Result.txt"); //файл, в який будемо записувати результат

q:
	cout << "Enter the path to the file containing the data (numbers) to calculate the arithmetic mean" << endl;
	getline(cin, s); //отримуємо адрес до файлу


	f.open(s); //відкриваємо файл

	if (!f.is_open()) { //перевіряємо чи існує файл за такою адресою
		cout << "This file does not exist" << endl << endl << endl;// якщо не існує, то виводимо
		goto q;//та повертаємося на початок
	}
	else { //якщо існує
		double ser;
		double sum;
		int n;
		n = 0;
		sum = 0; //задаємо змінні

		while (!f.eof()) {

			f >> mas[n]; //зчитуємо масив даних


			if (!f) { //перевірка чи отримано значення


				cout << "Error (syntax is incorrect)" << endl << endl; //вивід повідомлення про помилку
				f.close(); // закриття файлу
				goto q; // повернення на початок

			}
			else {
				sum = sum + mas[n]; // рахуємо суму

				n++; // рахуємо кількість елементів
			}

		}

		ser = sum / n; // рахуємо середнє арифметичне

		system("cls"); // очищеємо вікно консолі




		cout << "Arithmetic mean: " << ser << endl << endl; // виводимо середнє арифметичне значення на екран

		r << ser; //записуємо середнє арифметичне значення у файл

	}
	f.close();
	r.close(); // закриваємо файли

	system("pause");
	return 0;
}