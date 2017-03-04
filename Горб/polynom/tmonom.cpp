#include "tmonom.h"

TMonom::TMonom()
{
	consta = 1;
	index = -1;
};

TMonom::TMonom(int _c, int _i)
{
	consta = _c;
	if (_i<-1 || _i>OVER_IND) throw ("Overdrive: Index is out of range.");
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
	if (_i<-1 || _i>OVER_IND) throw ("Overdrive: Index is out of range.");
	else index = _i;
};

TMonom& TMonom::operator=(const TMonom &_enter)
{
	consta = _enter.consta;
	index = _enter.index;
	return *this;
};

TMonom TMonom::operator+(const TMonom &_enter)
{
	if (index == -1 || _enter.index == -1) return *this;
	if (index != _enter.index)
	{
		throw ("Forbidden to add different degree monomials!");
		return *this;
	}
	else
	{
		TMonom res;
		res.consta = consta + _enter.consta;
		res.index = index;
		return res;
	}
};

TMonom TMonom::operator-(const TMonom &_enter)
{
	if (index == -1 || _enter.index == -1) return *this;
	if (index != _enter.index)
	{
		throw ("Forbidden to substract different degree monomials!");
		return *this;
	}
	else
	{
		TMonom res;
		res.consta = consta-_enter.consta;
		res.index = index;
		return res;
	}
}
TMonom TMonom::operator*(const TMonom &_enter)
{
	if (index == -1 || _enter.index == -1) return *this;
	TMonom res;
	res.consta = consta * _enter.consta;
	int a1, b1, c1, a2, b2, c2;
	//first
	a1 = (int)(index / 100);
	b1 = (int)((index - a1 * 100) / 10);
	c1 = index - a1 - b1;
	//second
	a2 = (int)(_enter.index / 100);
	b2 = (int)((_enter.index - a2 * 100) / 10);
	c2 = _enter.index - a2 - b2;
	//result:
	res.index = (a1 + a2) * 100 + (b1 + b2) * 10 + (c1 + c2);
	if (res.index > 999)
		throw("Achtung, Attention, Alert, Увага! Overdrive!!!"); //halt() exit() system down!
	return res;
};

TMonom TMonom::operator/(const TMonom &_enter)
{
	if (index == -1 || _enter.index == -1) return *this;
	if (index - _enter.index < 0)
	{
		throw ("It's to hard today");
		return *this;
	}
	else
	{
		TMonom res;
		res.consta = consta / _enter.consta;
		int a1, b1, c1,a2,b2,c2;
		//first
		a1 = (int)(index / 100);
		b1 = (int)((index - a1*100)/10);
		c1 = index - a1 - b1;
		//second
		a2 = (int)(_enter.index / 100);
		b2 = (int)((_enter.index - a2 * 100) / 10);
		c2 = _enter.index - a2 - b2;
		if (a1 - a2 <0) throw("Беда1");
		if (b1 - b2 <0) throw("Беда2");
		if (c1 - c2 <0) throw("Беда3");
		res.index=(a1 - a2)*100+(b1-b2)*10+(c1-c2);
		res.index = index - _enter.index;
		return res;
	}
};

bool TMonom::operator==(const TMonom &_enter) const
{
	return (consta == _enter.consta && index == _enter.index);
}
bool TMonom::operator!=(const TMonom &_enter) const
{
	return !(*this == _enter);
};
