#pragma once

class Card
{
public:
	float const GetSold();

	Card(int p=0,float s=0) :pin(p),sold(s) {};
	
	static Card* valueOf(Card& aux);
    void SetSold(float sol);
	int const GetPin() 
	{
		return pin;
	};

private:
	Card(const Card& c);
	
	
	int const pin;
	float sold;

};

