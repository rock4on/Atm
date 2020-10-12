#include "Bill.h"



 float Bill::GetValueOf(Bill::bill bi)
{
	float value = 0;
	switch (bi)
	{
	case Bill::bill::Lei_5:
		value = 5;
		break;
	case Bill::bill::Lei_10:
		value = 10;
		break;
	case Bill::bill::Lei_50:
		value = 50;
		break;
	case Bill::bill::Lei_100:
		value = 100;
		break;
	case Bill::bill::Lei_200:
		value = 200;
		break;
	case Bill::bill::Lei_500:
		value = 500;
		break;
	default:
		break;
	}
	return value;
}