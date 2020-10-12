#include "Atm.h"
int Atm::recalculate_ballance()
{
	float b_aux=0;

	for (auto i : this->num_of_Bills)
	{
		int multiplyer = 0;
		switch (i.first)
		{
		case Bill::bill::Lei_5:
			multiplyer = 5;
			break;
		case Bill::bill::Lei_10:
			multiplyer = 10;
			break;
		case Bill::bill::Lei_50:
			multiplyer = 50;
			break;
		case Bill::bill::Lei_100:
			multiplyer = 100;
			break;
		case Bill::bill::Lei_200:
			multiplyer = 200;
			break;
		case Bill::bill::Lei_500:
			multiplyer = 500;
			break;
		default:
			break;
		}
		b_aux += i.second * (float)multiplyer;
	}
	balance = b_aux;
	return b_aux;
}

Atm* Atm::add_Bill(Bill::bill b,int quantity)
{
	this->num_of_Bills[b] = quantity;
	recalculate_ballance();
	return this;
}

float Atm::get_balance(){
	return balance;
}

Atm* Atm::valueOf(Atm& a)
{
	Atm* aux=new Atm(a.num_of_Bills);
	return aux;
}




#include<iostream>

using std::cout;
using std::cin;


float Atm::extract(float sum)
{
	int nob[6]{};
	int val[6]{};
	for (auto i : this->num_of_Bills)
	{
		int multiplyer = 0;
		switch (i.first)
		{
		case Bill::bill::Lei_5:
			nob[0] = i.second;
			val[0] = 5;
			break;
		case Bill::bill::Lei_10:
			nob[1] = i.second;
			val[1] = 10;
			break;
		case Bill::bill::Lei_50:
			nob[2] = i.second;
			val[2] = 50;
			break;
		case Bill::bill::Lei_100:
			nob[3] = i.second;
			val[3] = 100;
			break;
		case Bill::bill::Lei_200:
			nob[4] = i.second;
			val[4] = 200;
			break;
		case Bill::bill::Lei_500:
			nob[5] = i.second;
			val[5] = 500;
			break;
		default:
			break;
		}
	}

	int i = 5;
	float sum_aux = sum;
	while (sum)
	{
		if (nob[i] == 0 || sum < val[i]) i--;
		else if (sum >= val[i])
		{
			nob[i]--;
			sum -= val[i];
		}
		if (i < 0) break;
	}
	cout << "\nse poate extrage suma de " << sum_aux - sum << "\n";
	cout << "continuam?1/0";
	bool raspuns(0);
	cin >> raspuns;
	if (!raspuns) return 0;

	this->num_of_Bills[Bill::bill::Lei_5] = nob[0];
	this->num_of_Bills[Bill::bill::Lei_10] = nob[1];
	this->num_of_Bills[Bill::bill::Lei_50] = nob[2];
	this->num_of_Bills[Bill::bill::Lei_100] = nob[3];
	this->num_of_Bills[Bill::bill::Lei_200] = nob[4];
	this->num_of_Bills[Bill::bill::Lei_500] = nob[5];

	recalculate_ballance();
//	cout << "tranzactie efectuata cu succes!\n";
	return sum_aux - sum;

}