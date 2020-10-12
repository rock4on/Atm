#include "Card.h" 



Card::Card(const Card& c):pin(c.pin),sold(c.sold)
{}


float const Card::GetSold()
{
	return sold;
}

void Card::SetSold(float s)
{
	sold = s;
}
Card* Card::valueOf(Card& c)
{
	Card* ca=new Card(c.pin,c.sold);
	return ca;
}