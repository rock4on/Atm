#pragma once

class Bill
{
public:
	static enum class bill
	{
		Lei_5,
		Lei_10,
		Lei_50,
		Lei_100,
		Lei_200,
		Lei_500
	};
	static float GetValueOf(bill);
};