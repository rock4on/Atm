#pragma once
#include <map>
#include "Bill.h"
using std::map;
class Atm
{
public:

	Atm() = default;
	Atm(map<Bill::bill, int> bills) : num_of_Bills(bills) { recalculate_ballance(); };
	int recalculate_ballance();
	Atm* add_Bill(Bill::bill b, int quantity);
	float get_balance();
	float extract(float sum);

	static Atm* valueOf(Atm& v);


private:
	//0-10 l
	Atm(const Atm& at) = default;
	map<Bill::bill, int> num_of_Bills
	{
		{ Bill::bill::Lei_10,0 },
		{ Bill::bill::Lei_100,0 },
		{ Bill::bill::Lei_200,0 },
		{ Bill::bill::Lei_500,0 },
		{ Bill::bill::Lei_5,0 },
		{ Bill::bill::Lei_50,0 },
	};
	float balance=0;


};


