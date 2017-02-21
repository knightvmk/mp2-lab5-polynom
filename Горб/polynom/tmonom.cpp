#include "tmonom.h"

TMonom::TMonom()
{
	consta = 1;
	index = 0;
};

TMonom::TMonom(int _c, int _i)
{
	consta = _c;
	if (_i<0 || _i>OVER_IND) throw ("Overdrive: Index is out of range.");
	else index = _i;
}
TMonom TMonom::GetCopy() const
{
	return *this;
};

int TMonom::GetConsta() const
{
	return consta;
};

int TMonom::GetIndex() const
{
	return index;
};

void TMonom::SetConsta(const int _c)
{
	consta = _c;
}
void TMonom::SetIndex(const int _i)
{
	if (_i<0 || _i>OVER_IND) throw ("Overdrive: Index is out of range.");
	else index = _i;
};

TMonom& TMonom::operator=(const TMonom & _enter)
{
	consta = _enter.consta;
	index = _enter.index;
	return *this;
};

TMonom& TMonom::operator+(const TMonom & _enter)
{
	if (index != _enter.index)
	{
		throw ("Forbidden to add different degree monomials!");
	}
	else
	{
		consta += _enter.consta;
	}
	return *this;
};

TMonom& TMonom::operator-(const TMonom & _enter)
{
	if (index != _enter.index)
	{
		throw ("Forbidden to substract different degree monomials!");
	}
	else
	{
		consta -= _enter.consta;
	}
	return *this;
}
TMonom& TMonom::operator*(const TMonom & _enter)
{
	consta *= _enter.consta;
	index += _enter.index;
	return *this;
};

TMonom& TMonom::operator/(const TMonom & _enter)
{
	if (index -= _enter.index < 0)
	{
		throw ("It's to hard today");
		
	}
	else
	{
		consta /= _enter.consta;
		index -= _enter.index;
	}
	return *this;
};

bool TMonom::operator==(const TMonom & _enter) const
{
	return (consta == _enter.consta && index == _enter.index);
};
