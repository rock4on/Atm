#include <iostream>
#include <String>
#include "Bill.h"
#include "Atm.h"
#include"Card.h"
#include "Tranzactie.h"

using std::cout;
using std::cin;
using std::string;

int main()
{
	Atm a;
	Card c(1234, 0);
	//a.add_Bill(Bill::bill::Lei_200, 1)->add_Bill(Bill::bill::Lei_100,1);
	ModelTranzactie mod(a, c);
	ViewTranzactie v;
	Tranzactie t(&mod, &v);
	t.adauga_bani(Bill::bill::Lei_200, 1);
//	t.scoate_bani(200);


	cout << "\n" << t.Get_Atm()->get_balance();
}