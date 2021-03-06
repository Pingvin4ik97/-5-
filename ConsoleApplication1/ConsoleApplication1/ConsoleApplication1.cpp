#include "stdafx.h"//Poluchilos' je?
#include <iostream>
#include <conio.h>
#include <locale.h> //setlocale(LC_ALL, "russian");
#include "Header.h"
#include <complex>
#include "ClassComplex.h"
using namespace std;

template <class Dtype>
void Calc(MyVektor<Dtype> obja, MyVektor<Dtype> objb, MyVektor<Dtype> objx)
{
	int sizea, sizeb;
	int tt;
	cout << "\nМасивы созданы" << endl;
	cout << obja << objb;
		try {
			if (obja > objb)
			{
				cout << "\n a > b";
				cout << "\nx = (a*a-b)/a";
				objx = obja * obja;
				#ifdef _DEBUG
				cout << "\na * a = " << objx;
				#endif // _DEBUG
				objx = objx - objb;
				#ifdef _DEBUG
				cout << "\na * a - b = " << objx;
				#endif // _DEBUG
				objx = objx / obja;
			}
			else
				if (obja < objb)
				{
					cout << "\n a < b";
					cout << "\nx = (a*b-1)/b";
					objx = obja * objb;
					#ifdef _DEBUG
					cout << "\na * b = " << objx;
					#endif // _DEBUG
					objx = objx - 1;
					#ifdef _DEBUG
					cout << "\na * b - 1 = " << objx;
					#endif // _DEBUG
					objx = objx / objb;
				}
				else
					if (obja == objb)
					{
						cout << "\n a = b";
						cout << "\nx = -a";
						objx = obja * (-1);
					}
			cout << objx;
			cout << CONTINUE;
		}
		catch (char*e)
		{
			cout << "\nОшибка! " << e;
			cout << CONTINUE;
		}
		catch (...)
		{
			cout << "\nУууупс... Что-то пошло не так";
			cout << CONTINUE;
		}
}

int Size(char* name)
{
	int size = 0;
	do
	{
		cout << "Введите размер массива ";
		cout << name;
		cout << ": ";
		cin >> size;
		if ((size < 1) || (size > 1000))
			cout << "\nНеверный размер массива!";
	} while ((size < 1) || (size > 1000));
	return size;
}

void main()
{
	setlocale(LC_ALL, "russian");
	bool chek = true;
	int type = 0;
	do 
	{
		try
		{
			cout << "\nЛабораторная робота №5. Вариант №20";
			cout << "\n\n    Г(a*a-b)/a, если a>b;";
			cout << "\nX = |-a,        если а = b;";
			cout << "\n    L(a*b-1)/b, если a<b;\n";
			cout << "\nВыберите тип данных хранимых в векторе (1 - int, 2 - double, 3 - NoComplex (int), 4 - NoComplex (double), 5 - complex(int))\n";
			do
			{
				cin >> type;
				switch (type)
				{
				case 1: {MyVektor<int> objx; MyVektor<int> obja(Size("a")); MyVektor<int> objb(Size("b")); Calc(obja, objb, objx); chek = false;  break; }
				case 2: {MyVektor<double> objx; MyVektor<double> obja(Size("a")); MyVektor<double> objb(Size("b")); Calc(obja, objb, objx); chek = false;  break; }
				case 3: {MyVektor<NoComplex<int>> objx; MyVektor<NoComplex<int>> obja(Size("a")); MyVektor<NoComplex<int>> objb(Size("b")); Calc(obja, objb, objx); chek = false;  break; }
				case 4: {MyVektor<NoComplex<double>> objx; MyVektor<NoComplex<double>> obja(Size("a")); MyVektor<NoComplex<double>> objb(Size("b")); Calc(obja, objb, objx); chek = false;  break; }
				case 5: {MyVektor<complex<int>> objx; MyVektor<complex<int>> obja(Size("a")); MyVektor<complex<int>> objb(Size("b")); Calc(obja, objb, objx); chek = false;  break; }
				default: {cout << "Ошибка ввода, повторите попытку!"; break; }
				}
			} while (chek);
		}
		catch (char*e)
		{
			cout << "\nОшибка! " << e;
			cout << CONTINUE;
		}
		catch (...)
		{
			cout << "\nУууупс... Что-то пошло не так";
			cout << CONTINUE;
		}
	} while (_getch() != 27);
} 