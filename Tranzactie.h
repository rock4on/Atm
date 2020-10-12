#pragma once
#include "Atm.h"
#include "Card.h"
#include "Bill.h"
class ModelTranzactie {
public:
	ModelTranzactie(Atm&a,Card&c):atm(&a),card(&c){}
	Atm* getAtm() { return atm; }
	Card* getCard() { return card; }
private:
	Atm* atm;
	Card* card;
};


#include <iostream>
using std::cout;
using std::cin;
class ViewTranzactie
{
public:
	ViewTranzactie() = default;


	void adauga_bani(Card* c, Bill::bill bill,Atm*a, int quantity)
	{
		cout << "\n Introduceti pin-ul:\n";
		int pi = 0;
		cin >> pi;
		if (pi != c->GetPin()) return;
		c->SetSold(c->GetSold() + Bill::GetValueOf(bill) * quantity);
		a->add_Bill(bill, quantity);
		cout << "tranzactie efectuata cu succes";
		
	}

	void scoate_bani(Card* c,Atm* a,int suma)
	{
		cout << "\n Introduceti pin-ul:\n";
		int pi=0;
		cin >> pi;
		if (pi != c->GetPin()) return;
		if (suma > c->GetSold()) { cout << "nu sunt suficenti bani pe card"; return; }
		c->SetSold(c->GetSold()-a->extract(suma));
		cout << "tranzactie efectuata cu succes";

	}




};



class Tranzactie {
public:
	Tranzactie(ModelTranzactie* m, ViewTranzactie* v) :model(m), view(v) {};
	//folosita pt exterior hard-copy
	Atm* Get_Atm()
	{
		return Atm::valueOf(*model->getAtm());
	}
	Card* Get_Card()
	{
		return Card::valueOf(*model->getCard());
	}

	void scoate_bani(int s)
	{
		view->scoate_bani(model->getCard(), model->getAtm(), s);
	
	}

	void adauga_bani(Bill::bill b,int q)
	{
		view->adauga_bani(model->getCard(), b, model->getAtm(), q);

	}


private:
	ModelTranzactie* model;
	ViewTranzactie* view;
};