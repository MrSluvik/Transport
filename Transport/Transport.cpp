//Створити абстрактний базовий клас «Транспортний засіб» і похідні класи «Автомобіль», «Велосипед», «Віз». Підрахувати час і вартість перевезення пасажирів і вантажів кожним транспортним засобом.
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Transport//базовий клас
{
protected:
	virtual double time() = 0;//чистот віртуальні ф-н
    virtual double costp() = 0;
	virtual double costv() = 0; 
};
//потрібна вартість за км пасажира і ватажу  , швидкість, відстань
class Car:public Transport
{
private:
	double l;//відстань перевезення в км
	double v;//швидкість транспорту 
	double Costp;//вартість перевезення пасижира
	double Costv;//вартість перевезення вантажів
	int people;
public:
	Car(double l , double v , double costp , double costv, int people)//конструтор з параметрами
	{
		this->l = l;
		this->v = v;
		this->Costp = costp;
		this->Costv = costv;
		this->people = people;
	}

	 double costp()override   //вартість перевезення пасажира
	 {
		 return (l * Costp)*people;//відстань множим на ціну і на кількість пасажирів
	 }

	 double costv()override  //вартість перевезення вантажу
	 {
		 return l * Costv;//відстань множим на ціну
	 }

	 double time() override //час перевезення
	 {
		 return l / v;//відстань діли на швидкість отримуєм час
	 }
	~Car(){}//деструктор
};

class Bike :public Transport
{
protected:
	double l;//відстань перевезення в км
	double v;//швидкість транспорту 
	double Costp;//вартість перевезення пасижира
	double Costv;//вартість перевезення вантажів
public:
	Bike(double l, double v, double costp, double costv)//конструтор з параметрами
	{
		this->l = l;
		this->v = v;
		this->Costp = costp;
		this->Costv = costv;
	}

	double costp()override   //вартість перевезення пасажира
	{
		return l * Costp;//відстань множим на ціну перевезення пасажира (на велик поміститься лише 1 пасижир якщо хочете їхати з відносним комфортом),тому ьак
	}

	double costv()override  //вартість перевезення вантажу
	{
		return l * Costv;//відстань множим на ціну
	}

	double time() override //час перевезення
	{
		return l / v;//відстань діли на швидкість отримуєм час
	}

	~Bike(){}//деструктор

};

class Cart : public Transport
{
protected:
	double l;//відстань перевезення в км
	double v;//швидкість транспорту 
	double Costp;//вартість перевезення пасижира
	double Costv;//вартість перевезення вантажів
	int people;
public:
	Cart (double l, double v, double costp, double costv , int people)//конструтор з параметрами
	{
		this->l = l;
		this->v = v;
		this->Costp = costp;
		this->Costv = costv;
		this->people = people;
	}

	double costp()override   //вартість перевезення пасажира
	{
		return (l * Costp)*people;//відстань множим на ціну і на кількість пасажирів
	}

	double costv()override  //вартість перевезення вантажу
	{
		return l * Costv;//відстань множим на ціну
	}

	double time() override //час перевезення
	{
		return l / v;//відстань діли на швидкість отримуєм час
	}

	~Cart (){}//деструктор
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Car A(20.5 , 66 , 21.7, 30.0 , 3);//вводимо відстань в км  /   швидкість в км/год   /    вартість перевезення пасажира  / вартість перевезення вантажу  / кількість пасажирів

	Bike B(15 , 15.5 , 15.6 ,20.4);//вводимо відстань в км /   швидкість в км/год   /    вартість перевезення пасажира  / вартість перевезення вантажу  /

	Cart C(40 ,8.10 , 11, 14 , 6);//вводимо відстань  в км/   швидкість в км/год   /    вартість перевезення пасажира  / вартість перевезення вантажу  / кількість пасажирів

	cout << "Час перевезення на автомобілі : " << A.time() << " " <<  endl;
	cout << "Час перевезення на велосипеді : " << B.time() << " " <<  endl;
	cout << "Час перевезення на возі :  " << C.time() << " " << endl << endl;

	cout << "Вартість перевезення пасажира на автомобілі : " << A.costp() << " грн" << endl;
	cout << "Вартість перевезення пасажира на велосипеді : " << B.costp() << " грн" << endl;
	cout << "Вартість перевезення пасажира на возі : " << C.costp() << " грн" << endl << endl;

	cout << "Вартість перевезення пасажира на автомобілі : " << A.costv() << " грн" << endl;
	cout << "Вартість перевезення пасажира на велосипеді : " << B.costv() << " грн" << endl;
	cout << "Вартість перевезення пасажира на возі : " << C.costv() << " грн " << endl << endl;
}


